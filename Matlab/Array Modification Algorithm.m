function [m_array] = array_shi110(vector,val)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
%  ENGR 19500 Fall 2012
%  Programmer(s) and Purdue Email Address(es):
%  1. Name: Andy Shi shi110@purdue.edu
%
%  Section #: 1     Team #: 15
%
%  Assignment #: Homework #9, Problem #4
%
%  Academic Integrity Statement:
%
%       I/We have not used source code obtained from
%       any other unauthorized source, either modified
%       or unmodified.  Neither have I/we provided access
%       to my/our code to another. The project I/we am/are 
%       submitting is my/our own original work.
%
%  Name of Function:
%
%  INPUTS:
%  vector - the NxM array
%  specified_value - test value to modify the vector array
%
%  OUTPUTS:
%  modified_array - modified array
%
%  Function Description: A user wants to modify the elements in an array based upon the following rules:
%    i. Double the value of the element if it is positive and divisible by a user specified value.
%    ii. Square the value of the element if it is negative.
%    iii. Use the original value for the elements that are not modified in steps i. or ii.
%  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

[rlength,clength] = size(vector);        % calculate the dimension 
m_array = zeros(rlength,clength);        % create a modify vector array of 0s (same size)

for row=1:1:rlength; % for loop; row
    for column=1:1:clength;  % for loop; column
        if vector(row,column)>0 && rem(vector(row,column),val)==0; % check if value is greater than 0 and divisible by value; rem = modulus division
            m_array(row,column)=2*vector(row,column); % m_array = value in original is double in new array
        
        elseif vector(row,column)<0; % if vector is negative
            m_array(row,column)=vector(row,column)^2; % modified array element is squared
        else
            m_array(row,column)=vector(row,column); % else element stays the same
        end
    end
end
return

% ---OUTPUTS---
% T = [5, 17, -3, 8, 0, -7, 12], user specified value = 4
% ans =
%      5    17     9    16     0    49    24
%
%
% T = [1 5 3; -2 6 -7; -4 12 24], user specified value = 2
% ans=
%    1     5     3
%    4     12    49
%    16    24    48
%
%
% T = [23 17 -34 66; -4 33 -23 0; 12 7 11 22; -2 0 0 7], user specified value = 11 
% ans=
%          23          17        1156         132
%          16          66         529           0
%          12           7          22          44
%           4           0           0           7
