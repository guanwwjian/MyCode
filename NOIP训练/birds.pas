var
i,j,k:longint;
n,m,t:int64;
begin
assign(input,'birds.in');reset(input);
assign(output,'birds.out');rewrite(output);
 readln(n);
 t:=0;
 while n<>0 do
  begin
   m:=trunc((sqrt(1+8*n)-1)/2);
   t:=t+m;
   n:=n-m*(m+1) div 2;
  end;
 writeln(t);
close(input);
close(output);
end.
