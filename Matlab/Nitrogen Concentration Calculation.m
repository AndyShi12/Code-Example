%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  ENGR 19500 Fall 2012
%  Programmer(s) and Purdue Email Address(es):
%  Name: Andy Shi - shi110@purdue.edu
%
%  Team #: 15
%
%  Assignment #: HW#10, Problem #3
%
%  Academic Integrity Statement:
%
%       I/we have not used source code obtained from
%       any other unauthorized source, either modified
%       or unmodified.  Neither have I/we provided access
%       to my/our code to another. The project I/we am/are submitting
%       is my/our own original work.
%
% Program Description: As part of an environmental impact study, an agricultural engineer is 
% investigating the nitrogen (N) concentration in the soil around bale feeders used 
% at winter feeding sites for cattle.  Soil samples 15 cm in depth were taken from 
% multiple sites at distances of 3, 12, 21, and 30 m from the feeder.  Use the data 
% file nitrogen.txt to complete this problem.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% --- INPUTS ---
load('nitrogen.txt');   % load data from nitrogen.txt
dist=nitrogen(:,1);     % declare the first column to be the distance
concentration=nitrogen(:,2);    % declare the second column to be the concentration

% --- CALCULATIONS ---
scatter(dist,concentration);    % scatter plot for distance/concentration
hold on;                        % hold the scatter plot
x=polyfit(dist, concentration, 1);  % find the slope and y-int
slope=x(1,1);                      
intecept=x(1,2);                    

% --- OUTPUTS ----
title('Distance vs Concentration');
xlabel('Distance (m)');
ylabel('Concentration of Nitrogen (ppm)');
fprintf('The best fit line is: Nitrogen Concentration = %5.5f * distance + %5.5f\n',slope,intecept);

y=polyval(polyfit(dist,concentration,1),dist);
plot(dist,y,'k-')


% b. The unit for the slope is meters and the unit for the intercept is DM basis in ppm 
% c. The least square regression line is the difference between the average
%     value and the residual value in the scatter plot.
% 9. The r^2 value is the correlation coefficient
% 10. y = -0.6325x + 40.913 ----> 31.4255

