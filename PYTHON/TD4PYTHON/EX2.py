list =[]
tsil = []
def invers(list):
    for i in range(len(list) - 1, -1, -1):
        tsil.append(list[i])
N = int(input("list size\n"))
for i in range (N):
    elm = input("New list element \n")
    list.append(elm)
invers(list)
print(list)