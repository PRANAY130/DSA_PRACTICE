import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from sklearn.cluster import KMeans 

iris=pd.read_csv("D:\\iris.csv")

data=iris[["sepal.length","sepal.width","petal.length","petal.width"]]
print(data)

kmeans_model=KMeans(n_clusters=3,random_state=42)
kmeans_model.fit(data)

labels=kmeans_model.labels_
clusters_kmeans=kmeans_model.cluster_centers_

# data['Cluster']=labels

plt.scatter(data["sepal.width"],data["sepal.length"],c=labels,cmap="viridis",label="Data points")
plt.scatter(clusters_kmeans[:,1],clusters_kmeans[:,0],s=200,marker="X",color="red",label="Cluster point")
plt.xlabel("Sepal Width")
plt.ylabel("Sepal Length")
plt.legend()
plt.grid(True)
plt.show()
