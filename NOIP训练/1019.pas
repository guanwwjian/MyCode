var
i,j,k,n,m,s,ans,tt,min:longint;
a,b,f:array[1..1000] of longint;
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
   if (a[i]<=a[j])and(f[i]<f[j]+1) then f[i]:=f[j]+1;
  if ans<f[i] then ans:=f[i];
  end;
 s:=1;b[1]:=a[1];
 for i:= 2 to n do
  begin
   tt:=0;min:=maxlongint;
   for j:= 1 to s do
    if (b[j]>=a[i])and(b[j]<min) then
     begin
      tt:=j;
      min:=b[j];
     end;
   if tt>0 then b[tt]:=a[i]
    else
     begin
     inc(s);
     b[s]:=a[i];
     end;
  end;
 writeln(ans);
 writeln(s);

end.
