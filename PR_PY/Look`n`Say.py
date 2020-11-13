#Python Implementation of Look And Say Series
#PYthon 3v5
#Author : Samad Haque <mailto:ubdussamad@gmail.com>
#Ref:26Nov17
#This is a least effort solution.
a = [1, 11, 21, 1211, 111221]


def lns(element):
    main =[]
    element = str(element)+'e'# e-endian (for saving the last digits)
    ph = ''
    last = 0
    list_el = [i for i in element]
    for j,i in enumerate(element):
        if ph == '':ph = i
        if i != ph:
            main += [list_el[int(last):int(j)]]
            last = j
        ph = i
    output = ''
    for i in main:
        output += str(len(i))+i[0]
    return map(int,output)
print lns(122242)
n = [1]
"""for i in range(32):
    n.append(int(lns(n[-1])))
print(len(str(n[30])))"""
