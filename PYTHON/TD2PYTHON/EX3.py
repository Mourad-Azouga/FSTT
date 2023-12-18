"""def maximum(a,b,c):
    if a > b:
        if a > c:
            max=a
        else:
            max=c
    else:
        if b > c:
            max=b
        else:
            max=c
    return(max)
a = float(input("Entrer a: "))
b = float(input("Entrer b: "))
c = float(input("Entrer c: "))
print("Le max de ",a, b, c, "est", maximum(a,b,c))"""
def maximum(a, b, c):
    if (a > b):
        if (a > c):
            return a
        else:
            return c
    else:
        if (b > c):
            return b
        else:
            return c
a = int(input("a"))
b = int(input("b"))
c = int(input("c"))
print(maximum(a, b ,c))
        