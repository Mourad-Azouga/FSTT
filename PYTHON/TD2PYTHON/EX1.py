def Est_pair (X):
    if X == 0:
        print("X est 0")
        return 2
    if X % 2 == 0:
        return 1
    else:
        return 0
x = int(input("INput"))
if (Est_pair(x) == 1):
    print("pair")
elif (Est_pair(x) == 0):
    print("impair")
else:
    print("0")