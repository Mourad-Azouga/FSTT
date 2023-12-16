import numpy as np
import matplotlib.pyplot as plt
donne = ['Classe1', 'Classe2','Class3']
valeurs = [1,10,100]
plt.figure(figsize = (9,3))
plt.subplot(131)
plt.bar(donne, valeurs, width = .5)
plt.subplot(132)
plt.scatter(donne, valeurs,c = 'purple', marker = 6)
plt.subplot(133)
plt.plot(donne, valeurs, 'g^')
plt.show()