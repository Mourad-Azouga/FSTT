list =[15,4,44,262,4,98,4,21,2,8888,51,51,84,1,51,31,3,6]
print(list)

serch = int(input("la valeur a faire disparaitre?\n"))
def supprimer_element(list):
    list2=[]
    for i in range(len(list)):
        if list[i] != serch:
            list2.append(list[i])
    print(list2)
supprimer_element(list)