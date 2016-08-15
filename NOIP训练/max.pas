const
maxn=500000;
var
i,j,k,n,m,a,b,ans:longint;
s:array[0..maxn] of int64;
c:array[0..maxn] of longint;
begin
assign(input,'max.in');reset(input);
assign(output,'max.out');rewrite(output);
fillchar(s,sizeof(s),0);
fillchar(c,sizeof(c),0);
 readln(n,a,b);
 for i:= 1 to n do
  read(c[i]);
 readln;
 s[0]:=0;
 for i:= 1 to n do
  begin
   s[i]:=s[i-1]+c[i];
  end;
 for i:= a to b do
  for j:= 1 to n do
  if (j+i-1)<=n then
   begin
    if ans<(s[j+i-1]-s[j-1]) then
     ans:=(s[j+i-1]-s[j-1]);
   end;
 writeln(ans);
close(input);
close(output);
end.
