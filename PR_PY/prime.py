def is_prime(num):
    if num == 2:return 1
    if num%2 == 0:return 0
    i = 3
    while i < int(round(sqrt(num)) + 1):
        if num % i == 0:return 0
        i += 2
    return 1


psum = 2

from math import *

j = 3

while j < 2000000:
    if is_prime(j):
        psum += j
    j += 2



print psum
