var
i,j,k,n,m,ans,x,tt:longint;
a:array[1..202] of longint;
f:array[1..202,1..202] of longint;
begin
assign(input,'matrix.in');reset(input);
assign(output,'matrix.out');rewrite(output);
fillchar(f,sizeof(f),120);
 readln(n);
 for i:= 1 to n do
  begin
   readln(a[i],a[i+1]);
   a[i+n]:=a[i];
  end;

for i:= 1 to 2*n do
 begin
  f[i,i]:=0;
  f[i,i+1]:=0;
 end;
 for j:= 1 to 2*n do
  for i:= j downto 1 do
   for k:= i+1 to j-1 do
    begin
    if ((f[i,k]+f[k,j]+a[i]*a[k]*a[j])<f[i,j])or(f[i,j]=0) then  f[i,j]:=f[i,k]+f[k,j]+a[i]*a[k]*a[j];
    end;
 ans:=maxlongint;
 for i:= 1 to n do
  begin
  tt:=a[i]*a[i+n-1]*a[i];
  if a[i+n-1]*a[i]*a[i+n-1]<tt then tt:=a[i+n-1]*a[i]*a[i+n-1];
  if ans>f[i,i+n-1]+tt then ans:=f[i,i+n-1]+tt;
  end;
 writeln(ans);
close(input);
close(output);
end.
