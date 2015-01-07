// Playground - noun: a place where people can play

import UIKit
//                              -----------  ARRAYS
var arr = [1,2,3,4,5]
arr[2]
arr.append(3)
println(arr)

arr.removeAtIndex(2)
arr.removeLast()
arr.removeRange(1...2)

var newArr = [1,2.3, "Tom"]
var emptyArr:[Int]
//emptyArr.append(3)

var dict = [
    "name":"Rob",
    "age":34,
    "gender":"male"
]

println(dict["name"]!)
dict["hair"] = "brown"
dict["age"] = "old"

var name = dict["name"]!
var myString = "my name is \(name)"
//var myString2 = "My name is \(dict[name]!)"

var numArr = [2,4,6,8]
numArr.removeAtIndex(0)
numArr.append(10)


var aboutMe = ["name":"rob", "age":34]
var name2 = aboutMe["name"]!
var age = aboutMe["age"]!
var myString2 = "my name is \(name2) and my age is \(age)"
