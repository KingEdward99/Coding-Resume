# Import Libraries
import numpy as np
import pandas as pd
from sklearn.ensemble import IsolationForest
import matplotlib.pyplot as plt

# Generate or Load Data
rng = np.random.RandomState(42)
X_normal = 0.3 * rng.randn(100, 2)
X_outliers = rng.uniform(low=-4, high=4, size=(20, 2))

# Combine normal data and outliers
X = np.vstack([X_normal, X_outliers])

# Convert to DataFrame
df = pd.DataFrame(X, columns=["Feature 1", "Feature 2"])

# Train the Isolation Forest Model
iso_forest = IsolationForest(contamination=0.15, random_state=42)
iso_forest.fit(df)

# Predict anomalies (-1: anomaly, 1: normal)
df['anomaly'] = iso_forest.predict(df)

# Visualize the Results
normal_points = df[df['anomaly'] == 1]
anomaly_points = df[df['anomaly'] == -1]

plt.scatter(normal_points['Feature 1'], normal_points['Feature 2'], color='blue', label='Normal')
plt.scatter(anomaly_points['Feature 1'], anomaly_points['Feature 2'], color='red', label='Anomaly')
plt.title('Anomaly Detection with Isolation Forest')
plt.xlabel('Feature 1')
plt.ylabel('Feature 2')
plt.legend()
plt.show()