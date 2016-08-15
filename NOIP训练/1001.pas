var
i,j,k,n,m:longint;
s,l,r,x,t1,t2,ans:longint;
a:array[0..100] of longint;
b:array[1..5000000] of longint;
function ma:longint;
 var
 i,j,k:longint;
 tt:longint;
 begin
  while (a[s]=0)and(s<100) do inc(s);
 tt:=s;
 if (s=100)and(a[s]=0) then tt:=maxlongint;
 if l>0 then
  if (b[l]<tt)and(l<r) then
   begin
    tt:=b[l];
    inc(l);
    inc(a[s]);
   end;
  dec(a[s]);
  while (a[s]=0)and(s<100) do inc(s);
  exit(tt);
 end;
begin
 readln(n);
 for i:= 1 to n do
  begin
   read(x);
   inc(a[x]);
  end;
  readln;
  t1:=ma;t2:=ma;
  s:=0;
  l:=1;r:=1;
  b[1]:=t1+t2;
  ans:=t1+t2;
 while not((s=100)and(l=r)) do
  begin
   inc(r);
   t1:=ma;
   t2:=ma;
   b[r]:=t1+t2;
   ans:=ans+t1+t2;
  end;
 writeln(ans);



end.
