const
maxl=2000000000;
var
i,j,n,k:longint;
a:array[0..20] of longint;
procedure add;
var
i,j,kk,f,t,tt:longint;
 begin
  f:=0;t:=0;
  a[0]:=maxl;
  for i:= n-1 downto 1 do
   begin
    for j:= i+1 to n do
     begin
      if (a[j]>a[i])and(a[j]<a[f]) then
       begin
        f:=j;
        t:=i;
       end;
     end;
    if f>0 then break;
   end;
  tt:=a[f];
  for i:= f downto t+1 do
   a[i]:=a[i]-1;
  a[t]:=tt;
  for i:= t+1 to n do
   for j:= i+1 to n do
    if a[i]>a[j] then
     begin
      tt:=a[i];a[i]:=a[j];a[j]:=tt;
     end;
  end;
begin
assign(input,'permutation.in');reset(input);
assign(output,'permutation.out');rewrite(output);
 readln(n,k);
 for i:= 1 to n do
  read(a[i]);
 readln;
 for i:= 1 to k do
  add;
  write(a[1]);
 for i:= 2 to n do
  write(' ',a[i]);
 writeln;
close(input);
close(output);
end.
