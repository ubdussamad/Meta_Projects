def triangular_num(index):
    sum_ = 0
    for i in range(index+1):
        sum_ += i
    return sum_
def num_divisors(num):
    l = []
    for i in range(1,num+1):
        if num%i == 0:
            l.append(i)
    z = len(l)
    del l
    return z


i = 0
while 1:
    t_index = triangular_num(i)
    div = num_divisors(t_index)
    if div > 500:
        print(t_index,div,i)
    i = i+1

