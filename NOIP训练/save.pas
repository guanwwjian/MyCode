var
n,m,sum,now,ans:int64;
i,j,k:longint;
ch:char;
st:string;
s:array[1..5000] of string;
u:array[1..5000] of double;
v:array[1..5000] of int64;
f:array[1..5000] of int64;
procedure qsort(l,r:int64);
 var
 i,j,tt,mid:int64;
 td,x:double;
 ts:string;
 begin
  i:=l;j:=r;
  mid:=random(r-l+1)+l;
  x:=u[mid];
  repeat
   while u[i]<x do inc(i);
   while x<u[j] do dec(j);
   if i<=j then
    begin
     ts:=s[i];s[i]:=s[j];s[j]:=ts;
     td:=u[i];u[i]:=u[j];u[j]:=td;
     tt:=v[i];v[i]:=v[j];v[j]:=tt;
     inc(i);
     dec(j);
    end;
  until j<i;
  if l<j then qsort(l,j);
  if i<r then qsort(i,r);
 end;
begin
randomize;
assign(input,'save.in');reset(input);
assign(output,'save.out');rewrite(output);
 n:=0;
 while not(eof) do
  begin
   inc(n);
   read(v[n],u[n]);
   read(ch);
   readln(s[n]);
  end;
 qsort(1,n);

 for i:= 1 to n do
  begin
   sum:=sum+v[i];
   f[i]:=sum;
  end;
 for i:= 1 to n do
  begin
   if (f[i]<(sum div 2))and(f[i+1]>(sum div 2)) then
    begin
     ans:=i;
     if abs(f[i+1]-(sum div 2))<abs(f[i]-(sum div 2)) then ans:=i+1;
    end;
  end;
writeln(s[ans]);
close(input);
close(output);
end.
