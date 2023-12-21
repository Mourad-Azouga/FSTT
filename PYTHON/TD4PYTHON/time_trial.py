panier = []
def ajout():
    N = int(input("SVP de saisir le nombre d'articles"))
    for i in range(N):
        new_code = input("SVP de saisir le nouveau code: ")
        if (finder(new_code) != 666):
            print("Code trouvee! SVP de modifier ou utiliser un autre code\n")
            continue
        else:
            new_nom = input("SVP de saisir le nouveau nom: ")
            new_pu = float(input("SVP de saisir le nv prix: "))
            new_qt = int(input("SVP de saisir la quantite: "))
            panier.append([new_code, new_nom, new_pu, new_qt])
            print("Item ajoutee avec succee!\nCode: {} Nom: {} Prix Unitaire: {} Quantite: {}".format(panier[i-1][0], panier[i-1][1], panier[i-1][2], panier[i-1][3]))

def finder(code):
    i = 0
    for i in range(len(panier) - 1):
        if panier[i][0] == code:
            return i
    return 666

def calculer():
    sum = 0
    for i in range(len(panier)):
        sum = sum + (panier[i][2] * panier[i][3])
    return sum

def afficher_calcul(sum):
    print("Le prix total a payer: {}DH".format(sum))
    
def affi(sum):
    panier.sort()
    print("Code produit\tNom du produit\tQuantite\tPrix Unitaire\n")
    for i in range(len(panier)):
        print("{}\t{}\t{}\t{}\n".format(panier[i-1][0], panier[i-1][1], panier[i-1][2], panier[i-1][3]))
    print("Prix total\t{}DH".format(sum))

def modifi():
    code = input("SVP de saisir le code a modifier!: ")
    opp = finder(code)
    if opp != 666:
        new_code = input("Code trouvee! SVP de donner le nouvel code: ")
        if finder(new_code) == 666:
            new_nom = input("SVP de saisir le nouveau nom: ")
            new_pu = float(input("SVP de saisir le nv prix: "))
            new_qt = int(input("SVP de saisir la quantite: "))
            panier.pop(opp)
            panier.append([new_code, new_nom, new_pu, new_qt])
            print("Item ajoutee avec succee!\nCode: {} Nom: {} Prix Unitaire: {} Quantite: {}".format(panier[opp][0], panier[opp][1], panier[opp][2], panier[opp][3]))
        else:
            print("Code tourvee! Operation annulee!\n")
            return
    else:
        print("Code pas trouvee! SVP d'ajouter un item avec ce code\n")
        return
def supip():
    code = input("SVP de saisir le code du produit a supprimer: ")
    opp = finder(code)
    if (opp != 666):
        for i in range(len(panier)):
            if panier[i][0] == opp:
                panier[i][0].pop()
        print("Code trouvee! Item suprrimee avec succee!\n")

while (1):
    print("Menu general:\n__________________________\n(1) Ajouter les poduits\n(2) Calculer le prix total a payer par le client\n(3) Afficher la facture total du client\n(4) Modifier les informations d\'un produit\n(5) Supprimer un produit\n")
    choix = int(input("Votre choix?"))
    match (choix):
        case 1: 
            ajout()
        case 2:
            afficher_calcul(calculer())
        case 3:
            affi(calculer())
        case 4:
            modifi()
        case 5:
            supip()
        case _:
            print("SVP de saisir les nombres entre 1 et 5")
