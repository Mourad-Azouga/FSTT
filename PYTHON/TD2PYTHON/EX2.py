def somme_suite(N):
    som=0
    for i in range(N+1):
        som += i
    return(som)
X = int(input("Entrer un entier:"))
som = somme_suite(X)
print("La somme de la suite est:", end="")
i = 1
for i in range(1, X+1):
    if i < X:
        print(i,"+ ",end="")
    else:
        print(i, "=", som)