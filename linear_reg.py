from ctypes import CDLL, POINTER, c_int, c_float, c_void_p, Structure
from typing import List, Union

class C_LinearModel(Structure):
    _fields_ = [('x_vals', c_void_p),
                ('y_vals', c_void_p),
                ('w', c_float),
                ('b', c_float)]

class C_PerformanceResult(Structure):
    _fields_ = [('r2_score', c_float),
                ('mean_squared_error', c_float),
                ('mean_absolute_error', c_float),
                ('mean_error', c_float)]

# Return and argument type definitions for functions of the C library
lib_linear_reg = CDLL("lib_linear_reg.so")
lib_linear_reg.py_fit.restype = POINTER(C_LinearModel)
lib_linear_reg.py_score.restype = POINTER(C_PerformanceResult)
lib_linear_reg.py_predict.argtypes = (c_float,)
lib_linear_reg.py_predict.restype = c_float
lib_linear_reg.py_memfree.argtypes = (c_void_p,)
lib_linear_reg.py_memfree.restype = None

# Type union for input to train() and predict()
T = Union[int, float]

class LinearRegressionModel:
    w: T = 0.0
    b: T = 0.0
    x_values: List[T] = []
    y_values: List[T] = []
    
    # Take in either 2D or 1D x_values
    def fit(self, x_values: List[T], y_values: List[T]) -> None:
        if not all(isinstance(val, T) for val in x_values) or not all(isinstance(val, T) for val in y_values):
            raise TypeError("LinearRegressionModel.fit() requires arguments of type List[int | float]")
        # Add check for if x is 2D or 1D
        self.x_values = x_values
        self.y_values = y_values
        XArray = c_int * len(x_values)
        YArray = c_int * len(y_values)
        c_model = lib_linear_reg.py_fit(XArray(*x_values), len(x_values), YArray(*y_values), len(y_values))
        self.w = c_model.contents.w
        self.b = c_model.contents.b
        lib_linear_reg.py_memfree(c_model)

    def score(self) -> None:
        XArray = c_int * len(self.x_values)
        YArray = c_int * len(self.y_values)
        c_performance_results = lib_linear_reg.py_score(XArray(*self.x_values), len(self.x_values), YArray(*self.y_values), len(self.y_values))
        print(f"R2 Score: {c_performance_results.contents.r2_score}\n"
              f"Mean Squared Error (MSE): {c_performance_results.contents.mean_squared_error}\n"
              f"Mean Absolute Error (MAE): {c_performance_results.contents.mean_absolute_error}\n"
              f"Mean Error (ME): {c_performance_results.contents.mean_error}")
        lib_linear_reg.py_memfree(c_performance_results)

    def predict(self, val: T) -> float:
        if not isinstance(val, T):
            raise TypeError("LinearRegressionModel.predict() requires argument of type int | float")
        prediction = lib_linear_reg.predict(val)
        print(f"Prediction (x = {val}): y = {prediction}")
        return prediction

    def __str__(self):
        return f"Slope (w): {self.w}\nIntercept (b): {self.b}"

