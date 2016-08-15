var
i,j,k,n,m,tt,z:longint;
a:array[1..20,1..20] of longint;
f,t:array[1..20] of longint;
chr:char;
procedure dfs(x:longint);
var
h,l,i,j,k:longint;
flag:boolean;
 begin
 if x>z then
  begin
   for h:=1 to n do
    if f[h]<=0 then exit;
   for l:= 1 to m do
    if t[l]<=0 then exit;
   writeln(x-1);
   close(input);
   close(output);
   halt;
  end
  else
   begin
  for h:= 1 to n do
   begin
    for i:= 1 to m do
     begin
     a[h,i]:=-a[h,i];
     f[h]:=f[h]+2*a[h,i];
     t[i]:=t[i]+2*a[h,i];
     end;
    dfs(x+1);
    for i:= 1 to m do
    begin
     t[i]:=t[i]-2*a[h,i];
     f[h]:=f[h]-2*a[h,i];
     a[h,i]:=-a[h,i];
    end;
   end;
  for l:= 1 to m do
   begin
    for i:= 1 to n do
     begin
      a[i,l]:=-a[i,l];
      f[i]:=f[i]+2*a[i,l];
      t[l]:=t[l]+2*a[i,l];
     end;
     dfs(x+1);
    for i:= 1 to n do
     begin
      t[l]:=t[l]-2*a[i,l];
      f[i]:=f[i]-2*a[i,l];
      a[i,l]:=-a[i,l];
     end;
   end;
  end;
 end;
begin
assign(input,'array.in');reset(input);
assign(output,'array.out');rewrite(output);
 readln(n,m);
 for i:= 1 to n do
  begin
   for j:= 1 to m do
   begin
    read(chr);
    if (chr>='0')and(chr<='9') then tt:=ord(chr)-ord('0')
     else if (chr>='a')and(chr<='z') then tt:=ord(chr)-ord('a')+10
      else if (chr>='A')and(chr<='Z') then tt:=-(ord(chr)-ord('A')+1);
    a[i,j]:=tt;
    f[i]:=f[i]+a[i,j];
    t[j]:=t[j]+a[i,j];
   end;
   readln;
  end;
  z:=0;
 while true do
  begin
   z:=z+1;
   dfs(1);
  end;

close(input);
close(output);
end.
