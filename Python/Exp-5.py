import pandas as pd
import numpy as np
obj = pd.Series([1,2,3,4,5,6,7,8,9,'a'])
while True:
    print("1. Slicing of series without steps.")
    print("2. Slicing of series with step.")
    print("3. Exit")
    ch=int(input("Enter your choice: "))
    if ch == 1:
        start = int(input("Enter the beginning of the slice."))
        stop = int(input("Enter the end of the slice."))
        a = obj[start:stop+1]
        print("Slicing from", start, "index to", stop, "without step: ")
        print(a)
