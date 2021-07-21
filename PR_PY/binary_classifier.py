import math
import numpy

def mean(list):
    return sum(list)/len(list)

def variance(list):
    mean = mean(list)
    return sum([ ((i-mean)**2) for i in list ]) / (len(list)-1)

def covariance(*list):
    mean_x = mean(list[0])
    mean_y = mean(list[1])
    return sum([(x - mean_x)*(y - mean_y) for x,y in list[0],list[1]]) / (len(x)-1)

w1 = covariance(x,y) / variance(x)

w0 = mean(y) - (w1 * mean(x))
