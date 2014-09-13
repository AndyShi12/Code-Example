%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  ENGR 19500 Fall 2012
%  Programmer(s) and Purdue Email Address(es):
%  Name Andy Shi
%  shi110@purdue.edu
%
%  Team #:  15
%
%  Assignment #: HW #5, Problem 4
%
%  Academic Integrity Statement:
%
%       I/we have not used source code obtained from
%       any other unauthorized source, either modified
%       or unmodified.  Neither have I/we provided access
%       to my/our code to another. The project I/we am/are submitting
%       is my/our own original work.
%
%  Program Description: Determine the correct phases that may exists for an eutectic phase diagram given %B and temperature. 
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% --- INPUTS ---           
    B=60;
    T=380;
    % If a point falls on a line, the phase stage would be always be set
    % below the line.
    
% --- CALCULATIONS ---
    if (B>=0)&(B<=100)&(T<610)  % check if the variables fit the conditions     
    % ------------ Conditions for the first 10%
        if (B<=10)&(T<=((325/10)*B))
            phase='alpha + beta';
        elseif (B<=10) & (T>((325/10)*B))& (T <= 610 - ((325-610)/10)*B )
            phase='alpha';
        elseif (B<=10) & (T > 610 - ((325-610)/10)*B ) & (T <= 610 - ((325-610)/40)*B )
            phase='alpha+liquid';
        elseif (B<=10)&(T > 610 - ((325-610)/40)*B )
            phase='liquid';
        elseif (B==10)&(T==325)
            phase='eutectic line';
            
    % ------------ Conditions for the 10%-40%         
        elseif (B>10)&(B<40)&(T<325)
            phase='alpha + beta';
        elseif (B>10)&(B<40)&(T>325)&     (T <= 610 - ((325-610)/40)*B )
            phase='alpha + liquid';
        elseif (B>10)&(B<40)&             (T > 610 - ((325-610)/40)*B )
            phase='liquid'
        elseif (B>10)&(B<40)&(T==325)
            phase='eutectic line'
    % ------------ Conditions for the 40%-85%
    
        elseif (B>40)&(B<=85)&(T<325)
            phase='beta + beta';
        elseif (B>40)&(B<=85)&(T>325)&    (T < 325 + ((695-325)/60)*(B-40))  
            phase='beta + liquid';
        elseif (B>40)&(B<=85)&             (T > 325 + ((695-325)/60)*(B-40)) 
            phase='liquid'
        elseif (B>40)&(B<=85)&(T==325)
            phase='eutectic line'
            
   % ------------ Conditions for last 15%
   
        elseif (B>85)&    (T<=(325-((-325/15)*B-85)))
            phase='alpha + beta';
        elseif (B>85) & (T >(325-((-325/15)*B-85))) & (T <= 325 + ((695-325)/15)*(B-85))
            phase='beta';
        elseif (B>85) & (T > 325 + ((695-325)/15)*(B-85)) & (T <= 325 + ((695-325)/60)*(B-85))
            phase='beta + liquid';
        elseif (B>85) & (T > 325 + ((695-325)/60)*(B-85))
            phase='liquid';
        elseif (B==85)&(T==325)
            phase='eutectic line';
            
    % ------------ Conditions at the 40 mass percent point     
        elseif (B==40) & (T>325)
            phase='liquid';
        elseif (B==40) & (T<325)
            phase='alpha + beta';
        else (B==40) & (T==325);
            phase='eutectic point';
        end
    else %if comditions are not met, display error.
        display('Incorrect conditions, check 0%<B%<100% and T>=0°.');
    end
    
% --- OUTPUTS ----
if (B>=0)&(B<=100)&(T>=0)
    fprintf('For %2.1f mass %% B at %3.1f° C, the phase is %s. \n \n' ,B,T, phase);
end

% 325 °C, 40% B     For 40.0 mass % B at 325.0° C, the phase is eutectic point.
% 380 °C, 60% B     For 60.0 mass % B at 380.0° C, the phase is beta + liquid. 
% 370 °C, 40% B     For 40.0 mass % B at 370.0° C, the phase is liquid. 
% 100 °C, 105% B    Incorrect conditions, check 0%<B%<100% and T>=0°.