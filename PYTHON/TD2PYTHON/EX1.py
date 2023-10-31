def Est_pair(X):
    if X % 2 == 0:
        return(1)
    else:
        return(0)

X = float(input("SVP saisir le nombre:"))
renvoi = Est_pair(X)
if renvoi == 1:
    print(X, "Est un nombre pair")
elif renvoi == 0:
    print(X, "Est un nombre impair")