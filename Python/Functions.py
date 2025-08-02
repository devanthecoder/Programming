import matplotlib.pyplot as plt
import math as mt
import numpy as np
plt.plot([-20,20],[0,0],color='black')
plt.plot([0,0],[-1,1],color='black')
x = list(np.arange(-20,20.01,0.01))
y = []
for i in range(0,4002):
    y.insert(i,(mt.sin(x[i]))/x[i])
plt.plot(x,y,color='green',linewidth = 5)
plt.show()