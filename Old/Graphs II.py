import math
import matplotlib.pyplot as plt
import numpy as np
from random import randint
def main ():
    print("Something works.")
    base = [*range(100)]
    plt.plot( base , [randint(0,100) for i in base] , "g")
    plt.axis([0, 100, 0, 200])
    plt.plot(base , [0 for i in base] , "g--" )
    plt.plot( base  , [101 for i in base] , "r--" )
    plt.plot( base  , [50 for i in base] ,"b--" )
    plt.ylabel('f(x) = sin(x)')
    plt.show()


if __name__ == "__main__":
    main()
