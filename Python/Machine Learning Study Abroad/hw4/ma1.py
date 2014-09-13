from numpy import *
WINDOW = 10
data = [1,2,3,4,5,5,5,5,5,5,5,5,5,5,5]
weightings = repeat(1.0, WINDOW) / WINDOW
y=convolve(data, weightings,'valid')
print y
