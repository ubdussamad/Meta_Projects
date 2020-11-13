from math import *
from time import time

def factors(n):
        step = 2 if n%2 else 1
        return len(set(reduce(list.__add__,
                    ([i, n//i] for i in range(1, int(sqrt(n))+1, step) if n % i == 0))))

def genrate_triangular(index):
    return (index*(index+1))/2
    
    
def nu_of_factors1b(n):
    result_set = set()
    for i in range(1, 1+int(n**0.5)):
        if n % i == 0:
            result_set.add(n // i)
            result_set.add(i)
    return len(result_set)
    
t1 = time()
j = 12000
while 1:
    factor = factors(genrate_triangular(j))
    if factor > 620:
        print genrate_triangular(j)
        break
    j+=1
t2 = time()
print(t2-t1)
