var
i,j,k,n,m,u,v,ans:longint;
d:array[0..500,0..500] of boolean;
f:array[1..500,1..500] of longint;
flag:boolean;
begin
assign(input,'trip.in');reset(input);
assign(output,'trip.out');rewrite(output);
 readln(n,m);
 for i:= 1 to m do
  begin
   readln(u,v);
   d[u,v]:=true;
  end;
 ans:=0;
 for i:= 0 to n-1 do
   begin
    flag:=true;
    for j:= 0 to n-1 do
     if d[j,i] then flag:=false;
    if flag then ans:=ans+1;
   end;
  writeln(ans);
close(input);
close(output);
end.
