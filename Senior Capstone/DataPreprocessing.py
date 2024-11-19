import pandas as pd
import os

def process_and_save_csv(file_path, output_csv_path):
    # Check if the input file exists
    if not os.path.exists(file_path):
        print(f"File not found: {file_path}")
        return None

    # Load the Excel file with the 'openpyxl' engine
    df = pd.read_csv(file_path)

    df.to_csv(output_csv_path, index=False)
    print(f"File converted to CSV and saved at: {output_csv_path}")



# Example of how to call the function
file_path = "/Users/eddyk99/Documents/GitHub/Coding-Resume/Senior Capstone/metrics_log.csv"
output_csv_path = '/Users/eddyk99/Documents/GitHub/Coding-Resume/Senior Capstone/device_metrics.csv'

process_and_save_csv(file_path, output_csv_path)
