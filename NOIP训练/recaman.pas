var
i,j,k,n:longint;
a:array[0..500000] of longint;
b:array[0..10000000] of boolean;
begin
assign(input,'recaman.in');reset(input);
assign(output,'recaman.out');rewrite(output);
readln(n);
a[0]:=0;
b[0]:=true;
for i:= 1 to n do
 begin
 if a[i-1]-i>0 then
  begin
  if not(b[a[i-1]-i]) then
   begin
   a[i]:=a[i-1]-i;
   b[a[i]]:=true;
   end
   else
   begin
    a[i]:=a[i-1]+i;
    b[a[i]]:=true;
   end;
  end
  else
  begin
    a[i]:=a[i-1]+i;
    b[a[i]]:=true;
   end;
 end;
writeln(a[n]);

close(input);
close(output);
end.
