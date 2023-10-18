N = int(input("SVP de determiner le nombre des valeurs:\n"))
numbers = []
for i in range(N) :
    print("SVP saisir le num N°[", i, "]")
    number = int(input())
    numbers.append(number)

max = numbers[0]
for num in numbers :
    if num > max :
        max = num
print("le max est:\n", max)