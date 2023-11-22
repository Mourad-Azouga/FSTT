list =[15,4,44,262,4,98,4,21,2,8888,51,51,84,1,51,31,3,6]
print(list)
serch = input("la valeur a faire disparaitre????:\n")
def supprimer_element():
    for i in range(len(list)):
        if serch != list[i]:
            continue
        else:
            list.remove(list[i])
    print(list)
supprimer_element(list)