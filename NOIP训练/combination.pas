var
i,j,k,n:longint;
a:array[1..1000] of longint;
f:array[0..1000] of longint;
s:array[0..1000,0..1000] of longint;
function su(x:longint):boolean;
var
i,j,k:longint;
flag:boolean;
begin
 flag:=true;
 if x=1 then exit(false);
 i:=2;
  while ((i*i)<=x) do
   begin
    if (x mod i=0) then flag:=false;
    i:=i+1;
   end;
 exit(flag);
end;

begin
assign(input,'combination.in');reset(input);
assign(output,'combination.out');rewrite(output);
 readln(n);
 for i:= 1 to n do
  read(a[i]);
 readln;
 for i:= 1 to n do
  s[i,i]:=a[i];
 for i:= 1 to n do
  for j:= i+1 to n do
  begin
   s[i,j]:=s[i,j-1]+a[j];
  end;
 for i:= 1 to n do
  f[i]:=1;
 for i:= 1 to n do
  for j:= 1 to i-1 do
  if su(s[j,i]) then
   f[i]:=(f[i]+f[j]) mod 987654321;

 writeln(f[n]);
close(input);
close(output);
end.
