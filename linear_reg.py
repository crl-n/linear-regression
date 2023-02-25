from ctypes import CDLL, POINTER, c_int, c_float, Structure
from typing import List, TypeVar


class GradientDescentResult(Structure):
    _fields_ = [('w', c_float),
                ('b', c_float)]

lib_linear_reg = CDLL("lib_linear_reg.so")
lib_linear_reg.train.restype = POINTER(GradientDescentResult)

class LinearRegressionModel:
    T = TypeVar("T")
    
    def train(self, x_values: List[T], y_values: List[T]) -> None:
        XArray = c_int * len(x_values)
        YArray = c_int * len(y_values)
        result = lib_linear_reg.train(XArray(*x_values), len(x_values), YArray(*y_values), len(y_values))
        print(x_values)
        print(y_values)
        print("result in python -> w:", result.contents.w, "b:", result.contents.b)
        pass

    def predict(self, val: T) -> T: 
        prediction = lib_linear_reg.predict(val)
        print(f"Prediction: {prediction}")
        return prediction
