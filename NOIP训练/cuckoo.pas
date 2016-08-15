var
i,j,k,t,m,n:longint;
h1,h2:array[1..10000] of longint;
begin
assign(input,'cuckoo.in');reset(input);
assign(output,'cuckoo.out');rewrite(output);
 readln(t);
 for i:= 1 to n do
 begin
  readln(m,n);
  for j:= 1 to m do
   readln(h1[j],h2[j]);
  if m<(n div 2) then writeln('successful hashing')
   else writeln('rehash necessary');
 end;
 close(input);
 close(output);
end.
