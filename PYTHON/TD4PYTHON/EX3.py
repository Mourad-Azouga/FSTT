list =[15,4878,44,262,4,98,4,21,2,8,51,51,84,1,51,31,3,6]
def maximum(list):
    max = list[0]
    for i in range(len(list)):
        if max < list[i]:
            max = list[i]
    return(max)
def minimum(list):
    min = list[0]
    for i in range(len(list)):
        if min > list[i]:
            min = list[i]
    return(min)
def somme(list):
    som = 0
    for i in range(len(list)):
        som+=list[i]
    return(som)
def moyenne(list):
    som = somme(list)
    return(som // len(list))
print("Le max", maximum(list))
print("Le min:", minimum(list))
print("La somme:", somme(list))
print("La moy:", moyenne(list))
