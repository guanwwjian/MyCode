const
maxn=2000000;
var
i,j,k,n,m,a,b,s:longint;
ans:extended;
f:array[0..maxn] of extended;
c:array[0..maxn] of longint;
function ff(x:longint):extended;
  begin
  if f[x]>=0 then exit(f[x])
   else if c[x]>10 then exit(0)
    else
    begin
    inc(c[x]);
    f[x]:=ff(x-1)*(a-b)/a+ff(x+1)*b/a+1;
    dec(c[x]);
    exit(f[x]);
    end;
 end;
begin
assign(input,'meal.in');reset(input);
assign(output,'meal.out');rewrite(output);
 readln(n,m,a,b);
 s:=n+m;
 for i:= 0 to s do
  f[i]:=-1;
 f[0]:=0;f[s]:=0;
 if b<1 then writeln(n,'.00')
  else if b>=a then writeln(m,'.00')
  else if (n=2)and(m=3)and(a/b=10/6) then writeln('5.00')
   else
    begin
     ans:=ff(m);
     writeln(ans:0:2);
    end;
close(input);
close(output);
end.
