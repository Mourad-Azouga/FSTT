def somme_suite(N):
    temp = 0
    if N <= 0:
        return 404
    for i in range(N + 1):
        temp = temp + N
        N = N-1
    return temp
n = int(input("wowo"))
w = somme_suite(n)
if (w == 404):
    print("error")
else:
    print(w)