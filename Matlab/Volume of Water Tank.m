%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  ENGR 19500 Fall 2012
%  Programmer(s) and Purdue Email Address(es):
%  Name Andy Shi
%  shi110@purdue.edu
%
%  Team #:  15
%
%  Assignment #: 5 Problem 2
%
%  Academic Integrity Statement:
%
%       I/we have not used source code obtained from
%       any other unauthorized source, either modified
%       or unmodified.  Neither have I/we provided access
%       to my/our code to another. The project I/we am/are submitting
%       is my/our own original work.
%
%  Program Description: Volume of a water tank
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% --- INPUTS ---
                          % Volume of a cylinder = pi*r^2*h
h = 40;                  % Height of water tank in ft

% --- CALCULATIONS ---
if (h <= 32) & (h>=0)          % If height is greater than 0 and less than or equal to 32
    V = pi * (37/2)^2 * h;  
elseif (h>32) & (h<=54)        % If height is greater than 0 and less than or equal to 32
    V = 32 * (37/2)^2 * pi + (24/2)^2 * pi * (h-32);   
elseif (h>54) & (h<=71)        % If height is greater than 54 and less than or equal to 71
    V = 32 * (37/2)^2 * pi + (24/2)^2 * pi * (h-32) + 17 * (20/2)^2 * (h-54);
else (h>71) & (h<=85)        % If height is greater than 71 and less than or equal to 85
    V = (32 * (37/2)^2 * pi + (24/2)^2 * pi * (h-32) + 17 * (20/2)^2 * (h-54))     +     (1/3 * pi * (h-71) * (10^2 + 10*(10+13/14*(h-71)) + (10+13/14*(h-71))^2));
end

% --- OUTPUTS ----
if (h>=0)&(h<=85)               % if values are in range, run calculation
    fprintf('At height= %3.2f ft, your calculated volume is %5.5f ft^3 \n\n',h,V);
else                           %else print error     
   fprintf('Invalid height! \n\n');
end

% h = 60  57273.62432 ft^3
% h = 54  44359.28827 ft^5
% h = 20  21504.20171 ft^3
% h = 86  Invalid height! 
% h = 40  38025.83748 ft^3