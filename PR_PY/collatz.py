def collatz(numb):
    if numb%2:
        return (3*numb + 1)
    else:
        return (numb / 2)
num = 13
def lar(num):
    onum = num
    lis = []
    while 1:
        if collatz(num) == 1:
            break
        lis.append(collatz(num))
        num = collatz(num)
    l = len(lis)
    del lis
    return onum,l+2
