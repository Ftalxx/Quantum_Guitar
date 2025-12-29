import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("dataset_raw_60s.csv")

# Compute mean + std for each column
stats = df.describe().loc[["mean","std"]]

print(stats)

stats.to_csv("baseline_sensor_statistics.csv")

# Plot drift over time
df[["bicep_ax","bicep_ay","bicep_az"]].plot(figsize=(12,6))
plt.title("Bicep IMU Drift Over Time")
plt.show()

df[["hand_ax","hand_ay","hand_az"]].plot(figsize=(12,6))
plt.title("Hand IMU Drift Over Time")
plt.show()
