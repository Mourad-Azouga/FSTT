import numpy as np
import matplotlib.pyplot as plt
def f1(x):
    return np.exp(-x) * np.cos(2*np.pi*x)
def f2(y):
    return np.cos(3*np.pi*y)

x = np.arange(0.0, 5.0, .1)
y = np.arange(0.0, 5.0, .02)

plt.plot(x, f1(x), 'b',y, f2(y), 'r')
plt.min()
plt.show()