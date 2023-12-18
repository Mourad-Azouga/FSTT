def palindrome(ch):
    for i in range(len(ch)):
        if (ch[::1] != ch[::-1]):
            return 0
    return 1
ch = input("input\n")
print(palindrome(ch))