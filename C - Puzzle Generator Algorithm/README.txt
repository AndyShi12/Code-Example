This assignment asks you to generate the states of 15 puzzle.  The 15
puzzle is a popular game.  There are 15 squares in a 4 x 4 box.  One
is empty.  The solved state is shows below

1  2  3  4
5  6  7  8
9  A  B  C
D  E  F  -

Here, we use A to F for numbers 10 to 15. - is the space.  To play
this game, you can move the space.  For example, moving - up changes
the state to

1  2  3  4
5  6  7  8
9  A  B  -
D  E  F  C

Moving - left changes the state to

1  2  3  4
5  6  7  8
9  A  -  B
D  E  F  C

To solve this state, you can move - right and down.  However, if
you move it down and right, you will get this state

1  2  3  4
5  6  7  8
9  A  F  B
D  E  C  -

To make it simple, we will express each state by a single line from
the upper left side to the lower right side.  The solved state is
expressed as

123456789ABCDEF- 

There is no space between the numbers.l

123456789A-BDEFC expresses the following state

1  2  3  4
5  6  7  8
9  A  -  B
D  E  F  C

Please notice that we do not use "10"; we use "A" instead.

This assignment has three stages:

1. given a valid state and a sequence, output the final state
   A sequence contains only four possible moves: 
   R: move space right
   L: move space left
   U: move space up
   D: move space down

2. give a valid state and a number n, output all possible states after
   n moves.

3. give a valid state, find a sequence that can move to the initial
   (solved) state

===========
= Stage 1 =
===========

The program's inputs (argv) has three arguments:
"1" means stage 1
a string as a valid state
another string as the move sequence

It is possible that the move sequence will produce an invalid state.
For example, if the input is the initial state and the sequence starts
with D, the result is an invalid state.  Your output should be "I".

Here are some sample outputs:

 > ./pa11 1 123456789AFBDE-C U
123456789A-BDEFC

 > ./pa11 1 123456789AFBDE-C UUU
12-456389A7BDEFC

 > ./pa11 1 123456789AFBDE-C D
I

 > ./pa11 1 123456789AFBDE-C LLUUU
-23416785AFB9DEC

You must test this code yourself, by generating your own test cases,
and running them. You may be helpful to print the puzzle in a 2d
array as you do this. Think about the problem as follows:
(1) Given a board state, what sequences are valid and invalid
(2) Does my program produce exactly the correct states?
(3) Does my program dismiss exactly the expected states.

## A Note about "validity" and "solvability" ##

Stage 1 only tests if a puzzle state is a _legal_ puzzle state. However,
in the 15 puzzle, half the legal states are unreachable from each other!
This fact was exploited by the famous 19th century America puzzle expert
Sam Lloyd, who offered $1000 for the correct solution to "123456789ABCDFE-".
There is no solution, but Lloyd may not have been able to prove it at the 
time. $1000 in 1880 is about $25000 in 2013. See me if you are interested in a
proof for why Lloyd's wager was safe.

Note: In a truly shameless act of self-promotion (probably typical in the 
19th century), Lloyd claimed to have invented the 15-puzzle himself. He did 
not. It first appeared about fifteen years before any of Lloyd's publications.

===========
= Stage 2 =
===========

The program's inputs (argv) has three arguments:
"2" means stage 2
a string as a valid state
a number between 0 and 9 (inclusive)

Your program should generate *unique* states after so many moves.  You
do not need to worry about the order of these states since the states
will be sorted before grading.

You will receive no point if your program prints duplicate states.  One
way to check is to send your program to the sort program in Linux and
then use the uniq program in Linux.  Adding "-d" after uniq will print
duplicates.  This is a way to check.

 > ./pa11 2 state num | sort | uniq -d

Here are some sample outputs:

 > ./pa11 2 123-456789AFBDEC 1
123-456789AFBDEC
12-3456789AFBDEC
1237456-89AFBDEC

 > ./pa11 2 123-456789AFBDEC 2
123-456789AFBDEC
12-3456789AFBDEC
1-23456789AFBDEC
1237456-89AFBDEC
123745-689AFBDEC
1237456F89A-BDEC
126345-789AFBDEC

 > ./pa11 2 123-456789AFBDEC 3
123-456789AFBDEC
12-3456789AFBDEC
1-23456789AFBDEC
-123456789AFBDEC
12-7453689AFBDEC
1237456-89AFBDEC
123745-689AFBDEC
12374-5689AFBDEC
1237456F89A-BDEC
1237456F89-ABDEC
1237456F89ACBDE-
123745A689-FBDEC
126345-789AFBDEC
12634-5789AFBDEC
126345A789-FBDEC
1263457-89AFBDEC
15234-6789AFBDEC


===========
= Stage 3 =
===========

The program's inputs (argv) has two arguments:
"3" means stage 3
a string as a valid state

Your program should generate a sequence that moves the puzzle to the
initial state.  The length of this sequence must be between 1 and 9
(inclusive). 

Below is some sample output:

 > make && ./pa11 3 -23416785ABC9DEF
DDDRRR

Note that a solution could be up to 80 tiles long, which is impossible
to calculate with this approach. So why do it this way? This assignment
is instructive, in that it shows that, in general, brute-force solutions 
work for tiny problems only. Brute force solutions often require more
time and energy to solve than is available in the known universe, and
so knowing _how_ to get a solution is not the same as being _able_ to 
calculate it. This is a major road-block in artificial intelligence.
Russel Norvig's classic book "Artificial Intelligence" has more 
information on how to solve the 15-puzzle.




=========================================

Hint: You should finish the first stage before starting the second
stage; you should finish the second stage before starting the third
stage.

Even though this assignment does not ask you to print the puzzle in
the 2-dimensional view, you should consider to write a function that
converts the 1-dimensional and the 2-dimensional views.  This may help
you visualize and debug.

It is understandable if you want to print debugging messages.
However, please notice that printing a lot of debugging messages can
dramatically slow down your programs.  

For stage 2, your program needs to remember a state and does not have
duplicate states.  You can use a linked list or a binary tree to keep
the states.  The latter is likely to be much faster.

=========================================

This assignment comes with the following files:
+ "README", please read all of this before asking questions.
+ "pa11.c", do not edit this file. (See note below.)
+ "pa11.h", do not edit this header file.
+ "answer11.c", the file you must SUBMIT at the assignment deadline.
+ "tester", a binary (encrypted) file that runs tests on a compiled 
  executable.

You are responsible for testing your code as you write it. The tester
binary will run some tests; however, it is specifically designed to be
too slow to be executed in an edit-compile-test loop. You must set up
this loop yourself. This is EXTREMELY important if you want to learn
how to code faster and more accurately, which is why we do this.

TO TEST YOUR CODE

You should set up your own "main(...)" function, in which you create
data an manipulate it with specific functions. For example, you can
run the "isValidState(...)" function as follows:

int main(int argc, char * * argv)
{
   isValidState("ABCDE");
   return 0;
}





