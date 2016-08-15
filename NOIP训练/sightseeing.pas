const
mx:array[1..2] of longint=(1,0);
my:array[1..2] of longint=(0,1);
var
i,j,k,n,m:longint;
a,b:array[1..1000,1..1000] of longint;
f,g:array[1..1000,1..1000] of longint;
ans:real;
begin
assign(input,'sightseeing.in');reset(input);
assign(output,'sightseeing.out');rewrite(output);
fillchar(f,sizeof(f),0);
fillchar(g,sizeof(g),120);
 readln(n,m);
 for i:= 1 to n do
  begin
   for j:= 1 to m do
     read(a[i,j]);
   readln;
  end;

 for i:= 1 to n do
  begin
   for j:= 1 to m do
    read(b[i,j]);
   readln;
  end;
 f[1,1]:=a[1,1];
 g[1,1]:=b[1,1];
 for i:= 1 to n do
  for j:= 1 to m do
   begin
    for k:= 1 to 2 do
     if ((i-mx[k])>0)and((j-my[k])>0) then
      if (f[i,j]/g[i,j])<((f[i-mx[k],j-my[k]]+a[i,j])/(g[i-mx[k],j-my[k]]+b[i,j])) then
       begin
        f[i,j]:=f[i-mx[k],j-my[k]]+a[i,j];
        g[i,j]:=g[i-mx[k],j-my[k]]+b[i,j];
       end;
  end;
 writeln(f[n,m]/g[n,m]:0:5);
 close(input);
 close(output);
end.
