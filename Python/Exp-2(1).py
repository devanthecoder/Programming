import pandas as pd
import numpy as np
d = {'pname':['soap','paste','brush','shampoo'],'pid':[1,2,3,4],'pmfg':['HUL','Godrej','Senodyne','HUL']}
DF1 = pd.DataFrame(d)
a = DF1.iseritem()
for i in a:
    print(i[0],'column data type=',DF1[i[0]].dtype)

