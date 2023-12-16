import numpy as np
import matplotlib.pyplot as plt

data = {
    'a' : np.arange(0.,50),
    'c' : np.random.randint(0,50,50),
    'd' : np.random.randn(50) *5
}
data['b'] = data['a'] + 10 * np.random.randn(50)
data['d'] = (np.abs(data['d']) * 100)
plt.scatter('a', 'b', s = 'd', c = 'c', data = data)
plt.xlabel('ENTREE a')
plt.ylabel('ENTREE b')
plt.show()