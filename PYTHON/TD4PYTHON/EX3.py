list = []
def maxi(list):
    maxi = list[0]
    for i  in range(len(list)):
        if (maxi < list[i]):
            maxi = list[i]
    return maxi
def mini(list):
    min = list[0]
    for i  in range(len(list)):
        if (min > list[i]):
            min = list[i]
    return min
def sommi(list):
    sum = 0
    for i in range(len(list)):
        sum = sum + list[i]
    return sum
def moy(list):
    return sommi(list) / len(list)
 
N = int(input("list size\n"))
for i in range (N):
    elm = int(input("New list element \n"))
    list.append(elm)


print(maxi(list),mini(list), sommi(list), moy(list))