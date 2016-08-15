const
maxn=100000;
maxt=10000000;
var
i,j,k,n,x,y,p,ans1,ans2:longint;
xx,yy:array[1..maxn] of longint;
ru,chu:array[1..maxt] of longint;
procedure qsort(l,r:longint);
 var
 i,j,x,mid,tt:longint;
 begin
  i:=l;j:=r;
  mid:=random(r-l+1)+l;
  x:=xx[mid];
  repeat
   while xx[i]<x do inc(i);
   while x<xx[j] do dec(j);
   if i<=j then
    begin
     tt:=xx[i];xx[i]:=xx[j];xx[j]:=tt;
     tt:=yy[i];yy[i]:=yy[j];yy[j]:=tt;
     inc(i);
     dec(j);
    end;

  until j<i;
  if l<j then qsort(l,j);
  if i<r then qsort(i,r);
 end;

begin
assign(input,'examtime.in');reset(input);
assign(output,'examtime.out');rewrite(output);
 readln(x,y);
 readln(n);
 for i:= 1 to n do
  begin
   readln(xx[i],yy[i]);
   inc(ru[xx[i]]);
   inc(chu[yy[i]]);
  end;
 p:=0;ans1:=2000000000;ans2:=0;
 for i:= x to y do
  begin
  p:=p+ru[i];
  if ans2<p then ans2:=p;
  if ans1>p then ans1:=p;
  p:=p-chu[i];
  end;
writeln(ans1,' ',ans2);
close(input);
close(output);
end.
