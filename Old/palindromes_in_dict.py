import math

f = open("/usr/share/dict/american-english" , 'r')
file = f.read()
f.close()

p_list = []
for i in file.split("\n"):
	if i == i[::-1]:
		p_list.append(i)

f = open("/home/samad/Desktop/palindromes.txt" , 'w')
p_list ='\n'.join(filter(lambda x:x is not '',[i if len(i)-1 else '' for i in p_list]))
f.write(p_list)
f.close()
