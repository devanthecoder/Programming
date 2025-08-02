import pandas as pd
import numpy as np
Marks = {'Name':['Ram','Alex','Zara','Keshav','Madhav','Riya'],'RNo':[1,2,3,4,5,6],'Marks':[56,50,78,99,89,37]}
Results = pd.DataFrame(Marks)
print(Results)
m=Results.loc[:,'Marks']
print(m[m>70 & m<80])
