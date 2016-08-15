var
i,j,k,n,e,m,h,cha,mc:longint;
a:array[1..50] of longint;
f:array[1..50] of longint;
num:array[1..1000] of longint;
begin
assign(input,'ProblemSetter.in');reset(input);
assign(output,'ProblemSetter.out');rewrite(output);
 mc:=2000000000;
 readln(n);
 for i:= 1 to n do
  begin
  read(a[i]);
  end;
 readln;
 for i:= 1 to n do
  for j:= 1 to n do
    for k:= 1 to n do
     if (a[i]<a[j])and(a[j]<a[k]) then
     begin
     cha:=abs((a[j]-a[i])-(a[k]-a[j]));
      if (cha<mc)or((cha=mc)and(i<e))or((cha=mc)and(i=e)and(k>h))or((cha=mc)and(i=e)and(k=h)and(j<m)) then
       begin
        mc:=cha;
        e:=i;
        m:=j;
        h:=k ;
       end;
     end;
 writeln(e,' ',m,' ',h);
 close(input);
 close(output);
end.
