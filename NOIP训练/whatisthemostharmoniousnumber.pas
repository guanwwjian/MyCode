var
i,j,k,n,m,s,tt,x:longint;
a:array[1..200000] of longint;
h:array[1..200000] of longint;
procedure turn(x:longint);
 var
 i,j,k,min,t:longint;
 flag:boolean;
 begin
  while (h[x]<h[x div 2])and(x>1) do
   begin
    tt:=h[x];h[x]:=h[x div 2];h[x div 2]:=tt;
    x:=x div 2;
   end;
  flag:=true;
  while flag do
   begin
    min:=h[x];t:=x;
    if (x*2<=s)and(h[x*2]<min) then
     begin
     t:=x*2;
     min:=h[x*2];
     end;
    if (x*2+1<=s)and(min>h[x*2+1]) then
     begin
      t:=x*2+1;
      min:=h[x*2+1];
     end;
    if min=h[x] then break
     else
      begin
       tt:=h[x];h[x]:=h[t];h[t]:=tt;
       x:=t;
      end;
   end;
 end;
procedure insert(x:longint);
 var
 i,j,k:longint;
 begin
  inc(s);
  h[s]:=x;
  turn(s);
 end;
function print:longint;
var
 tt:longint;
 begin
  writeln(h[1]);
  tt:=h[1];h[1]:=h[s];h[s]:=tt;
  dec(s);
  turn(1);
 end;
begin
assign(input,'whatisthemostharmoniousnumber.in');reset(input);
assign(output,'whatisthemostharmoniousnumber.out');rewrite(output);
  readln(n,m);
  for i:= 1 to n+m do
   begin
    readln(x);
    if x>=0 then insert(x)
     else print;
   end;
close(input);
close(output);
end.
