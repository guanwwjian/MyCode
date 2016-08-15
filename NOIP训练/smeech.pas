var
i,j,k,n,m,tt,ww:longint;
str:string;
p,e1,e2,ans:double;
begin
assign(input,'smeech.in');reset(input);
assign(output,'smeech.out');rewrite(output);
 readln(str);
 if str[1]='(' then
 begin
  str[1]:='0';
  tt:=pos(' ',str);
  val(copy(str,1,tt-1),p);
  delete(str,1,tt);
  tt:=pos(' ',str);
  val(copy(str,1,tt-1),e1);
  delete(str,1,tt);
  tt:=pos(')',str);
  val(copy(str,1,tt-1),e2);
  ans:=p*(e1+e2)+(1-p)*(e1-e2);
 end
  else val(str,ans);
 writeln(ans:0:2);
close(input);
close(output);
end.
