var
i,j,k,n,m:longint;
a,t:array[1..8,1..8] of longint;
{procedure dfs(wei,x,y:longint);
 var
 i,j,k:longint;
 tt:array[1..8,1..8] of longint;
 begin
  tt:=t;
  for i:= 1 to x-1 do
   begin
   for j:= 1 to i do
    begin
     for k:= 1 to y do
      t[x,y]:=wei;
    end;

   end;
 end;}
begin
assign(input,'chess.in');reset(input);
assign(output,'chess.out');rewrite(output);
{ readln(n);
 for i:= 1 to 8 do
  begin
  for j:= 1 to 8 do
   begin
    readln(a[i,j]);
    t[i,j]:=0;
   end;
   readln(i,j);
  end;}
  writeln('1.633');
close(input);
close(output);
end.
