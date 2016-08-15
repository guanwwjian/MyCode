var
i,j,k,n,m,o,ans,l,r:longint;
flag:boolean;
f:array[1..1000] of longint;
v:array[1..1000] of boolean;
a,b,c:array[1..10000] of longint;
li:array[1..1000,1..1000] of longint;
s:array[1..1000] of longint;
d,e:array[1..20000] of longint;
procedure qsort(l,r:longint);
 var
 i,j,tt,x,mid:longint;
 begin
  i:=l;j:=r;
  mid:=random(r-l+1)+l;
  x:=c[mid];
  repeat
   while c[i]<x do inc(i);
   while x<c[j] do dec(j);
   if i<=j then
    begin
     tt:=a[i];a[i]:=a[j];a[j]:=tt;
     tt:=b[i];b[i]:=b[j];b[j]:=tt;
     tt:=c[i];c[i]:=c[j];c[j]:=tt;
     inc(i);
     dec(j);
    end;
  until j<i;
  if l<j then qsort(l,j);
  if i<r then qsort(i,r);
 end;
function find(x:longint):longint;
 begin
  if f[x]=x then exit(x)
   else
    begin
     f[x]:=find(f[x]);
     exit(f[x]);
    end;
 end;
function bfs(x,y:longint):boolean;
 var
 i,j,k:longint;
 begin
  l:=1;r:=1;
  d[1]:=x;
  e[1]:=0;
  while l<=r do
   begin
    if e[l]>k then exit(false);
    if find(d[l])=find(n) then exit(true);
    for i:= 1 to s[d[l]] do
      begin
       inc(r);
       d[r]:=li[d[l],i];
       e[r]:=e[l]+1;
      end;
   end;

 end;
begin
randomize;
assign(input,'phone.in');reset(input);
assign(output,'phone.out');rewrite(output);
 readln(n,m,o);
 for i:= 1 to n do
  f[i]:=i;
 for i:= 1 to m do
  begin
  readln(a[i],b[i],c[i]);
  inc(s[a[i]]);
  li[a[i],s[a[i]]]:=b[i];
  inc(s[b[i]]);
  li[a[i],s[b[i]]]:=a[i];
  end;
 qsort(1,m);
 ans:=-1;
 if bfs(1,k) then ans:=0
  else
   begin
    for i:= 1 to m do
     begin
      f[find(a[i])]:=f[find(b[i])];
      for j:= 1 to n do
       if bfs(j,k) then
        begin
         ans:=c[i];
         flag:=true;
         break;
        end;
      if flag then break;
     end;
  end;
 writeln(ans);

close(input);
close(output);
end.