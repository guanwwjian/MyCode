var
i,j,k,n,m,x1,x2,y1,y2,ans:longint;
ch:char;
b:array[1..50,1..50] of boolean;
begin
assign(input,'circle.in');reset(input);
assign(output,'circle.out');rewrite(output);
 readln(n,m);
 x1:=maxlongint;
 x2:=-maxlongint;
 y1:=maxlongint;
 y2:=-maxlongint;
 for i:= 1 to n do
  begin
  for j:= 1 to m do
   begin
    read(ch);
    if ch='.' then
     begin
      b[i,j]:=true;
      if i<x1 then x1:=i;
      if i>x2 then x2:=i;
      if j<y1 then y1:=j;
      if j>y2 then y2:=j;
     end
     else b[i,j]:=false;
   end;
  end;
 ans:=x2-x1;
 if (y2-y1)>ans then
  ans:=y2-y1;
 writeln(ans);
close(input);
close(output);
end.
