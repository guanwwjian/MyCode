var
i,j,k,n,m:longint;
f:array[0..1000000] of extended;
begin
assign(input,'LocalMaxima.in');reset(input);
assign(output,'LocalMaxima.out');rewrite(output);
 readln(n);
 f[0]:=0;
 f[1]:=1;
 for i:= 2 to n do
  begin
  f[i]:=2/(2*i);
  for j:= 1 to i do
    f[i]:=f[i]+(f[i-1]+f[i-j])/(2*n);
  end;
  writeln(f[n]:0:8);
close(input);
close(output);
end.
