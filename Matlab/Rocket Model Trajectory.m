function [] = model_rocket_shi110(vi, deg)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
%  ENGR 19500 Fall 2012
%  Programmer(s) and Purdue Email Address(es):
%  1. Andy Shi - shi110@purdue.edu
%
%  Section #: 1     Team #: 15
%
%  Assignment #8 Problem 3
%
%  Academic Integrity Statement:
%
%       I/We have not used source code obtained from
%       any other unauthorized source, either modified
%       or unmodified.  Neither have I/we provided access
%       to my/our code to another. The project I/we am/are 
%       submitting is my/our own original work.
%
% FUNCTION NAME model_rocket_shi110
% INPUTS: vi - Initial velocity
%         deg- Degree at which projectile is launched
% OUTPUTS: no variable output, while loop outputs the distance until the
% projectile hits the ground
%          
% Function description: The motion of each rocket can be described using the velocity and the launch
% angle measured from horizontal provided by the professors. The horizontal
% distance (X) and vertical height (Y) of the firework after it has been launched is
% calculated.
%  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

t=0; %initial time
y=1; %initial height
x=0; %initial distance

fprintf('For an initial velocity (m/s) of %3.2f and angle of %3.0f degrees: \n\n', vi, deg);

while (y>=0)
    x=vi*cosd(deg)*t; %calculate x
    y=vi*sind(deg)*t - .5*9.81*t*t; %calculate y
    fprintf('At %1.0f seconds, the height is %3.2f m and the distance is %3.2f m. \n', t, y, x);
    t=t+1; %time counter variable
end %end while

%{ 
For an initial velocity (m/s) of 78.00 and angle of  57 degrees: 

At 0 seconds, the height is 0.00 m and the distance is 0.00 m. 
At 1 seconds, the height is 60.51 m and the distance is 42.48 m. 
At 2 seconds, the height is 111.21 m and the distance is 84.96 m. 
At 3 seconds, the height is 152.10 m and the distance is 127.45 m. 
At 4 seconds, the height is 183.19 m and the distance is 169.93 m. 
At 5 seconds, the height is 204.46 m and the distance is 212.41 m. 
At 6 seconds, the height is 215.92 m and the distance is 254.89 m. 
At 7 seconds, the height is 217.57 m and the distance is 297.37 m. 
At 8 seconds, the height is 209.41 m and the distance is 339.85 m. 
At 9 seconds, the height is 191.44 m and the distance is 382.34 m. 
At 10 seconds, the height is 163.66 m and the distance is 424.82 m. 
At 11 seconds, the height is 126.07 m and the distance is 467.30 m. 
At 12 seconds, the height is 78.68 m and the distance is 509.78 m. 
At 13 seconds, the height is 21.47 m and the distance is 552.26 m. 
%}