var
i,j,k,n,m,p,x,y,z,zg,zt,ig,it,cg,ct:longint;
g,t:array[1..100] of longint;
a:array[1..100] of longint;
b:array[1..100] of longint;
ans:array[1..100] of longint;
con:array[1..100] of longint;
bb:array[1..100] of boolean;
procedure qsort(l,r:longint);
 var
 i,j,mid,x,tt:longint;
 begin
  i:=l;j:=r;
  mid:=random(r-l+1)+l;
  x:=a[mid];
  repeat
   while a[i]<x do inc(i);
   while x<a[j] do dec(j);
   if i<=j then
    begin
     tt:=a[i];a[i]:=a[j];a[j]:=tt;
     tt:=b[i];b[i]:=b[j];b[j]:=tt;
     inc(i);
     dec(j);
    end;
  until j<i;
  if l<j then qsort(l,j);
  if i<r then qsort(i,r);
 end;
begin
assign(input,'Playlist.in');reset(input);
assign(output,'Playlist.out');rewrite(output);
  readln(n);
  read(k);
  for i:= 1 to k do
   begin
    read(x);
    bb[x]:=true;
   end;
  readln;
  read(p);
  for i:= 1 to p do
   begin
    read(x);
    inc(a[x]);
   end;
  for i:= 1 to n do
   b[i]:=i;
  qsort(1,n);
  for i:= 1 to n do
   con[b[i]]:=n-i+1;
  z:=n;
  zg:=0;zt:=0;cg:=0;
  for i:= 1 to n do
   if bb[i] then
    begin
     zg:=zg+1;
     g[zg]:=i;
     cg:=cg+1;
    end
    else
    begin
     zt:=zt+1;
     t[zt]:=i
    end;
  ig:=1;it:=1;
 for i:= 1 to n do
  if con[i]<=cg then
   begin
    ans[i]:=g[ig];
    ig:=ig+1;
   end
  else
   begin
    ans[i]:=t[it];
    it:=it+1;
   end;
   write(ans[1]);
  for i:= 2 to n do
   begin
    write(' ',ans[i]);
   end;
  writeln;
close(input);
close(output);
end.
