%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  ENGR 19500 Fall 2012
%  Programmer(s) and Purdue Email Address(es):
%  Name Andy Shi
%  shi110@purdue.edu
%
%  Team #:  15
%
%  Assignment #: HW04, Problem 6
%
%  Academic Integrity Statement:
%
%       I/we have not used source code obtained from
%       any other unauthorized source, either modified
%       or unmodified.  Neither have I/we provided access
%       to my/our code to another. The project I/we am/are submitting
%       is my/our own original work.
%
%  Program Description: If a basketball is dropped from a helicopter, its velocity as a function of time v(t)
%  can be modeled by the equation: v(t)=...PROBLEM 6
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% --- INPUTS ---
clc;

g=9.81; % gravitation constant 9.81 m/s^2
drag=0.5;  % drag coefficient 0.5
drag2=0.3;  % drag coefficient 0.3 of golfball
air=1.2;  % density of air 1.2 kg/m^3
radi =0.117; % radius 0.117m
m = 0.624; %mass of basketball
area0 = pi*radi*radi; % area pi(r^2)
e = 2.71828182846; 
time0 = [0 1 2 3 4 5 6 7 8 9 10]; %time in seconds

% --- CALCULATIONS ---
velocityB = sqrt((2*m*g)/(air*area0*drag))*(1-e.^(-time0*sqrt((air*g*drag*area0)/(2*m))));
velocityG = sqrt((2*m*g)/(air*area0*drag2))*(1-e.^(-time0*sqrt((air*g*drag2*area0)/(2*m))));
% --- OUTPUTS ----
display(velocityB);
plot(time0, velocityB);
ylabel('Velocity (m/s)');
xlabel('Time (s)');
title('Velocity of Basketball/Golfball Dropped from Helicopter');
hold on;
plot(time0, velocityG,'--');
legend('Basketball','Golfball');
