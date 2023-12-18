def comparaison_chaine(a, b):
    if (a == b):
        return 0
    if (a > b):
        return -1
    else:
        return 1
    
a = input("a")
b = input("b")
print(comparaison_chaine(a,b))