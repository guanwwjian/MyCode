const
px:array[1..6] of longint=(-1,1,0,0,0,0);
py:array[1..6] of longint=(0,0,-1,1,0,0);
pz:array[1..6] of longint=(0,0,0,0,-1,1);
var
i,j,k,l,n,m,x,y,z,ans:longint;
a:array[1..50,1..50,1..50] of longint;
f:array[1..505050] of longint;
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
 for i:= 1 to 505050 do
  f[i]:=i;
 readln(x,y,z);
 readln(m);
 for i:=1 to x do
  for j:= 1 to y do
   for k:= 1 to z do
    begin
     read(a[i,j,k]);
    end;
 ans:=x*y*z;
 for i:=1 to x do
  for j:= 1 to y do
   for k:= 1 to z do
    for l:= 1 to 6 do
     if (i+px[l]>=1)and(i+px[l]<=x)and(j+py[l]>=1)and(j+py[l]<=y)and(k+pz[l]>=1)and(k+pz[l]<=z) then
      begin
       if abs(a[i,j,k]-a[i+px[l],j+py[l],k+pz[l]])<=m then
        begin
         if find(i*10000+j*100+k)<>find((i+px[l])*10000+(j+py[l])*100+k+pz[l]) then
          begin
           dec(ans);
           f[find(i*10000+j*100+k)]:=find((i+px[l])*10000+(j+py[l])*100+k+pz[l]);
          end;
        end;
      end;
 writeln(ans);
end.