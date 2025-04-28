import pandas as pd
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt

# Step 1: Load the CSV
data = pd.read_csv("D:\\iris.csv")

# Step 2: Select only numeric columns for clustering
X = data[['sepal.length', 'sepal.width', 'petal.length', 'petal.width']]

# Step 3: Create KMeans model
kmeans = KMeans(n_clusters=3, random_state=42)
kmeans.fit(X)

# Step 4: Get cluster labels
labels = kmeans.labels_

# Step 5: Add cluster labels to the original data
data['Cluster'] = labels

# Step 6: Plot clusters
plt.scatter(X['sepal.length'], X['sepal.width'], c=labels, cmap='viridis',label="Data points")
plt.scatter(kmeans.cluster_centers_[:, 0], kmeans.cluster_centers_[:, 1], color='red', marker='X', s=200, label='Centers')
plt.xlabel('Sepal Length')
plt.ylabel('Sepal Width')
plt.title('KMeans Clustering')
plt.legend()
plt.grid(True)
plt.show()