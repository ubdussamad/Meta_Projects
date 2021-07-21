import math
import matplotlib.pyplot as plt
import numpy as np
def main ():
    x = np.linspace(0,80,10000)                   #I can feed (To DAC) this as as a lookup table and
    plt.plot(x,[math.sin(i)**2 for i in x] , "g") # round robin to produce a killer crispy sine wave.
    plt.axis([0, 80, -4, 4])
    plt.plot(x , [0 for i in x] , "r--" ) 
    plt.ylabel('f(x) = sin(x)')
    plt.show()


if __name__ == "__main__":
    main()
