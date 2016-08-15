var
i,j,k,n,m,s,w,o:longint;
a:array[0..1000000] of longint;
flag:boolean;
procedure dfs(x,y:longint);
 var
 i,j,k,tt:longint;
 tb:boolean;
 begin
  inc(s);
  if (s>=1000000)or flag then exit;
 if x>w then
  begin
  tb:=true;
  tt:=y;
  while tt>0 do
   begin
    if not(((tt mod 10)=0)or((tt mod 10)=1)) then tb:=false;
    tt:=tt div 10;
   end;
  if tb then
   begin
    flag:=true;
    exit;
   end;
  end
  else
  for i:= 0 to 9 do
   begin
    if flag then exit;
    if (x=0)and(i=0) then continue;
    a[x]:=i;
    if (((y+i*n) mod 10)=1)or(((y+i*n)mod 10)=0) then dfs(x+1,(y+i*n) div 10);
    if flag then exit;
   end;
 end;
begin
s:=0;
assign(input,'torch.in');reset(input);
assign(output,'torch.out');rewrite(output);
 readln(n);
 for w:= 1 to 1000000 do
  begin
   dfs(0,0);
   if flag or(s>1000000) then break;
  end;
 if flag then
  begin
  for i:= w downto 0 do
   write(a[i]);
  writeln;
  end
 else writeln('No Solution');

close(input);
close(output);
end.
