var
i,j,k,m,n,tt,x,s,now,ans:longint;
{a:array[1..300] of longint;}
b:array[1..300] of boolean;
begin
assign(input,'disk.in');reset(input);
assign(output,'disk.out');rewrite(output);
 readln(n,k);
  for i:= 1 to n do
   begin
    read(x);
    b[x]:=true;
    b[100+x]:=true;
    b[200+x]:=true;
   end;
 {for i:= 1 to 3*n do
   for j:= i+1 to 3*n do
    if a[i]>a[j] then
    begin
     tt:=a[i];a[i]:=a[j];a[j]:=tt;
    end;}
  s:=n;
  now:=k+100;
  while s>0 do
   begin
    for i:= now to 300 do
     if b[i] then break;
    for j:= now downto 1 do
     if b[j] then break;
    if abs(now-j)<abs(now-i) then i:=j;
    ans:=ans+abs(now-i);
    s:=s-1;
    b[i mod 100]:=false;b[i mod 100+100]:=false;
    b[i mod 100+200]:=false;
    now:=i;
   end;
 writeln(ans);
close(input);
close(output);
end.
