var
i,j,k,n,m,f,l,ans,tt:longint;
function yue(x,y:longint):longint;
 var
 i,j,k:longint;
 begin
 if y=0 then exit(x)
  else exit(yue(y,x mod y));
 end;
function bei(x,y:longint):longint;
 begin
  exit(x*y div yue(x,y));
 end;
begin
assign(input,'lcm.in');reset(input);
assign(output,'lcm.out');rewrite(output);
 readln(f,l);
 ans:=1;
 for i:= f to l do
 ans:=bei(ans,i);
 writeln(ans);
close(input);
close(output);
end.
