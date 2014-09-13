function [rsq] = rsquared_shi110(x,y,slope,yint)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
%  ENGR 19500 Fall 2012
%  Programmer(s) and Purdue Email Address(es):
%  1. Andy Shi shi110@purdue.edu
%
%  Section #: 1     Team #: 15
%
%  Assignment #: Homework #10, Problem 4
%
%  Academic Integrity Statement:
%
%       I/We have not used source code obtained from
%       any other unauthorized source, either modified
%       or unmodified.  Neither have I/we provided access
%       to my/our code to another. The project I/we am/are 
%       submitting is my/our own original work.
%
%  Name of Function:rsquared_shi110
%
%  Inputs and Outputs (list and comment one per line):
%  1. x -> x vector 
%  2. y -> y vector
%  3. slope
%  4. yint -> y intercept
%  5. rsq -> r square value
%
%  Function Description: Find the value of r^2 given x,y,m,b
%  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

SSE=sum((y-(x.*slope)+yint).^2); % equation for SSE
SST=sum((y-(mean(y))).^2);       % equation for SST
r_sq = 1-(SSE./SST)              % r^2
return

% rsquared_shi110([1 3 5 7 9],[0.5 2.5 2 4 3.5],0.5,0)
% 
% r_sq =
% 
%     0.6667
