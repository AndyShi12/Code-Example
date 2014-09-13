# Homework 2 Problem 2
# Code from Chapter 2 of Machine Learning: An Algorithmic Perspective
# by Stephen Marsland (http://seat.massey.ac.nz/personal/s.r.marsland/MLBook.html)

# You are free to use, change, or redistribute the code in any way you wish for
# non-commercial purposes, but please maintain the name of the original author.
# This code comes with no warranty of any kind.

# Stephen Marsland, 2008

# This is the start of a script for you to complete
from pylab import *
from numpy import *
import linreg, linreg_logic_eg, cPickle, gzip, random
#train = np.array(loadtxt('prostate_data_test',comments='"', dtype=float))
#test = np.array(loadtxt('auto_mpg.txt',comments='"', dtype=float))

data = np.array(loadtxt('auto_mpg.txt',comments='"', dtype=float))

# Separate the data into training and testing sets
random.shuffle(data)

train_set = data[:195]
trainin = train_set[:,0:7]
traintgt = train_set[:,7]

test_set = data[196:]
testin = test_set[:,0:7]
testtgt = test_set[:,7]

# Normalise the data

#This is the training part
beta = linreg.linreg(trainin,traintgt)
testin = concatenate((testin,-ones((shape(testin)[0],1))),axis=1)
testout = dot(testin,beta)
error = sum((testout - testtgt)**2)

figure(1)
plot(testtgt)
plot(testout)
show()
print error
"""plt.scatter(testtgt, testout)
plt.xlabel("Target")
plt.ylabel("Output")
plt.title("Target Value vs Output Value")
plt.show()

print error"""