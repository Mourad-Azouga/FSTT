def Est_pair(X):
    if X == 0:
        return(9)
    elif X % 2 == 0:
        return(1)
    else:
        return(0)

X = int(input("SVP saisir le nombre:\n"))
renvoi = Est_pair(X)
if renvoi == 1:
    print(X, "Est un nombre pair")
elif renvoi == 0:
    print(X, "Est un nombre impair")
elif renvoi == 9:
    print(X, "Est zero")