var
i,j,k,n,m,l4,l2,t:longint;
a:array[1..30000] of longint;
c:array[0..9] of longint;
d:array[0..9] of longint;
st1,st2,tt:ansistring;
begin
 readln(n,m);
 a[1]:=1;
 l2:=1;l4:=1;
 for i:= 2 to n do
  begin
   if (a[l2]*2+1)>(a[l4]*4+5) then
    begin
     a[i]:=a[l4]*4+5;
     inc(l4);
    end
   else
    begin
     a[i]:=a[l2]*2+1;
     inc(l2);
    end;
  end;
 for i:= 1 to n do
  begin
   str(a[i],tt);
   st1:=st1+tt;
   t:=a[i];
   while t>0 do
    begin
    inc(c[t mod 10]);
    t:=t div 10;
   end;
 end;
st2:=st1;
for i:= 0 to 9 do
 begin
  if c[i]<m then
   begin
    d[i]:=c[i];
    m:=m-c[i];
   end
  else
   begin
    d[i]:=m;
    m:=0;
    break;
   end;
 end;
 i:=1;
 while i<=length(st2) do
  if d[ord(st2[i])-ord('0')]>0 then
  begin
   dec(d[ord(st2[i])-ord('0')]);
   delete(st2,i,1);
  end
 else inc(i);
writeln(st1);
writeln(st2);


end.
