var
i,j,k,n,m:longint;
s:double;
begin
 readln(n);
 for i:= 1 to 10000000 do
  begin
  s:=s+1/i;
  if s>n then break;
  end;
 writeln(i);

end.