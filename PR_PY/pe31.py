z = [1,2,5,10,20,50,100,200]
count = 0
for i in range(201): #1p
    for j in range(101): #2p
        for k in range(41): #5p
            for l in range(21): #10p
                for m in range(11): #20p
                    for n in range(5): #50p
                        for o in range(3):
                            if (i+j*2+k*5+l*10+m*20+n*50+o*100) == 200:
                                count+=1
print(count)

