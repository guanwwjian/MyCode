program rook2;
var
i,j,k,n,m,tt:longint;
f:array[1..50,1..50] of int64;
ans:int64;
tx,ty:array[0..50] of longint;
l,h:array[0..50] of longint;
procedure dfs(wei,x,y:longint);
 var
 i,j:longint;
 begin
  if wei>k then
   begin
    ans:=ans+1;
   end
  else
   begin
    for i:= 1 to n do
     if h[i]>0 then
     for j:= 1 to m do
     if (i-1)*m+j>(x-1)*m+y then
      if l[j]>0 then
      begin
       dec(h[i]);
       dec(l[j]);
       dfs(wei+1,i,j);
       inc(h[i]);
       inc(l[j]);
      end;
   end;
 end;
begin
assign(input,'rook2.in');reset(input);
assign(output,'rook2.out');rewrite(output);
 readln(n,m,k);
 if m<n then
  begin
   tt:=m;
   m:=n;
   n:=tt;
  end;
 for i:= 1 to m do
  l[i]:=2;
 for i:= 1 to n do
  h[i]:=2;
 ans:=0;
 if k<=m*2 then dfs(1,1,0);
 writeln(ans);
close(input);
close(output);
end.

