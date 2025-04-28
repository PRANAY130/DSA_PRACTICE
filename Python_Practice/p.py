import numpy as np
import matplotlib.pyplot as plt
import seaborn as sb
import pandas as pd

data=pd.read_csv("D:\\iris.csv")

plt.plot(data["variety"])
plt.show()

plt.hist(data["variety"])
plt.show()


iris_Setosa=data.loc[data["variety"]=="Setosa"]
iris_Virginica=data.loc[data["variety"]=="Virginica"]
iris_Versicolor=data.loc[data["variety"]=="Versicolor"]

print("Mean of setosa",np.mean(iris_Setosa["sepal.length"]))