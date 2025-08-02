import matplotlib.pyplot as plt
import numpy as np
x = ['ENGLISH','ACCOUNTS','BST','ECONOMICS','IP']
y = [80,100,60,80,90]
plt.bar(x,y)
plt.title('SUBJECT RESULT ANALYSIS')
plt.xlabel('SUBJECT')
plt.ylabel('PERCENTAGE')
plt.yticks(np.arange(0,101,20))
plt.show()
plt.savefig('Result.png')
