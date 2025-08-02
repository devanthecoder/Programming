import matplotlib.pyplot as plt
import numpy as np
x = np.arange(10,100,2)
y = np.arange(10,55)
# i) with x and no other args
plt.hist(x, orientation = 'horizontal', histtype = 'step')
plt.show()
plt.savefig("hist.png")
