#PE?27
#16MAR2K18
def mod(num):
    return(-num if num<0 else num)
from math import *
def is_prime(num):
    num = mod(num)
    if num == 2:return 1
    if num%2 == 0:return 0
    i = 3
    while i < int(round(sqrt(num)) + 1):
        if num % i == 0:return 0
        i += 2
    return 1
def num_of_primes(a,b):
    n = 0
    c_p = []
    while 1:
        z = n**2 + a*n + b
        if is_prime(z):
            c_p.append(z)
        else:
            return len(c_p)
        n+=1
max_p = 0
pair = []
for a in range(-999,1000):
    for b in range(-1000,1001):
        nop = num_of_primes(a,b)
        if nop>max_p:
            max_p = nop
            pair = [a,b]
print(pair)
