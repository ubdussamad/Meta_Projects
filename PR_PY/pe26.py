#Project Euler 26
#@ubdussamad
#Ref: 1Mar18
#http://multporn.net/comics/wonder_woman
#Maximum number of recurring cycles.
def timeit(func):
	def time_wrapper(*args,**kwargs):
		import time
		initial = time.time()
		z = func(*args,**kwargs)
		print("Time delta: %f"%(time.time() - initial,))
		return z
	return time_wrapper
def count(num):
    count = 0
    while 1:
        num /= 10
        if num < 1:count += 1;break
        else:count+=1
    return(count)

def terminating(num):
    while 1:
        if num == 1:
            return(1)
            break
        if not(num%5):
            num = num/5
        elif not(num%2):
            num = num/2
        else:
            return(0)

def remove_multiple(num): #Removes multiples of 2 or 5
    while 1:
        if not(num%5):
            num = num/5
        elif not(num%2):
            num = num/2
        else:
            return(num)
            
def T(num,dem):
    digits = []
    rem = num%dem
    while 1:
        if rem==0:return(0)
        while 1:
            if rem<dem:
                rem = rem * 10
            else:
                break
        rem = rem%dem
        if rem in digits:
            return(len(digits[digits.index(rem):]))
        digits.append(rem)
@timeit
def s():
    mt =0
    num = 0
    for i in range(1,1001):
        t = T(1,i)
        if t>mt:
            mt = t
            num = i
    print(num,mt)
    return(num,mt)


s()
