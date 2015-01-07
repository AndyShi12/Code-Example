// Playground - noun: a place where people can play

import UIKit

var str = "Hello, playground"

var num = 4
var prime = true;

if (num > 2){
    prime=false
}
else {
for (var n = 2; n < num; n++)
{
    if num % n == 0
    {
    prime = false
    }
}
}

println(prime)