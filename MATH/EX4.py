"""import numpy as np
import matplotlib.pyplot as plt

def f1(x):
    return np.exp(-x) * np.cos(2*np.pi*x)
def f2(y):
    return np.cos(3*np.pi*y)

x = np.arange(0.0, 5.0, .1)
y = np.arange(0.0, 5.0, .02)

plt.plot(x, f1(x), 'b',y, f2(y), 'r')
print(min)
plt.show()

"""
import numpy as np
import matplotlib.pyplot as plt

def f1(x):
    return np.exp(-x) * np.cos(2*np.pi*x)
def f2(y):
    return np.cos(3*np.pi*y)

x = np.arange(0.0, 5.0, .1)
y = np.arange(0.0, 5.0, .02)

plt.figure()
plt.subplot(211)
plt.plot(x, f1(x), 'b')
plt.annotate('Min', xy = (.5, min(f1(x))), xytext = (.9,-.5), arrowprops = dict(facecolor = 'b', shrink = .05))
plt.subplot(212)
plt.plot(y, f2(y), 'r')

plt.show()