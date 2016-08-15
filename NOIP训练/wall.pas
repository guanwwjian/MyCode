
const
yu=10000;
var
i,j,k,n,m,tt:longint;
f:array[-1..1000000,-2..2] of longint;
flag:boolean;
begin
assign(input,'wall.in');reset(input);
assign(output,'wall.out');rewrite(output);
 readln(n);
 f[0,0]:=1;
 for i:= 1 to n do
  begin
   f[i,-2]:=f[i-2,0];
   f[i,-1]:=f[i-2,0]+f[i-2,1];
   f[i,0]:=f[i-1,0]+f[i,-2]+f[i-1,-1]+f[i-2,1];
   f[i,1]:=f[i,-1]+f[i-1,0];
   f[i,2]:=f[i,0];
   for j:= -2 to 2 do
    begin
     if (f[i,j] div yu)>0 then flag:=true;
     f[i,j]:=f[i,j] mod yu;
    end;
  end;
 if flag then
  begin
   tt:=f[n,0];
   j:=0;
   repeat
     tt:=tt div 10;
     inc(j);
   until tt=0;
  for i:= 1 to 4-j do
   write('0');
  writeln(f[n,0])
  end
 else writeln(f[n,0]);
close(input);
close(output);
end.