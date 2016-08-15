const
t:array[1..13] of char=('0','1','2','3','4','5','6','7','8','9','+','-','*');
var
i,j,k,n,m,l,s:longint;
a:array[1..100] of longint;
b,e:array['a'..'z'] of longint;
c,d:array[1..100] of char;
st,an:string;
begin
assign(input,'expression.in');reset(input);
assign(output,'expression.out');rewrite(output);
 readln(st);
 n:=length(st);
 an:=an+'1';
 an:=an+'=';
 an:=an+'1';
 for i:= 1 to n-3 do
  if i mod 2=1 then an:=an+'*'
   else an:=an+'1';
close(input);
close(output);
end.