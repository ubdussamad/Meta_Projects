import math
from PIL import Image
import numpy as np
import time
import scipy.signal

z = Image.open("grim_reaper.jpg")
print(z.size)
print(z.filename)
print(z.format)
print(z.getpixel((10,20)))
print(z.getpixel((40,50)))
print(z.getpixel((80,10)))
z = z.convert('L')
a= np.array( z )

conv_filter = np.array([[0,-1,0],[-1,5,-1],[0,-1,0]])

j=scipy.signal.convolve2d(a , conv_filter)
print(type(j))


k = Image.fromarray(np.array(j))
#print("Showing Image")
#k.show()
