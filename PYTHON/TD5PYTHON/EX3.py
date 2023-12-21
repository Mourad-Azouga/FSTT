import os

def ajouter_candidats():   
    cin = input("SVP de saisir cin\n")
    nom = input("SVP de saisir nom\n")
    pre = input("SVP de saisir pre\n")
    age = int(input("SVP de saisir age\n"))
    dec = input("SVP de saisir dec\n")
    concours = open("concours.txt", 'a+')
    concours.write(cin+";"+nom+";"+pre+";"+f"{age}"+";"+dec)
    print("Condidat ajoutee avec succee!\n")

def trier_candidats():
    with open("concours.txt", 'r') as ccc:
        li = ccc.readlines()
        li.sort()
        ctn = "".join(li)
    with open("concours.txt", 'w') as cc5:
        cc5.write(ctn)
    with open("concours.txt", 'r') as cc6:
        print(cc6.read())

def condidats_admis():
    with open("admis.txt", 'a+') as cck:
        with open("concours.txt", 'r') as cco:
            for ligne in cco:
                if 'admis' in ligne:
                    cck.write(ligne)
    with open("admis.txt", 'r') as ccl:
        print(ccl.read())

def condidats_refuse():
    with open("refuse.txt", 'a+') as cck:
        with open("concours.txt", 'r') as cco:
            for ligne in cco:
                if 'refuse' in ligne:
                    cck.write(ligne)
    with open("refuse.txt", 'r') as ccl:
        print(ccl.read())

def condidats_ajournee():
    with open("ajournee.txt", 'a+') as cck:
        with open("concours.txt", 'r') as cco:
            for ligne in cco:
                if 'ajourne' in ligne:
                    cck.write(ligne)
    with open("ajournee.txt", 'r') as ccl:
        print(ccl.read())
def liste_attente():
    with open("admis.txt", 'r') as cc:
        with open("attente.txt", 'a+') as att:
            for ligne in cc:
                lign = ligne.split(';')
                if int(lign[3])>=30:
                    att.write(ligne)
    with open("attente.txt", 'r') as att1:
        print(att1.read())
def statistiques() :
    with open("concours.txt","r") as id_fichier :
        l1=id_fichier.readlines()
        print(len(l1))
    with open("admis.txt","r") as id_admis :
        l2=id_admis.readlines()
        print(len(l2))
    with open("refus.txt","r") as id_refus :
        l3=id_refus.readlines()
        print(len(l3))
        print("Le pourcentage des candidats admis est ",(len(l2)/len(l1))*100, "%")
        print("Le pourcentage des candidats refusés est ",(len(l3)/len(l1))*100, "%")
        l4=len(l1)-len(l2)-len(l3)
        print("Le pourcentage des candidats ajournés est ",(l4/len(l1))*100,"%")
while True :
    print("Menu principal")
    print("(1) Ajouter les candidats ")
    print("(2) Afficher la liste triée des candidats ") 
    print("(3) Afficher la liste des candidas admis")
    print("(4) Afficher la liste d'attente des candidats")
    print("(5) Afficher les statistiques")
    print("(6) Quitter")
    choix = int(input("Entrer votre choix : "))
    match choix :
        case 1 :
            ajouter_candidats()
        case 2 :
            trier_candidats()
        case 3 :
            condidats_admis()
        case 4 :
            liste_attente()
        case 5 :
            statistiques()
        case 6 :
            print("Fin du programme")
            break
        case _ :
            print("choix invalide")