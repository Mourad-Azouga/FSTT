panier = []
def ajout():
    print("Vous avez choisis l'ajout des produits")
    N = int(input("SVP de saisir le nombre des produits: "))
    for i in range(N):
        new_code = input("SVP de saisir le nouvel code: ")
        id = finder(new_code)
        if id != 555:
            print("Code produit deja trouver, taper 1 pour retaper le code, ou 2 pour augmenter quantite")
            choix2 = int(input("Votre choix: "))
            if choix2 == 1:
                quit
            elif choix2 == 2:
                panier[id][3]+=1
                print("Quantite changer pour l'item: ", panier[id])
        else:
            new_name = input("SVP de saisir le nouvel nom d'item: ")
            new_prix = float(input("SVP de saisir le nouvel prix: "))
            new_qte = int(input("SVP de saisir la nouvelle quantite: "))
            panier.append([new_code, new_name, new_prix, new_qte])
            print("Item ajoutee avec succe->\nCode: {} Nom: {} Prix: {}DH Qte: {}".format(panier[len(panier)- 1][0],panier[len(panier)- 1][1],panier[len(panier)- 1][2],panier[len(panier)- 1][3]))
  
def finder(code):
    for i in range(len(panier) - 1):
        if code == panier[i][0]:
            return (i)
    return(555)
def calcul():
    sum = 0
    for i in range(len(panier)):
        sum += float(panier[i][2] * panier[i][3])
    return(sum)
def calcul_affi(sum):
    print("Total Hors Tax: {:.2f}DH".format(sum))
    print("Total TVA: {:.2f}DH".format(sum * .2))
    print("Total TTC: {:.2f}DH".format(sum + (sum * .2)))
def modif():
    change_code = input("SVP de saisir le code a modifier: ")
    id = finder(change_code)
    if id != 555:
        print("Code {} correspand a {}, prix: {:.2f}, quantite: {}".format(panier[id][0], panier[id][1], panier[id][2], panier[id][3]))
        new_code = input("SVP de saisir le nouvel code: ")
        if finder(new_code) != 555:
            print("Code existant, modification annulee")
            quit
        else:#no need to handle error because the float input wont allow anything but float, as well as int
            new_name = input("SVP de saisir le nouvel nom: ")
            new_prix = float(input("SVP de saisir le nouvel prix: "))
            new_qte = int(input("SVP de saisir la nouvelle quantite: "))
            panier.pop(id)
            panier.insert(id, [new_code, new_name, new_prix, new_qte])
            print("Item modifier avec succee, les nouvelles info d'item: ", panier[id])
    elif id == 555:
        print("Item non trouvee, veuiller l'ajouter, modification annulee:")

def affi(sum):
    print("Code du produit\tNom du produit\t\tQuantité\tPrix Unitaire")
    panier.sort()
    for i in range(len(panier)):
        if panier[i][1].count(' ') == 0:
            print("{}\t\t{}\t\t\t{}\t\t\t{:.2f}DH".format(panier[i][0], panier[i][1], panier[i][3], panier[i][2]))
        else:
            print("{}\t\t{}\t\t{}\t\t\t{:.2f}DH".format(panier[i][0], panier[i][1], panier[i][3], panier[i][2]))
    print("\nPrix total:\t{:.2f} DH".format(sum + (sum * .2)))

def suppi():
    suppi_code = input("SVP de saisir le code d'item a supprimer:")
    id = finder(suppi_code)
    if id == 555:
        print("Item non trouvee, suppression annulee")
        quit
    else:
        print("Item trouver: {}".format(panier[id]))
        choix2 = int(input("Etes vous sure?\nTaper 1->oui\nTaper 2->non\n"))
        if choix2 == 1:
            panier.pop(id)
            print("Item supprime avec succee!")
        else:
            print("Suppression annulee!")
            quit

while (True):
    print("\nBienvenu au System Panier:\nMenu general:\n(1) Ajouter les produits\n(2) Calculer le prix total des produits\n(3) Afficher la facture total du client\n(4) Modifier les informations d'un produit\n(5) Supprimer un produit")
    choix = int(input("Votre choix: "))
    match (choix):
        case 1 : ajout()
        case 2 : calcul_affi(calcul())
        case 3 : affi(calcul())
        case 4 : modif()
        case 5 : suppi()
        case 555: break
        case _ : print("Choix non reconnue veuiller reassayer")
