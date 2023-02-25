#!/usr/bin/env python3

from linear_reg import LinearRegressionModel

def main():
   model = LinearRegressionModel()
   x = list(range(0, 25))
   y = list(map(lambda value: value * 10, x))
   model.train(x, y)
   print(model.predict(21))

if __name__ == "__main__":
    main()
