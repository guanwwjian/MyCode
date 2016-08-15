var
i,j,k,n,m,ans:longint;
a:array[1..100] of longint;
f,g:array[1..100] of longint;
begin
 readln(n);
 for i:= 1 to n do
  read(a[i]);
 readln;
 ans:=0;
 for i:= 1 to n do
  begin
  f[i]:=1;
   for j:= 1 to i-1 do
   begin
   if (a[j]<a[i])and(f[i]<f[j]+1) then f[i]:=f[j]+1;
   end;
 end;
 for i:= n downto 1 do
  begin
   g[i]:=1;
   for j:= n downto i+1 do
    if (a[j]<a[i])and(g[i]<g[j]+1) then g[i]:=g[j]+1;
  end;
 for i:= 1 to n do
  if g[i]+f[i]-1>ans then ans:=g[i]+f[i]-1;
 ans:=n-ans;
 writeln(ans);
end.
