#!/usr/bin/env python3

from linear_reg import LinearRegressionModel

def main():
   model = LinearRegressionModel()
   x = list(range(0, 25))
   y = list(map(lambda value: value * 10, x))
   model.fit(x, y)
   print(model)
   model.predict(21)
   model.score()

if __name__ == "__main__":
    main()
