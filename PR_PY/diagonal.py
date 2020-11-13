import numpy as np
z = np.random.rand(12,12)

def down(x,y):
    return x+1,y

def right(x,y):
    return x,y+1
count = 0

def t(z,t):#Starts from t to right and left of it in z , returns None if can't
    global count
    #print(t)
    if t == -1:
        count +=0.5
        return
    try:
        d = list(map(int,np.where(z==z[ down(*t) ])))
    except:
        d = -1
    try:
        r = list(map(int,np.where(z==z[ right(*t) ])))
    except:
        r = -1
    return d,r
i = [0,0]

def map_(z,i):
    global count
    try:
        a=t(z,i)[0]
        map_(z,a)
    except Exception as err:
        #print(err)
        pass
    try:
        b = t(z,i)[1]
        map_(z,b)
    except Exception as err:
       # print(err)
        pass
map_(z,[0,0])
print(count)
