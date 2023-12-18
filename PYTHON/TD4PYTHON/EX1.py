list = []
def rech_elm(elm):
    for i in range(len(list)):
        if list[i] == elm:
            return 1
        else:
            return 0
N = int(input("list size\n"))
for i in range (N):
    elm = input("New list element \n")
    list.append(elm)
serch = input("element a chercher\n")
if (rech_elm(serch) == 1):
    print(serch, "Element trouvee !")
else:
    print(serch, "Element non trouvee")
