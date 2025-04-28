import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sb 

iris = pd.read_csv("D:\\iris.csv")
print(iris.shape) 
print(iris.columns)
print(iris['species'].value_counts()) 
print(iris.info())

# First plot
plt.plot(iris["species"])
plt.xlabel("No. of data points")
plt.show()
# Second plot
plt.hist(iris["species"],color="green")
plt.show() 

print(iris.describe())

sb.set_style('whitegrid')
sb.scatterplot(data=iris, x='sepal_length', y='sepal_width', hue='species')
plt.plot() 

sb.set_style('whitegrid')
sb.pairplot(iris,hue='species',size=3)
plt.show() 

iris_setosa = iris.loc[iris['variety']=='Setosa']
iris_versicolor = iris.loc[iris['variety']=='Versicolor']
iris_virginica = iris.loc[iris['variety']=='Virginica'] 

# Means of the petal length
print("Means")
print("setosa",np.mean(iris_setosa["petal.length"]))
print("versicolor",np.mean(iris_versicolor["petal.length"]))
print("virginica",np.mean(iris_virginica["petal.length"]))
# standard-daviation
print("standard-daviation")
print("setosa :",np.std(iris_setosa["petal.length"]))
print("versicolor :",np.std(iris_versicolor["petal.length"]))
print("virginica :",np.std(iris_virginica["petal.length"]))
# median
print("median")
print("setosa :",np.median(iris_setosa["petal.length"]))
print("versicolor :",np.median (iris_versicolor["petal.length"]))
print("virginica :",np.median (iris_virginica["petal.length"])) 