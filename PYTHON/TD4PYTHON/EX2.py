list =["Ahmed", "Abdo","Karim", "Simo", "Mohammed"]
print(list)
tsil=[]
def inverser_list(list):
    for i in range(len(list)-1, -1, -1):
           tsil.append(list[i])
    return(tsil)
resultat = inverser_list(list)
print(resultat)
