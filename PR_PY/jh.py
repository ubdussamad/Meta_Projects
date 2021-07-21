Python 3.5.2 (default, Nov 23 2017, 16:37:01) 
[GCC 5.4.0 20160609] on linux
Type "copyright", "credits" or "license()" for more information.
>>> from PIL import Image
>>> death = Image.open('death.png','r')
Traceback (most recent call last):
  File "<pyshell#1>", line 1, in <module>
    death = Image.open('death.png','r')
  File "/usr/lib/python3/dist-packages/PIL/Image.py", line 2258, in open
    fp = builtins.open(filename, "rb")
FileNotFoundError: [Errno 2] No such file or directory: 'death.png'
>>> death = Image.open('death','r')
>>> parda = Image.open('parda.png','r')
>>> duniya = Image.new('RGB',(400,400))
>>> for i in range(400):
	for j in range(400):
		if (i+j)% 2 == 0:
			duniya.putpixel((i,j),death.getpixel((i,j)))
		else:
			duniya.putpixel((i,j),parda.getpixel((i,j)))

			
>>> duniya.show()
>>> 
