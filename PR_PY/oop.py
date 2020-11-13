from math import *
from time import time
def global_timer(func):
    def wrapper(*args,**kwargs):
        print("Wrapper executed before the main funtion!")
        t1 = time()
        f = func(*args,**kwargs)
        t2 =  time()
        print("timedelta:%s"%format(t2-t1,'.22f'))
        return f
    return wrapper

class Polynomial:
    def __init__(self,*coeffs):
        self.coeffs = coeffs

    def __repr__(self):
        return "<Polynomian function of degree %d with cofficients:%s>"%(len(self.coeffs)-1, ','.join(map(str,self.coeffs)) )
    def __add__(self, other):
        return Polynomial(*[ i+j for i,j in zip(self.coeffs,other.coeffs) ] )
    @global_timer
    def __len__(self):
        return len(self.coeffs)
    def __call__(self):
        return "Roots are as follows!"
    def __type__(self):
        return "Polynomial_Object"
    @global_timer
    def roots (self):
        try:
            a,b,c = self.coeffs
            r1,r2 = ((-b)+((b**2)-(4*a*c))**(1/2))/(2*a),((-b)-((b**2)-(4*a*c))**(1/2))/(2*a)
            return (r1,r2)
        except Exception as e:
            return ("Can seem to work my way arounf this one (The ploy might not be quadratic! \n %s"%(e,))

assert(hasattr(Polynomial,"roots")),"you broke Bitch!"
