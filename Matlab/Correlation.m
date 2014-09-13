%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  ENGR 19500 Fall 2012
%  Programmer(s) and Purdue Email Address(es):
%  Name: Andy Shi shi110@purdue.edu
%
%  Team #: 15 
%
%  Assignment #: Homework #10, Problem 6
%
%  Academic Integrity Statement:
%
%       I/we have not used source code obtained from
%       any other unauthorized source, either modified
%       or unmodified.  Neither have I/we provided access
%       to my/our code to another. The project I/we am/are submitting
%       is my/our own original work.
%
%  Program Description: Plot a scatter plot to find the correlation between
%  resistance and failure time.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% --- INPUTS ---
data=load('resistance.txt')     % load resistance data
resist=data(:,1);               % resistance in ohms
fail_time=data(:,2);            % falure time (min)

% --- CALCULATIONS ---
plot(resist,fail_time,'ko')         % Plot resistance vs failure time
hold on
LSRL=polyfit(resist,fail_time,1);   % Find slope and y-int
y_fit=polyval(LSRL,resist);
plot(resist,y_fit);                 % plot LSRL

% --- OUTPUTS ----
estimated=(LSRL(1)*42)+LSRL(2);
title('Resistance');
xlabel('Resistance (ohms)');
ylabel('Failure Time (min)');
display(estimated);

% actual value = 39
% estiamted value = 37.2718