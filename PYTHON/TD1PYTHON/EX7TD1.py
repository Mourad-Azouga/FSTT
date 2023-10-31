import math
def somme():
    print("Vous avez choisis la Somme:\n")
    a = float(input("Saisir le 1er num\n"))
    b = float(input("Saisir le 2eme num\n"))
    som = a + b
    print(a, "+", b, "=", som)
def sous():
    print("Vous avez choisis la Soustraction\n")
    a = float(input("Saisir le 1er num\n"))
    b = float(input("Saisir le 2eme num\n"))
    sus = a - b
    print(a, "-", b, "=", sus)
def multi():
    print("Vous avez choisis la Multiplication\n")
    a = float(input("Saisir le 1er num\n"))
    b = float(input("Saisir le 2eme num\n"))
    mul = a * b
    print(a, "*", b, "=", mul)
def div():
    print("Vous avez choisis la Division\n")
    a = float(input("Saisir le 1er num\n"))
    b = float(input("Saisir le 2eme num\n"))
    if b == 0:
        print("b ne peut pas prendre 0")
        return
    dii = a / b
    print(a, "/", b, "=", dii)
def puis():
    print("Vous avez choisis la Puissance\n")
    a = float(input("Saisir le 1er num\n"))
    b = float(input("Saisir la puissance\n"))
    pui = a ** b
    print(a, "^", b, "=", pui)
def raccar():
    print("Vous avez choisis la Racine carrée\n")
    a = float(input("Saisir le num\n"))
    sq = math.sqrt(a)
    print("√",a,"=", sq)
def carr():
    print("Vous avez choisis le Carré\n")
    a = float(input("Saisir le num\n"))
    carr = a * a
    print(a, "^ 2 =", carr)
def cube():
    print("Vous avez choisis le Cube\n")
    a = float(input("Saisir le num\n"))
    cub = a * a * a
    print(a, "^ 3 =", cub)
def valab():
    print("Vous avez choisis la Valeur absolue\n")
    a = float(input("Saisir le num\n"))
    if a < 0:
        vall = a * -1
    else:
        vall = a
    print("|",a, "| =", vall)
def pgcd():
    print("Vous avez choisis la PGCD\n")
    a = float(input("SVP saisir le 1er nombre\n"))
    b = float(input("SVP saisir le 2eme nombre\n"))
    aend = a
    bend = b
    while b != 0:
        temp = a % b
        a = b
        b = temp
    print("Le PGCD de", aend, "et", bend, "est", a)
def fac():
    print("Vous avez choisis la Factorielle\n")
    N = float(input("SVP de saisir le nombre\n"))
    i = 0
    faq = 1
    for i in range(N) :
        faq *= i + 1
        i = i + 1
    print(N, "! = ", faq)

print("Liste des opérations\n----------------------\nSomme             taper 1\nSoustraction      taper 2\nMultiplcation     taper 3\nDivision          taper 4\nPuissance         taper 5\nRacine carrée     taper 6\nCarré             taper 7\nCube              taper 8\nValeur absolue    taper 9\nPGCD              taper 10\nFactorielle       taper 11\nQuitte            taper 0\n")
while True:    
    OP = int (input("Saisir le code d'opetation desirée\n"))
    match OP:
        case 0:
            print("Au revoir")
            quit()
        case 1:
            somme()
        case 2:
            sous()
        case 3:
            multi()
        case 4:
            div()
        case 5:
            puis()
        case 6:
            raccar()
        case 7:
            carr()
        case 8:
            cube()
        case 9:
            valab()
        case 10:
            pgcd()
        case 11:
            fac()
        case _:
            print("SVP de taper un nombre de 0 a 11")




