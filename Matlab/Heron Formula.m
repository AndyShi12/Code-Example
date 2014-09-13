%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  ENGR 19500 Fall 2012
%  Programmer(s) and Purdue Email Address(es):
%  Name Andy Shi
%  shi110@purdue.edu
%
%  Team #:  15
%
%  Assignment #: HW #5, Problem 3
%
%  Academic Integrity Statement:
%
%       I/we have not used source code obtained from
%       any other unauthorized source, either modified
%       or unmodified.  Neither have I/we provided access
%       to my/our code to another. The project I/we am/are submitting
%       is my/our own original work.
%
%  Program Description: The area of a triangle can be calculated from the lengths of the three sides using
%  Heron's formula 
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% --- INPUTS ---                input for sides of a triangle
a = 200;
b = 75;
c = -250;
s =(a+b+c)/2;                   % s variable for Heron's formula
% --- CALCULATIONS ---

if (a>=0) & (b>=0) & (c>=0)     % if all sides are positive
    area= sqrt( s*(s-a)*(s-b)*(s-c) );  % heron's forumla
else
    answ='All sides must be positive.';  % stops the script, negative side
end

if (a>=0) & (b>=0) & (c>=0)                   % is all sides are positive, print answer
fprintf('The area of this triangle is %5.5f units^2 \n\n' ,area); % output area
else
    fprintf('%s \n \n',answ);                            % output error
end

% --- OUTPUTS ----
% a=10, b=15, c=7       area = The area of this triangle is 29.39388 units^2 
% a=6, b=8, c=-3        area = All sides must be positive.
% a=200, b=75, c=250    area = The area of this triangle is 6200.97964 units^2 