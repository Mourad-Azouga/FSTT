import matplotlib.pyplot as plt
import numpy as np


y = np.random.normal(loc=0.5, scale=0.4, size=1000)
y = y[(y > 0) & (y < 1)]
y.sort()
x = np.arange(len(y))

plt.figure()
# linear
plt.subplot(221)
plt.plot(x, y)
plt.title('linear')

# log
plt.subplot(222)
plt.plot(x, y)
plt.title('log')

# symmetric log
plt.subplot(223)
plt.plot(x, y - y.mean())
plt.yscale('symlog', linthresh=0.01)
plt.title('symlog')

# logit
plt.subplot(224)
plt.plot(x, y)
plt.title('logit')
plt.show()