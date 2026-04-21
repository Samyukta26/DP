import pandas as pd

data = pd.read_csv("C:\Users\Samyukta\Desktop\CODES\data.csv")

X = data.iloc[:, :-1]
y = data.iloc[:, -1]

hypothesis = ['0'] * len(X.columns)

for i in range(len(X)):
    if y[i] == "Yes":
        for j in range(len(X.columns)):
            if hypothesis[j] == '0':
                hypothesis[j] = X.iloc[i, j]
            elif hypothesis[j] != X.iloc[i, j]:
                hypothesis[j] = '?'

print("Final Hypothesis:", hypothesis)