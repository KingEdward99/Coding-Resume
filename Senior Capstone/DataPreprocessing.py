import pandas as pd
import csv


def preprocess_data():
    df = pd.read_csv('metric_log.xlsx')
    # Extract features for anomaly detection (e.g., CPU usage, memory usage)
    features = df[["cpu_usage", "memory_usage", "bytes_sent", "bytes_received"]]
    return features