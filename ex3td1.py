import math
a = input("Svp saisir a\n")
b = input("Svp saisir b\n")
c = input("Svp saisir c\n")
if a == "" or b == ""  or c == "":
    print("une ou plusieurs valeus n'existent pas")
    quit()
if a == 0 :
    print("a ne peut pas etre 0")
    quit()
a = int
b = int
c = int
print("Votre equation est:\n", a,"x2 + ", b,"x + ",c )
delt = b * b - 4 * a * c
if delt > 0 :
    x1 = (-b + math.sqrt(delt)) / (2 * a)
    x2 = (-b - math.sqrt(delt)) / (2 * a)
    print("Les solutions sont:\n X1 = ", x1, "X2 = ", x2)
elif delt < 0 :
    print("Pas de solution dans R")
else :
    x = -b / (2 * a)
    print("La solution est:\n X = ", x)