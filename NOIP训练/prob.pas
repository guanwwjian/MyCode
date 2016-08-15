var
i,j,k,n,m,x,y,fx,fy,z,ans:longint;
{a:array[1..100,1..100] of longint;}
f,g,s,d:array[1..200] of longint;
a,b:array[1..200] of longint;
flag:boolean;
function find(x:longint):longint;
var
fx:longint;
 begin
  if f[x]=x then exit(x)
   else
    begin
     fx:=find(f[x]);
     g[x]:=(g[x]+g[f[x]]) mod 2;
     f[x]:=fx;
     exit(f[x]);
    end;
 end;
procedure he(x,y:longint);
 var
 i,j,fx,fy:longint;
 begin
  fx:=find(x);fy:=find(y);
  f[fx]:=fy;
  g[fx]:=(g[x]+g[y]+1) mod 2;
 end;
procedure dfs(wei,cha:longint);
 begin
  if wei>z then
   begin
    if cha=0 then inc(ans);
   end
   else
    begin
     dfs(wei+1,cha+a[wei]-b[wei]);
     dfs(wei+1,cha-a[wei]+b[wei]);
    end;
 end;
begin
assign(input,'prob.in');reset(input);
assign(output,'prob.out');rewrite(output);
 readln(n,m);
 for i:= 1 to 2*n do
  begin
   f[i]:=i;
   s[i]:=0;
   d[i]:=0;
   g[i]:=0;
  end;
{ for i:= 1 to n do
  for j:= 1 to n do
   a[i,j]:=1;
 for i:= 1 to n do
  a[i,i]:=0;}
 flag:=true;ans:=0;
 for i:= 1 to m do
  begin
   readln(x,y);
   fx:=find(x);fy:=find(y);
   if fx<>fy then he(x,y)
    else if g[x]=g[y] then flag:=false;
  end;
 if flag then
 begin
 z:=0;
 for i:= 1 to 2*n do
  begin
   fx:=find(i);
   if g[i]=1 then inc(d[fx])
    else inc(s[fx]);
  end;
 for i:= 1 to 2*n do
  begin
   if s[i]>0 then
    begin
     z:=z+1;
     a[z]:=s[i];
     b[z]:=d[i];
    end;
  end;
 dfs(1,0);
 end;
 writeln(ans);

close(input);
close(output);
end.
