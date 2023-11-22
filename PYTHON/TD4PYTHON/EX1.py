list =["Ahmed", "Abdo","Karim", "Simo", "Mohammed","Abdo"]
rech = input("Nom a chercher?\n")

def rechercher_element(rech):
    resul = []
    resulindi = []
    for i in range(len(list)):
        if rech == list[i]:
            resul.append(list[i])
            resulindi.append(i)
        else:
            continue
    for i, x in zip(resul, resulindi) :
        print ("Trouver le nom:",i,"Dans l'indice: ", x)
    if len(resul) == 0:
        print("Pas trouver")

rechercher_element(rech)

