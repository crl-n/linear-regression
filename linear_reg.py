from ctypes import CDLL
from typing import List, TypeVar

lib_linear_reg = CDLL("lib_linear_reg.so")

class LinearRegressionModel:
    T = TypeVar("T")
    
    def train(self, x_values: List[T], y_values: List[T]) -> None:
        # lib_linear_reg.train(x_values, y_values)
        print(x_values)
        print(y_values)
        pass

    def predict(self, val: T) -> T: 
        prediction = lib_linear_reg.predict(val)
        print(f"Prediction: {prediction}")
        return prediction
