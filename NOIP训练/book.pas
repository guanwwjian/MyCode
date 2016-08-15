var
i,j,k,n,m,ans:longint;
a,s:array[0..100000] of longint;
begin
assign(input,'book.in');reset(input);
assign(output,'book.out');rewrite(output);
 readln(n,m);
 for i:= 1 to n do
  readln(a[i]);
 s[0]:=0;
 for i:= 1 to n do
  s[i]:=s[i-1]+a[i];
 if s[n] mod m=0 then ans:=s[n] div m
  else ans:=s[n] div m+1;
 for i:= 1 to n do
  if a[i]>ans then ans:=a[i];
 writeln(ans);
close(input);
close(output);
end.
