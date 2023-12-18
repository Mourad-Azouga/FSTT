import time
# méthode de slicing
debut=time.time()
chaine1=input("Entrer votre texte : ")
print(chaine1[::-1])
fin=time.time()
print("Temps d'execution de la 1ère méthode : ", fin-debut)

# méthode en utilisant reversed()
debut=time.time()
chaine2=input("Entrer votre texte : ")
chaine2="".join(reversed(chaine2))
print(chaine2)
fin=time.time()
print("Temps d'execution de la 2ème méthode : ", fin-debut)
