def d(num):
	add=0
	for i in range(1,num):
		if not num%i:add+=i
	return(add)
sets = []
for a in range(1,10000):
        b = d(a)
        if (d(b) == a and a!=b):
                sets.append(a)
                sets.append(b)

print(sum(set(sets)))        
