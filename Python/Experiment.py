import numpy as np
import pandas as pd
np1 = np.arange(1,13)
DF = pd.DataFrame(columns = [1,2,3,4,5,6,7,8,9,10,11,12], index = [1,2,3,4,5,6,7,8,9,10,11,12])
for n in range(1,13):
    np2 = np1*n
    DF[n] = np2
    n = n+1
print(DF)
