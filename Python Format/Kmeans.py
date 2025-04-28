from sklearn.datasets import load_iris
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt

iris=load_iris()
data=iris.data
print(data)
target=iris.target
print(target)

kmeans_model=KMeans(n_clusters=3,random_state=1).fit(data)
labels=kmeans_model.labels_
clusters_kmeans=kmeans_model.cluster_centers_

def plotting(data,labels,clusters):
    plt.scatter(data[:,0],data[:,1],c=labels,cmap="viridis",label="Data Points")
    plt.scatter(clusters[:,0],clusters[:,1],s=200,marker="X",color="red",label="Cluster points")
    plt.xlabel("Sepal Width")
    plt.ylabel("Seapl Length")
    plt.grid(True)
    plt.legend()
    plt.show()
    
plotting(data,labels,clusters_kmeans)