var
i,j,k,n,m,ans:longint;
a:array[1..300,1..300] of longint;
f:array[0..300,0..300] of longint;
begin
assign(input,'rhombus.in');reset(input);
assign(output,'rhombus.out');rewrite(output);
 readln(n);
 for i:= 1 to n+1 do
  begin
  for j:= 1 to i do
   read(a[i,j]);
  readln;
  end;
 for i:= n+2 to 2*n+1 do
  begin
   for j:= 1 to 2*n+2-i do
    read(a[i,j]);
   readln;
  end;
 f[1,1]:=a[1,1];
 for i:= 2 to n+1 do
  begin
   for j:= 1 to i do
    begin
     f[i,j]:=maxlongint;
     if (j-1)>0 then
      if f[i,j]>f[i-1,j-1]+a[i,j] then f[i,j]:=f[i-1,j-1]+a[i,j];
     if (j<=i-1) then
      if f[i,j]>f[i-1,j]+a[i,j] then f[i,j]:=f[i-1,j]+a[i,j];
    end;
  end;
 for i:= n+2 to 2*n+1 do
  for j:= 1 to 2*n+2-i do
   begin
    f[i,j]:=f[i-1,j]+a[i,j];
    if f[i,j]>f[i-1,j+1]+a[i,j] then f[i,j]:=f[i-1,j+1]+a[i,j];
   end;
  ans:=f[2*n+1,1];
 writeln(ans);
close(input);
close(output);
end.
