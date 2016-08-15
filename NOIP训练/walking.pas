var
i,j,k,n,m,t1,t2:longint;
ans,x,y,tt:int64;
begin
assign(input,'walking.in');reset(input);
assign(output,'walking.out');rewrite(output);
 readln(x,y,t1,t2);
 if y<x then
  begin
   tt:=x;x:=y;y:=tt;
  end;
 if t1*2<=t2 then ans:=(x+y)*t1
  else if t1<=t2 then
   begin
    ans:=x*t2+(y-x)*t1;
   end
  else
   begin
    ans:=x*t2+((y-x) div 2)*2*t2+((y-x) mod 2)*t1;
   end;
 writeln(ans);
close(input);
close(output);
end.
