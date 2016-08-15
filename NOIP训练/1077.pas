const
px:array[1..4] of longint=(-1,1,0,0);
py:array[1..4] of longint=(0,0,-1,1);
var
i,j,k,n,m,x1,y1,x2,y2,o,xx,yy,l,r,ans:longint;
b,v:array[1..100,1..100] of boolean;
x,y,t:array[1..100000] of longint;
begin
 readln(n,m,x1,y1,x2,y2,o);
 for i:= 1 to o do
  begin
   readln(xx,yy);
   for j:= xx-1 to xx+1 do
    for k:= yy-1 to yy+1 do
     begin
      b[j,k]:=true;
     end;
  end;
 l:=1;r:=1;
 x[1]:=x1;y[1]:=y1;t[1]:=0;
 ans:=0;
 while l<=r do
  if (not(b[x[l],y[l]]))and(not(v[x[l],y[l]])) then
   begin
    v[x[l],y[l]]:=true;
    if (x[l]=x2)and(y[l]=y2) then
     begin
      ans:=t[l];
      break;
     end;
    for i:= 1 to 4 do
     if (x[l]+px[i]<=n)and(x[l]+px[i]>=1)and(y[l]+py[i]<=m)and(y[l]+py[i]>=1) then
      begin
       inc(r);
       x[r]:=x[l]+px[i];
       y[r]:=y[l]+py[i];
       t[r]:=t[l]+1;
      end;
    inc(l);
   end
  else inc(l);
 writeln(ans);
 end.
