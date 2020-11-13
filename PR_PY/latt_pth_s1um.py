#Lattice path sum, Python implimentation
def func(r1,r2):
    ''' r1:n r2:n+1 -->> Returns the array of dia r1'''
    #print('\n\n')
    l = []
    #print(r1,'\n',r2)
    for i in r1:
        #print('i is:',i)
        a1 = r2[r1.index(i)]+i
        a2 = r2[r1.index(i)+1]+i
        #print('+1 , -1 are',a1,a2)
        l.append(max(a1,a2))
    if len(l) <2:print(l)
    return(l)

a = open('p067_triangle.txt','r').read()
a='''3
7 4
2 4 6
8 5 9 3'''
a = a.split('\n')


#a.pop(-1)

a  = [list(map(int,i.split(' '))) for i in a]
las = len(a)
#print(a)
for i in range(las): #start from n-1 and loop n-1 times
    try:
        ll = len(a)
        z = func(a[ll-2],a[ll-1])
        del a[ll-1]
        del a[ll-2]
        a.append(z)
    except Exception as err:print("passing",err)

        

