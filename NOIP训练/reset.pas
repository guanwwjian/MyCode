var
i,j,k,n,m,z:longint;
a:array[0..20,0..20] of longint;
c:array[0..20] of longint;
s:array[1..100000] of longint;
b:array[0..20000000] of integer;
procedure dfs(x:longint);
 var
i,j,k,tt:longint;
t:array[0..20] of longint;
 begin
  tt:=0;
  for i:= 1 to n do
   tt:=tt*8+c[i];
  if b[tt]=z then exit;
  b[tt]:=z;
  if x>z then
   begin
    for i:= 1 to n do
     if c[i]<>0 then exit;
    for i:= 1 to z do
     write(s[i]);
    writeln;
    close(input);
    close(output);
    halt;
   end
   else
    begin
     t:=c;
     for i:= 0 to m-1 do
      begin
       for j:= 1 to n do
        c[j]:=a[c[j],i];
       s[x]:=i;
       dfs(x+1);
       c:=t;
      end;
    end;
 end;

begin
assign(input,'reset.in');reset(input);
assign(output,'reset.out');rewrite(output);
 readln(n,m);
 for i:= 0 to n-1 do
  begin
  for j:= 0 to m-1 do
   read(a[i,j]);
  readln;
  end;
 z:=0;
 for i:= 1 to n do
  c[i]:=i-1;
 while true do
  begin
   z:=z+1;
   dfs(1);
  end;
close(input);
close(output);
end.
