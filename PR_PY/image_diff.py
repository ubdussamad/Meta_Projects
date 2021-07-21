import cv2

l1 = cv2.imread('1.jpg')
l2 = cv2.imread('2.jpg')

#l1 = cv2.resize(l1,(133,128))
#l2 = cv2.resize(l2,(133,128))

diff1 = cv2.absdiff(l2, l1)
diff1  = cv2.resize(diff1,((1920/5)*3,(1200/5)*3))
diff1 = cv2.cvtColor(diff1, cv2.COLOR_BGR2GRAY)
cv2.imshow('diff1', diff1)
cv2.waitKey(0)
cv2.destroyAllWindows()
#cv2.imwrite('new.jpg',diff1)
