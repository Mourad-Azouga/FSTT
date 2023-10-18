N = int(input("SVP de saisir le nombre\n"))
i = 0
faq = 1
for i in range(N) :
    faq *= i + 1
    i = i + 1
print(N, "! = ", faq)