import math
import matplotlib.pyplot as plt
import numpy as np
from random import randint
counter = 1
class line ( object ) :
    def __init__ ( self ):
        global counter
        self.x = randint(1,10*counter)
        counter+=1
        self.yi = randint(1,80)
        self.yf = randint(self.yi , self.yi+randint(1,40) )
        plt.plot( [self.x for i in range(self.yf-self.yi)] , [i for i in range(self.yi,self.yf)] )
dc = {}
for i in range(5):
    dc[i] = line()

plt.show()
  
