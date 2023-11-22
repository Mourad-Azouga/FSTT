#3adel l'affichage makhedamch mezyan mlie kandiro return dial calcul f input dial affi katrewen d3wa
panier = {
      "001" : ["Nido", 18, 1],
      "005" : ["Danone Caramel", 18, 3],
      "002" : ["Jaouda Lait", 4, 2],
      "003" : ["Pain", 2, 5],
      "004" : ["Tagger", 1, 2]
}

def calcul(panier):
    sum = 0
    for key in panier:
        if len(panier[key][0].split()) == 1:
            print("{} \t= \t\t{} DH * {}".format(panier[key][0], panier[key][1], panier[key][2]))
        else:
            print("{} \t= \t{} DH * {}".format(panier[key][0], panier[key][1], panier[key][2]))
        sum += panier[key][1] * panier[key][2]
    tva = 0.2 * sum
    print("TVA 20%:\t\t{:.2f}".format(tva), "DH")
    print("TTC:\t\t\t{:.2f}".format(sum), "DH")
    print("Total:\t\t\t{:.2f}".format(sum + tva), "DH")
    return(sum+tva)

def affi(panier, sum, option):
    print("Code du Produit\tNom du produit\tQuantite\tPrix Unitaire")
    alphabi = sorted(panier.keys())
    for key in alphabi:
        if len(panier[key][0].split()) == 1:
            print("{}\t\t{}\t\t{}\t\t{}".format(key,panier[key][0],panier[key][2],panier[key][1]))
        else:
            print("{}\t\t{}\t{}\t\t{}".format(key,panier[key][0],panier[key][2],panier[key][1]))
    if option == 1:
        print("Total TTC: {:.2f}".format(sum), "DH")

def modif(panier, sum):
    affi(panier, sum, 0)
    choix = input("Veuiller selection l'item a modifier (Par ID): ")
    for key in panier:
        if key == choix:
            print("L'item choisit est:", panier[key])
            new_name = input("SVP de saisir le nouvel nom: ")
            if new_name == None:
                   print("Erreur d'input nom, ressayer")
                   exit
            else:
                   panier[key][0] = new_name
                   new_prix = float(input("SVP de saisir le nouvel prix: "))
            if new_prix == None:
                   print("Erreur d'input prix, ressayer")
                   exit
            else:
                   panier[key][1] = new_prix
                   new_qte = int(input("SVP de saisir la nouvelle quantite: "))
            if new_qte == None:
                   print("Erreur d'input qte")
                   exit
            else:
                    panier[key][2] = new_qte
            print("Item changee avec succee, nouvel info: ", panier[key])
        else:
              break

def suppri(panier, sum):
        print("Vous avez selectionner la suprresion d'un item: ")
        affi(panier, sum, 0)
        choix = input("SVP de saisir l'ID de l'item: ")
        for key in panier:
              if key == choix:
                    print("Item trouvee:", panier[key])
                    choix2 = input("Etes-vous sure de vouloir supprimer? (Action irreversible) (oui/non): ")
                    if choix2 == "oui":
                          del panier[key]
                          print("Item supprimer avec succe!")
                          break
                    elif choix2 == "non":
                        print("Suppresion annulee")
                        break
                    else:
                        print("Reponse non reconnue, suppression annulee")
        affi(panier, sum, 0)

while (True):
    option = 1
    print("\nBienvenu au System Panier by TimeXiTech:\nMenu general:\n(1) Ajouter les produits\n(2) Calculer le prix total des produits\n(3) Afficher la facture total du client\n(4) Modifier les informations d'un produit\n(5) Supprimer un produit")
    choice = int(input("Votre choix: "))
    match choice:
        case 1:
                print("Vous avez choisi d'ajoutter un nouvel produit dans le panier!\n")
                P_Code = str(input("Code Produit:"))
                P_Name = str(input("Nom Produit:"))
                P_Price = float(input("PU Produit:"))
                P_Qte = int(input("Qte Produit:"))
    

                if P_Code in panier:
                            panier[P_Code][2] += P_Qte
                else:
                            panier[P_Code] = [ P_Name, P_Price, P_Qte]
                print("Produit", panier[P_Code], "Ajoutee avec succe!")
        case 2: calcul(panier)
        case 3: affi(panier, calcul(panier), option)
        case 4: modif(panier, sum)
        case 5: suppri(panier, sum)
        case 666: break
        case _:
            print("Operation non reconnue, refaire")
