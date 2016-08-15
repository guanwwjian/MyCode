const
maxn=3000;
{mx:array[1..2] of longint=(0,1);
my:array[1..2] of longint=(1,0);}
var
i,j,k,n,m,ans:longword;
f:array[0..maxn,0..maxn] of longword;
begin
assign(input,'grid.in');reset(input);
assign(output,'grid.out');rewrite(output);
 fillchar(f,sizeof(f),0);
 readln(n,m);
 f[0,0]:=1;
 for i:= 0 to n do
  for j:= 0 to m do
  begin
   if i>=1 then f[i,j]:=f[i,j]+f[i-1,j];
   if j>=1 then f[i,j]:=f[i,j]+f[i,j-1];
  end;
 ans:=f[n,m];
 writeln(ans);
close(input);
close(output);
end.
