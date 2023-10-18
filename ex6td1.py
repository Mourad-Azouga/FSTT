a = int(input("SVP saisir le premier nombre\n"))
b = int(input("SVP saisir le 2eme nombre\n"))
aend = a
bend = b
while b != 0:
        temp = a % b
        a = b
        b = temp

print("Le PGCD de", aend, "et", bend, "est", a)