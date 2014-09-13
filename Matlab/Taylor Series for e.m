function [e_estimate] = e_estimate_shi110(x, accuracy)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
%  ENGR 19500 Fall 2012
%  Programmer(s) and Purdue Email Address(es):
%  1. Andy Shi - shi110@purdue.edu
%
%  Section #: 1     Team #: 15
%
%  Assignment #8 Problem 4
%
%  Academic Integrity Statement:
%
%       I/We have not used source code obtained from
%       any other unauthorized source, either modified
%       or unmodified.  Neither have I/we provided access
%       to my/our code to another. The project I/we am/are 
%       submitting is my/our own original work.
%
% FUNCTION NAME e_estimate_shi110
% INPUTS: x = e^x
%         accuracy = desired accuracy
% OUTPUTS: the value of the Taylor series approximation for ex
%          
% Function description: The function f(x) = ex can be represented in a Taylor series
%  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
e_act = exp(x);
e_est = 0;
n=0;

if (x<0)
     fprintf('e^%2.2f is %5.5f, Taylor series cannot be used to calculated negative e^x powers \n \n',x, e_act); 
else 
while ((e_act - e_est) > accuracy)
    e_est = e_est + (x^n)./factorial(n)
    n=n+1;
end
fprintf('exp(%2.0f) = %5.5f \n \n', x, e_est);
fprintf('e^%2.2f is %5.5f, Taylor appromixation of the %3.0f order is %5.5f accuracy to %5.5f \n \n',x, e_act, n, e_est, accuracy);
end

% exp(2) = 7.38871 
% exp(-4) = error
% exp(12) = 219695.98865 

% e^2.00 is 7.38906, Taylor appromixation of the 10 order is 7.38871 accuracy to 0.00100 
% e^-4.00 is 0.01832, Taylor series cannot be used to calculated negative e^x powers 
% e^12.30 is 219695.98867, Taylor appromixation of the 41 order is 219695.98865 accuracy to 0.00005
