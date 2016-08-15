const
su:array[1..15] of longint=(2,3,5,7,11,13,17,19,23,29,31,37,41,43,47);
var
i,j,k,n,m:longint;
ans:qword;
a:array[1..15] of longint;
procedure dfs(x,now:longint);
 var
 i,j,k:longint;
 tt:qword;
 begin
 if x>m then
  begin
   tt:=1;
   for i:= 1 to m do
    if a[i]<>0 then  tt:=tt*a[i];
   if ans<tt then ans:=tt;
  end
  else
   begin
    a[x]:=0;
    while now+a[x]<=n do
     begin
      if now+a[x]<=n then dfs(x+1,now+a[x]);
      a[x]:=a[x]+su[x];
     end;
   end;
 end;

begin
assign(input,'stones.in');reset(input);
assign(output,'stone.out');rewrite(output);
 readln(n);
 ans:=0;
 for i:= 1 to 15 do
  if su[i]>n then
   begin
    m:=i-1;
    break;
   end;
 dfs(1,0);
writeln(ans);
close(input);
close(output);
end.
