import pandas as pd
Sym = pd.Series(["H","He","Li","Be"],index = ["Hydrogen","Helium","Lithium","Beryllium"])
AtoNum = pd.Series([1,2,3,4],index = ["Hydrogen","Helium","Lithium","Beryllium"])
Dict = {"Symbol":Sym,"Atomic Number":AtoNum}
DF = pd.DataFrame(Dict)
print(DF)
