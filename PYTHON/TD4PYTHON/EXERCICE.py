notes = []
def ajou():
    note = int(input("Svp d'introduire la note de l'etudiant"))
    notes.append(note)
def aff_liste():
    print(notes)
def maxi():
    max = notes[0]
    for i in range(len(notes)):
        if max < notes[i]:
         max = notes[i]
    print("Le max est:", max)
def mini():
    min = notes[0]
    for i in range(len(notes)):
        if min > notes[i]:
            min = notes[i]
    print("Le min est", min)
def moy():
    j = 0
    n = 0
    for i in range(len(notes)):
        j+= notes[i]
        n+= 1
    moy = j / n
    print("La moy est:", moy)
def decroi():
    notes.reverse
    print("Reverse", notes)


print("1. Ajouter N notes ( la valeur de N est choisi par lutilisateur) \n2. Afficher la liste des notes des étudiants \n3. Afficher la note maximale \n4. Afficher la note minimale \n5. Afficher la note moyenne du groupe \n6. Trier la liste des notes d/'une manière décroissante \n7. Terminer l/'exécution du programme")
while True:
    choix = int(input("SVP de saisir l'indice d'operation\n"))
    match choix:
        case 1:
            ajou()
        case 2:
            aff_liste()
        case 3:
            maxi()
        case 4:
            mini()
        case 5:
            moy()
        case 6:
            decroi()
        case 7:
            quit()
        case _:
            print("Taper de 1 a 7 w zyar m3ana")


