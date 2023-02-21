from ctypes import CDLL, c_int
from typing import List, TypeVar

lib_linear_reg = CDLL("lib_linear_reg.so")

class LinearRegressionModel:
    T = TypeVar("T")
    
    def train(self, x_values: List[T], y_values: List[T]) -> None:
        XArray = c_int * len(x_values)
        YArray = c_int * len(y_values)
        lib_linear_reg.train(XArray(*x_values), len(x_values), YArray(*y_values), len(y_values))
        print(x_values)
        print(y_values)
        pass

    def predict(self, val: T) -> T: 
        prediction = lib_linear_reg.predict(val)
        print(f"Prediction: {prediction}")
        return prediction
