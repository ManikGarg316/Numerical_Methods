
import matplotlib.pyplot as plt
import numpy as np

def func(x):
    return x*x

f = open("./output.txt")
lines = f.readlines()
vals = lines[0].split(',')
x1 = [float(vals[i].strip(' \n')) for i in range(len(vals))]
y1 = [0 for i in range(len(vals))]

x2 = [i/10 for i in range(0,1001)]
y2 = [func(x2[i]) for i in range(len(x2))]


xpoints = np.array(x1)
ypoints = np.array(y1)


Xpoints = np.array(x2)
Ypoints = np.array(y2)
plt.plot(xpoints, ypoints, 'o')
plt.plot(Xpoints, Ypoints)
plt.xlabel("X")
plt.ylabel("Y")
  
# saving the file.Make sure you 
# use savefig() before show().
plt.savefig("squares.png")

# plt.show()