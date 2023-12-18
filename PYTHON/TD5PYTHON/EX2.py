import os
serch = input("Please input the text a chercher\n")
rempla = input("SVP input le remplacement\n")
def wow():
    file = open("test.txt", 'r+')
    x = file.read()
    if serch in x:
        x = x.replace(serch, rempla)
        print(x)   
    else:
        print("Not found")
    file.close()
wow()
