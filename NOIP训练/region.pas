const
x:array[1..4] of longint=(-1,0,0,1);
y:array[1..4] of longint=(0,-1,1,0);
var
i,j,k,n,m,tt,tx,ty,s,tf:longint;
sc:char;
f:array[1..100100] of longint;
a:array[1..100,1..100] of longint;
b:array[1..100100] of boolean;
c:array[1..100100] of char;
function find(x:longint):longint;
 begin
  if f[x]=x then exit(x)
   else
    begin
     f[x]:=find(f[x]);
     exit(f[x]);
    end;
 end;
begin
 assign(input,'region.in');reset(input);
 assign(output,'region.out');rewrite(output);
 readln(n,m);
 for i:= 1 to 100100 do
  f[i]:=i;
 for i:= 1 to n do
  begin
   for j:= 1 to m do
    read(a[i,j]);
   readln;
  end;
 for i:= 1 to n do
  for j:= 1 to m do
  begin
   tt:=a[i,j];
   for k:= 1 to 4 do
    if (i+x[k]>=1)and(i+x[k]<=n)and(j+y[k]>=1)and(j+y[k]<=n) then
      if a[i+x[k],j+y[k]]<tt then
       begin
        tt:=a[i+x[k],j+y[k]];
        tx:=i+x[k];
        ty:=j+y[k];
       end;
   if tt<>a[i,j] then
    begin
     f[find(tx*1000+ty)]:=find(i*1000+j);
    end;
  end;
  sc:=chr(ord('a')-1);
 for i:= 2 to n+m do
  for j:= 1 to i-1 do
   if (j>=1)and(j<=n)and((i-j)>=1)and((i-j)<=m) then
   begin
    tf:=find(j*1000+(i-j));
    if not(b[tf]) then
     begin
      b[tf]:=true;
      inc(sc);
      c[tf]:=sc;
     end;
   end;
 for i:= 1 to n do
  begin
  write(c[find(i*1000+1)]);
  for j:= 2 to m do
    write(' ',c[find(i*1000+j)]);
  writeln;
  end;
 close(input);
 close(output);
end.
