liste = [1, 9, 4, 5, 91, 6, 45, 2, 3, 41]
print(liste)

def trier_liste(liste):
    for i in range(len(liste)):
        for j in range(len(liste) - 1):
            if liste[j] > liste[j + 1]:
                liste[j], liste[j + 1] = liste[j + 1], liste[j]

trier_liste(liste)
print(liste)