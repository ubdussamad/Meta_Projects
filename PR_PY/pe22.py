f = open('p022_names.txt','r')
file = f.read()
f.close()
names = file.split(',')
names = [i.strip('\"').lower() for i in names]
names = sorted(names)

keys = [*"abcdefghijklmnopqrstuvwxyz"]
values = [*range(1,27)]

aval = dict(zip(keys,values))

def getaval(string):
    add = 0
    for i in string:
        add+=aval[i]
    return add
total_sum=0
for index,name in enumerate(names):
    val = getaval(name)
    total_sum += val*(index+1)

print(total_sum)
