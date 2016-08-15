const
yu=987654321;
type
ju=array[1..101,1..101] of longint;
var
i,j,k,n,m:longint;
a,b,c:ju;
function cheng(a,b:ju):ju;
 var
 i,j,k:longint;
 c:ju;
 begin
 fillchar(c,sizeof(c),0);
  for i:= 1 to n do
   for j:= 1 to n do
    for k:= 1 to n do
    begin
     c[i,j]:=(c[i,j]+a[i,k]*b[k,j]) mod yu;
    end;
  exit(c);
 end;
function mi(x:longint):ju;
 var
 i,j,k:longint;
 tt:ju;
 begin
  if x=1 then exit(b)
  else
   begin
    tt:=mi(x div 2);
    tt:=cheng(tt,tt);
    if (x mod 2)=1 then tt:=cheng(tt,b);
    exit(tt);
   end;
 end;
begin
assign(input,'beans.in');reset(input);
assign(output,'beans.out');rewrite(output);
 readln(n,m);
 for i:= 1 to n do
  read(a[1,i]);
 readln;
 b[1,1]:=1;
 b[1,2]:=1;
 b[n,n-1]:=1;
 for i:= 2 to n-1 do
  begin
   b[i,i-1]:=1;
   b[i,i+1]:=1;
  end;
  if m>0 then c:=cheng(a,mi(m)) else c:=a;
  write(c[1,1]);
 for i:= 2 to n do
  write(' ',c[1,i]);
close(input);
close(output);
end.
