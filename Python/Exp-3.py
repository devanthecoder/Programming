import pandas as pd
import numpy as np
Marks_list = {'Name':['Ram','Keshav','Zara'],'RNo':[1,2,3],'Marks':[56,87,98]}
Result = pd.DataFrame(Marks_list)
print(Result.loc[:, 'Marks'])
