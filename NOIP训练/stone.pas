var
i,j,k,n,m,l,ans,t:longint;
a:array[1..50] of longint;
b:array[1..10000] of boolean;
f:array[1..10000] of longint;
function ff(x:longint):longint;
 var
 i,j:longint;
 flag:boolean;
 begin
 if f[x]<>0 then exit(f[x])
  else
   begin
   b[x]:=true;
   flag:=true;
   for i:= 1 to k do
   if x-a[i]>0 then
    begin
    if (ff(x-a[i])=-1) then f[x]:=1;
    if (ff(x-a[i])<>1) then flag:=false
    end;
    if flag then f[x]:=-1;
    exit(f[x]);
   end;
 end;
begin
assign(input,'stone.in');reset(input);
assign(output,'stone.out');rewrite(output);
 readln(t);
 for l:= 1 to t do
  begin
   readln(n,k);
   for i:= 1 to k do
    read(a[i]);
   readln;
   for i:= 1 to k do
    f[a[i]]:=1;
   if ff(n)=1 then writeln('win')
    else writeln('lose');
  end;

close(input);
close(output);
end.
