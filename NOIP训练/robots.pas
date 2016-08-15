const
mi:array[1..2] of longint=(1,0);
mj:array[1..2] of longint=(0,1);
var
i,j,k,n,m,fx,fy,ans:longint;
f,g:array[1..50,1..50] of longint;
c:array[1..50,1..50] of char;
function find(x:longint):longint;
var
 i,j:longint;
 begin
  i:=x div 100;
  j:= x mod 100;
  if f[i,j]=i*100+j then exit(i*100+j)
   else
    begin
     f[i,j]:=find(f[i,j]);
    exit(f[i,j]);
    end;
 end;
begin
assign(input,'robots.in');reset(input);
assign(output,'robots.out');rewrite(output);
 readln(n,m);
 for i:= 1 to n do
  for j:= 1 to m do
   begin
    f[i,j]:=i*100+j;
    g[i,j]:=0;
   end;
 for i:= 1 to n do
  begin
  for j:= 1 to m do
   begin
    read(c[i,j]);
    if c[i,j]='R' then g[i,j]:=1;
   end;
   readln;
  end;
 for i:= 1 to n do
  for j:= 1 to m do
  if c[i,j]<>'#' then
   begin
    for k:= 1 to 2 do
    if ((i-mi[k])>0)and((j-mj[k])>0) then
     if c[i-mi[k],j-mj[k]]<>'#' then
      begin
       fx:=find(i*100+j);fy:=find((i-mi[k])*100+j-mj[k]);
       g[fx div 100,fx mod 100]:=g[fx div 100,fx mod 100]+g[fy div 100,fy mod 100];
       g[fy div 100,fy mod 100]:=0;
       f[fy div 100,fy mod 100]:=f[fx div 100,fx mod 100];
      end;
   end;
 ans:=-maxlongint;
 for i:= 1 to n do
  for j:= 1 to m do
   begin
    if g[i,j]>ans then ans:=g[i,j];
   end;
 writeln(ans);

close(input);
close(output);
end.
