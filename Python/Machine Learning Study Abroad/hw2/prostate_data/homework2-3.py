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
import pcn_logic_eg, linreg2, linreg_logic_eg, cPickle, gzip, random, numpy

trainSet = np.array(loadtxt('prostate_data_train.txt', comments='"', dtype=float))
testSet = np.array(loadtxt('prostate_data_test.txt', comments='"', dtype=float))

#training
tIn1 = trainSet[:, 0:4]
tIn2 = trainSet[:, 5:9]
training = concatenate((tIn1, tIn2), axis=1)

#testing
test1 = testSet[:,0:4]
test2 = testSet[:,5:9]
testing = concatenate((test1, test2), axis=1)

#training target
tTarget = trainSet[:,4]
tTarget = np.asmatrix(tTarget)

#test target
testTarget = testSet[:,4]

#concatenate
#training = concatenate((training, -ones((shape(training)[0],1))), axis=1)
beta = linreg2.linreg2(training, tTarget)
testing = concatenate((testing, -ones((shape(testing)[0],1))), axis=1)
testout = dot(testing, beta)

error = 0
error = [(testout[i,0]-testTarget[i])**2 for i in range(30)]
print sum(error)

"""print testing.shape
print testout.shape
print tTarget.shape
print testTarget.shape
print testout[0]
print testTarget[0]"""

p = pcn_logic_eg.pcn(training, tTarget)
#weights = p.pcntrain(training, tTarget, 0.25, 6)
weights = 0.01
testoutput = p.pcnfwd(testing)
testoutput=dot(testing, weights)
print sum(testoutput)