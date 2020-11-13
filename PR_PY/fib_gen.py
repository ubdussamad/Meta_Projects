def timeit(func):
	def time_wrapper(*args,**kwargs):
		import time
		initial = time.time()
		z = func(*args,**kwargs)
		print("Time delta: %f"%(time.time() - initial,))
		return z
	return time_wrapper


#@timeit
def fibonacci():
    a, b = 0, 1
    while True:
        yield a
        a, b = b, a + b
@timeit
def main():
        for j,i in enumerate(fibonacci()):
                if i>10**999:
                        print('The index is:',j,',and the value at that index is:',i)
                        break

main()
