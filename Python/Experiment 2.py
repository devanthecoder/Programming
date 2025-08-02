import matplotlib.pyplot as plt
def intercept(a,b):
    x = [0,a]
    y = [b,0]
    plt.plot(x,y, marker = "8", linestyle = "dashdot", linewidth = 4, markersize = 10)
    plt.xlabel("X-Axis")
    plt.ylabel("Y-Axis")
    plt.title("Intercept Form of a Line")
    plt.grid(True)
    print("The graph of the the line x /",a," + y /",b," = 1 is:")
    return plt.show()
