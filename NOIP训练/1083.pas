var
i,j,k,n,m,ans,tt:longint;
begin
 readln(n);
 ans:=0;
 for i:= 1 to n do
  begin
   read(tt);
   ans:=ans xor tt
  end;
 readln;

 writeln(ans);

end.