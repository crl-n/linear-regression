from ctypes import CDLL, POINTER, c_int, c_float, Structure
from typing import List, Union

class C_LinearModel(Structure):
    # Add missing fields? Or make py_fit() return just w and b and reuse the x_values and y_values
    _fields_ = [('w', c_float),
                ('b', c_float)]

lib_linear_reg = CDLL("lib_linear_reg.so")
lib_linear_reg.fit.restype = POINTER(C_LinearModel)
lib_linear_reg.predict.restype = c_float

# Make this into dataclass?
class LinearRegressionModel:
    T = Union[int, float]
    
    def train(self, x_values: List[T], y_values: List[T]) -> None:
        XArray = c_int * len(x_values)
        YArray = c_int * len(y_values)
        model = lib_linear_reg.fit(XArray(*x_values), len(x_values), YArray(*y_values), len(y_values))
        print(x_values)
        print(y_values)
        print("result in python -> w:", model.contents.w, "b:", model.contents.b)
        # Free result
        # Convert c model to LinearRegressionModel
        # Return self?
        pass

    def predict(self, val: T) -> float:
        prediction = lib_linear_reg.predict(val)
        print(f"Prediction: {prediction}")
        return prediction
