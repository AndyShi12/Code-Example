% downloading data with matlab
conn = yahoo; %connect to Yahoo
datainfo='BMW.DE',{'High','Low','Close'},'13/01/01','14/01/01');
%data =
%fetch(conn,'BMW.DE',{'High','Low','Close'},'13/01/01','14/01/01');
data=(conn,datainfo)