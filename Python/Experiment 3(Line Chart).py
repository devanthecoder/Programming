import matplotlib.pyplot as plt
import pandas as pd
DF = pd.read_csv(r"C:\Users\HP\Desktop\Devan\Python\Sales.csv")
DF.plot(kind = 'line', color = ['b','k','r'], marker = "H", markersize = "15", linestyle = "dotted",linewidth = "6")
plt.xticks = ("Mon","Tue","Wed","Thur","Fri","Sat","Sun")
plt.title("Sales Report")
plt.xlabel("Days")
plt.ylabel("Sales in Rs.")
plt.show()
print(DF)
