import os
text = open("test.txt", 'r')
newtext = open("test2.txt", 'a')
str = text.read()
print(text.read())
newtext.write(str)
text.close()
newtext.close()