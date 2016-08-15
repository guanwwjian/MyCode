var
i,j,k,n:longint;
f:array[0..100000] of longint;
begin
assign(input,'count.in');reset(input);
assign(output,'count.out');rewrite(output);
 readln(n);
 for i:= 1 to n do
  f[i]:=1;
 for i:= 1 to {n}(n+1) div 2 do
  begin
  for j:= 1 to {i div 2}i do
   f[2*i]:=f[2*i]+f[j];
  f[2*i+1]:=f[2*i];
  end;
 writeln(f[n]);
close(input);
close(output);
end.
