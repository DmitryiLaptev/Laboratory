import pandas as pd
import numpy as np
import csv

#filepath = r"C:\Users\acer\Downloads\report.csv"
#df = pd.read_csv(filepath)
#print(df)

with open(r"C:\Users\acer\Downloads\report.csv") as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')

    df = pd.DataFrame([csv_reader], index=None)
    df.head()

for val in list(df[1]):
    print(val)