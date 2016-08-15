var
i,j,k,ans:longint;
n,m,z:int64;
function yue(x,y:longint):longint;
 begin
  if y=0 then exit(x)
   else exit(yue(y,x mod y));
 end;
begin
 readln(n,m);
 z:=n*m;
 for i:= 1 to trunc(sqrt(z)) do
  if z mod i=0 then
  begin
   j:=z div i;
   if yue(i,j)=n then
     begin
      inc(ans);
      if i<>j then inc(ans);
     end;
  end;
 writeln(ans);

end.
