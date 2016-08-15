var
i,j,k,n,m,tt,s:longint;
a:array[1..100] of longint;
function magic(x:longint):longint;
 var
 i,j,k,tt,t1,s:longint;
 begin
  s:=0;
  while x>0 do
   begin
    inc(s);
    a[s]:=x mod 10;
    x:=x div 10;
   end;
  tt:=0;
  for i:= s downto 2 do
   begin
    tt:=tt*10+abs(a[i]-a[i-1]);
   end;
  exit(tt);
 end;
function mf(x:longint):longint;
 var
 tt:longint;
 begin
  tt:=x;
  while tt>=10 do
   tt:=magic(tt);
  exit(tt);
 end;
begin
assign(input,'MagicFingerprint.in');reset(input);
assign(output,'MagicFingerprint.out');rewrite(output);
 readln(n,m);
 tt:=m-n;
 if tt<10000000 then
  begin
   s:=0;
   for i:= n to m do
    begin
    if mf(i)=7 then
     begin
      inc(s);
     end;
    end;
   writeln(s);
  end
 else
  begin

  end;

close(input);
close(output);
end.