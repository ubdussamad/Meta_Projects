import math
from PIL import Image
import numpy as np
import time
z = Image.open("/home/samad/Pictures/silicon-valley-bachmanity-insanity.jpg")
print(z.size)
print(z.filename)
print(z.format)
print(z.getpixel((10,20)))
print(z.getpixel((40,50)))
print(z.getpixel((80,10)))

k= np.array( z )

for i in range(np.shape(k)[0]):
    for j in range(np.shape(k)[1]):
        i = sum(k[i][j])
        #sat= i%100 if i>200 else (i+100)%254
        k[i][j] = np.array([0,i//3,0])
k = Image.fromarray(k)
print("Showing Image")
k.show()
