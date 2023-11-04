import math
def somme(a, b):
    som = a + b
    return(som)
def sous(a, b):
    sus = a - b
    return(sus)
def multi(a, b):
    mul = a * b
    return(mul)
def div(a, b):
    if b == 0:
        print("b ne peut pas prendre 0")
        return
    dii = a / b
    return(dii)
def puis(a, b):
    pui = a ** b
    return(pui)
def raccar(a):
    sq = math.sqrt(a)
    return(sq)
def carr(a):
    car = a * a
    return(car)
def cube(a):
    cub = a * a * a
    return(cub)
def valab(a):
    if a < 0:
        vall = -a
    else:
        vall = a
    return(vall)
def pgcd(a, b):
    aend = a
    bend = b
    while b != 0:
        temp = a % b
        a = b
        b = temp
    return(a)
def fac(N):
    i = 0
    faq = 1
    for i in range(N) :
        faq *= i + 1
        i = i + 1
    return(faq)

print("Liste des opérations\n----------------------\nSomme             taper 1\nSoustraction      taper 2\nMultiplcation     taper 3\nDivision          taper 4\nPuissance         taper 5\nRacine carrée     taper 6\nCarré             taper 7\nCube              taper 8\nValeur absolue    taper 9\nPGCD              taper 10\nFactorielle       taper 11\nQuitte            taper 0\n")
while True:    
    OP = int (input("Saisir le code d'opetation desirée\n"))
    match OP:
        case 0:
            print("Au revoir")
            quit()
        case 1:
            print("Vous avez choisis la Somme:\n")
            a = float(input("Saisir le 1er num\n"))
            b = float(input("Saisir le 2eme num\n"))                
            print(a, "+", b, "=", somme(a,b))
        case 2:
            print("Vous avez choisis la Soustraction\n")
            a = float(input("Saisir le 1er num\n"))
            b = float(input("Saisir le 2eme num\n"))
            print(a, "-", b, "=", sous(a, b))
        case 3:
            print("Vous avez choisis la Multiplication\n")
            a = float(input("Saisir le 1er num\n"))
            b = float(input("Saisir le 2eme num\n"))
            print(a, "*", b, "=", multi(a,b))
        case 4:
            print("Vous avez choisis la Division\n")
            a = float(input("Saisir le 1er num\n"))
            b = float(input("Saisir le 2eme num\n"))
            print(a, "/", b, "=", div(a, b))
        case 5:
            print("Vous avez choisis la Puissance\n")
            a = float(input("Saisir le 1er num\n"))
            b = float(input("Saisir la puissance\n"))
            print(a, "^", b, "=", puis(a, b))
        case 6:
            print("Vous avez choisis la Racine carrée\n")
            a = float(input("Saisir le num\n"))
            if a < 0:
                print(a, "< 0
            print("√",a,"=", raccar(a))
        case 7:
            print("Vous avez choisis le Carré\n")
            a = float(input("Saisir le num\n"))
            print(a, "^ 2 =", carr(a))
        case 8:
            print("Vous avez choisis le Cube\n")
            a = float(input("Saisir le num\n"))
            print(a, "^ 3 =", cube(a))
        case 9:
            print("Vous avez choisis la Valeur absolue\n")
            a = float(input("Saisir le num\n"))
            print("|",a, "| =", valab(a))
        case 10:
            print("Vous avez choisis la PGCD\n")
            a = float(input("SVP saisir le 1er nombre\n"))
            b = float(input("SVP saisir le 2eme nombre\n"))
            print("Le PGCD de", a, "et", b, "est", pgcd(a, b))
        case 11:
            print("Vous avez choisis la Factorielle\n")
            N = int(input("SVP de saisir le nombre\n"))
            print(N, "! = ", fac(N))
        case _:
            print("SVP de taper un nombre de 0 a 11")
