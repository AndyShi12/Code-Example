% Gather IBM Data
%%%%%%%%%%%%%%%%%%%%
conn = yahoo; %connect to Yahoo
name='IBM';
begindate = '2-january-2014';
enddate = '14-may-2014';
data1 = fetch(conn,name,{'High','Low','Close'},begindate,enddate);% downloading data with matlab
data=data1(:,4); % closing prices

%%%%%%%%%%%%%%%%%%%%
% Finding input variables for moving averages
alpha = 1;
lastday = data(end,end);
xBar = mean(data(end,end));
xBar_1 = mean(data(end-1,end));
xBar_2 = mean(data(end-1,end));
numDays = 92

% calculate predicted value and output
xT = alpha * lastday + (1-alpha)*xBar*(numDays - 1)
xT_1 = alpha * xBar_1 + (1-alpha)*xBar_1*(numDays - 2)
xT_2 = alpha * xBar_2 + (1-alpha)*xBar_2*(numDays - 3)
bT = alpha * (xT -  xT_1)  + ((1-alpha) * alpha * (xT_1 - xT_2))

% prediction at day 93
prediction = xT + bT*((1/alpha)+1)
fprintf('prediction')

%fprintf('lastday')
%fprintf('xBar')
%fprintf('xBar_1')
%plot(data)

