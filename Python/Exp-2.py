import pandas as pd
Exam = {'RNo':[1, 2, 3], 'Class_Section':['D', 'E', 'F'], 'Marks':[98, 89, 68]}
Result = pd.DataFrame(Exam, index = ['Ram','Rohan','Ravinda'])
print("The required dataframe is:")
print(Result)
print("The rows of the given dataframe are:",Result.index.values)
print("The columns of the given dataframe are:",Result.columns.values)
print("The dimensions of the dataframe are:",Result.shape)
print("The columns and their corresponding datatypes are given as:")
print(Result.dtypes)
