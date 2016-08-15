var
i,j,k,n,m,x,y:longint;
max:double;
a:array[1..200000] of longint;
begin
assign(input,'function.in');reset(input);
assign(output,'function.out');rewrite(output);
 readln(n);
 for i:= 1 to n do
  readln(a[i]);
 max:=-maxlongint;
 for i:= 1 to n do
  for j:= i+1 to n do
   begin
    if max<(a[j]-a[i])/(j-i) then
     begin
      max:=(a[j]-a[i])/(j-i);
      x:=i;
      y:=j;
     end;
   end;
 writeln(x,' ',y);
close(input);
close(output);
end.
