import math

counter = 0
for i in range (256):
    i = bin(i)[2:]
    i = '0'*(8 - len(i)) + i
    if (i[0] == '1') or (i[-2:] == '00'):
        counter+=1
        print("HIT @",i)
print("Total: ",counter)
