
import math

def find_common(x,y):
    x_d = [x//10 , x%10]
    y_d = [y//10 , y%10]
    if x_d[0] == y_d[0] or x_d[0] == y_d[1]:
        return(x_d[0])
    elif x_d[1] == y_d[0] or x_d[1] == y_d[1]:
        return(x_d[1])
    else:
        return(0)

def d_non_common_terms (x,y):
    common = find_common(x,y)
    x_d = [x//10 , x%10]
    y_d = [y//10 , y%10]
    return( x_d[1] if  x_d[0]==common else x_d[0],
            y_d[1] if  y_d[0]==common else y_d[0] )

n_p = 1
d_p = 1
for i in range(10,99):
    for j in range(10,99):
        #Find a common term
        if find_common(i,j):
            if (i<j):
                nc_num,nc_denum = d_non_common_terms(i,j)
                if nc_num and nc_denum and nc_num%nc_denum:
                    if abs(nc_num/nc_denum - i/j) <= 0.001:
                            print("Bingo!",i,j)
                            n_p *= i
                            d_p *= j
print(n_p,d_p)




