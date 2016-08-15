var
i,j,k,n,m,x,y,s,ax1,ax2,ay1,ay2,ans:longint;
x1,x2,y1,y2:array[1..100] of longint;
begin
assign(input,'rectangle.in');reset(input);
assign(output,'rectangle.out');rewrite(output);
 readln(n,x,y);
 for i:= 1 to n do
  begin
   readln(x1[i],y1[i],x2[i],y2[i]);
  end;
 ans:=0;
 for i:= 1 to n do
  begin
  ax1:=x1[i];ay1:=y1[i];
  ax2:=ax1+x;ay2:=ay1+y;
  s:=0;
  for j:= 1 to n do
   begin
    if (ax1<=x1[j])and(x2[j]<=ax2)and(ay1<=y1[j])and(y2[j]<=ay2) then inc(s);
   end;
  if ans<s then ans:=s;
  end;
  writeln(ans);
close(input);
close(output);
end.
