#!/usr/bin/env python3

from linear_reg import LinearRegressionModel

def main():
   model = LinearRegressionModel()
   model.train([1, 2, 3], [10, 20, 30])
   print(model.predict(21))

if __name__ == "__main__":
    main()
