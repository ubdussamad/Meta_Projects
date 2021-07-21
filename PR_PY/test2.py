with open('prime','r') as fobj:
    file = fobj.read()
file = file.split(' ')
def chk(x):
    return(x not in [' ','\n'])

file = [int(i) for i in file if not i in ['',' ','\n']]
file = [ i for i in file if i<10000]
l =[]
import time
t1 = time.time()
def divisors(x):
    li =[]
    for i in range(1,x):
        if not x%i:
            li.append(i)
    return sum(li)
for a in range(10000):
     if a in file:continue
     b = divisors(a)
     c = divisors(b)
     if a==c:
         l.append(a)
         l.append(b)
print(time.time()-t1)
print(sum(l))
