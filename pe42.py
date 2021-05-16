
f=open('p042_words.txt','r')
l = f.read()
f.close()
words = [ i.strip("\"") for i in l.split(',')]
abc = [i for i in 'abcdefghijklmnopqrstuvwxyz']

# tn = (1/2) n (n+1)
# thus,
# the quadratic equation: n^2 + n - 2*tn = 0
# if this quad eqn has REAL & WHOLE number roots
# then tn is a triangle number.
# and n is the index of that triangle number
# Thus we find n (roots) and see if they're real , +ve and whole.
def root(b,a,c):
	d = ( (b**2) - (4*a*c) ) **(1/2)
	return [ ( (-b+d) / (2*a) ) , ( (-b-d) / (2*a))]

count = 0

for i in words:
	tn = 0
	for j in i:
		tn += abc.index(j.lower())  + 1
	for i in root(1,1,-2*tn):
		if i.is_integer():
			count+=1
			break
print(count)
