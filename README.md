# Linear Regression From Scratch
A simple linear regression library written in C with a Python API.

```
___________________________________________________________________________/\\\________        
 __________________________________________________________________________\/\\\________       
  ____/\\\__/\\\___________________________________________________/\\\_____\/\\\________      
   ___\//\\\/\\\___/\\\\\\\\\\__/\\____/\\___/\\__/\\\____/\\\_____\/\\\_____\/\\\________     
    ____\//\\\\\___\//////////__\/\\\__/\\\\_/\\\_\///\\\/\\\/___/\\\\\\\\\\\_\/\\\\\\\\\__    
     _____\//\\\_____/\\\\\\\\\\_\//\\\/\\\\\/\\\____\///\\\/____\/////\\\///__\/\\\////\\\_   
      __/\\_/\\\_____\//////////___\//\\\\\/\\\\\______/\\\/\\\_______\/\\\_____\/\\\__\/\\\_  
       _\//\\\\/_____________________\//\\\\//\\\_____/\\\/\///\\\_____\///______\/\\\\\\\\\__ 
        __\////________________________\///__\///_____\///____\///________________\/////////___
```

## Linear Regression
Linear regression is a method used to estimate a linear function (y = wx + b) that best fits a given dataset. This is done using a technique called **gradient descent**. Gradient descent is a more general optimization technique that is used also in other forms of machine learning. Simply put, gradient descent is an efficient way to find the best values for the w and b in y = wx + b.

For now the library is capable of univariate linear regression only, meaning the dataset should only consist of a pair of variables (x and y).

## Using the Python API
To use the Python API simply import LinearRegressionModel from lib_linear_reg.py. Use the train() method to train the model, giving it two lists of integers (one for each variable). Once the model has been trained use the predict() method to create a prediction.

Check out main.py for an example of how to use the Python API.

## Planned Features
- Precision
- Benchmarking
- Multivariate linear regression
- Plotting
- Parallelized gradient descent
