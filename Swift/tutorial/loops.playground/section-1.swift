// Playground - noun: a place where people can play

import UIKit

var str = "Hello, playground"

/*for var i=0; i<15; i+=5
{
    println(i)
}

var arr = [2,4,5,6]
for (index, x) in enumerate(arr){
    println(index)
    arr[index] = x+1
}
println(arr)


var newArr = [4,6,8,10,12]

for (index, x) in enumerate(newArr){
        newArr[index] = x/2;
}
println(newArr)*/

var i = 0

while (i < 11){
    if i % 2 == 0{
        println(i)
    }
    i++
}


var arr = [6,3,2,1,6,8]
var index = 0
println()
while(index < arr.count){
    arr[index] = arr[index]-1
    println(arr[index])
    index++
}

