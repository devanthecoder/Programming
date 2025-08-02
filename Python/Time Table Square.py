import pandas as pd
import numpy as np
l = int(input("Enter horizontal dimension of the Time Table: "))
b = int(input("Enter vertical dimension of the Time Table: "))
DF = pd.DataFrame(index = np.arange(1,b+1), columns = np.arange(1, l+1))
ar1 = np.arange(1, l+1)
for i in range(1, b+1):
    ari = ar1*i
    DF.loc[i] = ari
    i = i+1 
print(DF)
