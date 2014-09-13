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

#data IO
data = gzip.open('mnist.pkl.gz', 'rb')
trainSet, validSet, testSet = np.array(cPickle.load(data))
data.close()

trainingIn = trainSet[0]
target = trainSet[1]
reduceTraining = trainingIn[0:2000,:]
reduceTarget = target[0:2000,]
reduceTarget = np.asmatrix(reduceTarget)

testInputs = testSet[0]
testTarget = testSet[1]

reducetInput = testInputs[0:2000,:]
reducetTarget = testTarget[0:2000,]
reducetTarget = np.asmatrix(reducetTarget)

beta = linreg2.linreg2(reduceTraining, reduceTarget)
reducetInput = concatenate((reducetInput, -ones((shape(reducetInput)[0],1))),axis=1)
reducetOutput = dot(reducetInput, beta)
error=sum((reducetOutput - reducetTarget)**2)

print ("Training Inputs")
print reduceTraining
print ("Test Inputs")
print reducetInput
print ("Error")
print error





#sizeinitial = trainSet.shape
#size = trainingIn.shape
#sizeTarget = target.shape
#print(sizeTarget)
#print(sizeinitial)
#print(size)
"""
beta = linreg.linreg(newInput, newTarget)
newtestinput = concatenate((newTestInput - ones((shape)))
finalOutput = dot(newInput, beta)
error = sum((finalOutput - testTarget)**2)

trainingIn = trainSet[0]
target = trainSet[1]
testIn = testSet[0]

shortIn = trainingIn[0:2000,:]
shortOut = target[0:2000]
shortTest = testIn[0:2000]

shortIn = numpy.asmatrix(shortIn)
shortOut = numpy.asmatrix(shortOut)
"""
"""
#shortOut = linalg
beta = linreg.linreg(shortIn,shortOut)
#linalg.pinv

#shortIn = concatenate((shortIn,-ones((shape(shortIn)[0],1))),axis=1)
#testout = dot(shortIn,beta)
#error = sum((testOut - shortOut)**2)
print error

#print(shortIn)
#print("...")
#print(shortValid)
#beta = linreg.linreg(shortIn,shortValid)

#shortTarget 
#testin = concatenate((shortIn,-ones((shape(shortIn)[0],1))),axis=1)
#testout = dot(testin,beta)
#error = sum((shortOut - shortValid)**2)
#print error
#print testin

#####
#shortTrain = trainSet[0:2000]
#shortTest = testSet[0:2000]
#shortValid = validSet[0:2000]
#print(shortTrain)
#print("..........................>>>>>>>>>>>>>>>")
#print(shortTest)
#print("..........................>>>>>>>>>>>>>>>")
#print(shortValid)

#beta = linreg.linreg(shortTrain, shortValid)
#shortTrain = concatenate((shortTrain,-ones((shape(shortTrain)[0],1))),axis=1)
#testout = dot(shortTrain,beta)
#error = sum((testout - testValid)**2)

#beta = linreg.linreg(trainin,traintgt)
#testin = concatenate((testin,-ones((shape(testin)[0],1))),axis=1)
#testout = dot(testin,beta)
#error = sum((testout - testtgt)**2)


"""
"""
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

plt.scatter(testtgt, testout)
plt.xlabel("Target")
plt.ylabel("Output")
plt.title("Target Value vs Output Value")
plt.show()

print error"""