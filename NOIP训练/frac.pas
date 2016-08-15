var
i,j,k,n,m,x1,x2,y1,y2:longint;
c:array[0..8000,0..2000] of char;
h:array[0..2000] of boolean;
l:array[0..8000] of boolean;
procedure print(n,x,y:longint);
 begin
  if n=1 then
   begin
    c[x,y]:='/';
    c[x-1,y+1]:='/';
    c[x+1,y]:='\';
    c[x+2,y+1]:='\';
    c[x,y+1]:='_';
    c[x+1,y+1]:='_';
    if x1>(x-1) then x1:=x-1;
    if x2<(x+2) then x2:=x+2;
    if y1>y then y1:=y;
    if y2<y+1 then y2:=y+1;
   end
  else
   begin
    print(n-1,x,y);
    print(n-1,x-(1 shl (n-1)),y+(1 shl (n-1)));
    print(n-1,x+(1 shl (n-1)),y+(1 shl (n-1)));
   end;
 end;

begin
assign(input,'frac.in');reset(input);
assign(output,'frac.out');rewrite(output);
 readln(n);
x1:=maxlongint;
x2:=-maxlongint;
y1:=maxlongint;
y2:=-maxlongint;
for i:= 0 to 2*(1 shl n) do
 for j:= 0 to (1 shl n) do
  c[i,j]:=' ';
 print(n,4000,0);
 for j:= y1 to y2 do
  begin
  for i:= x1 to x2 do
   write(c[i,j]);
  writeln;
  end;

close(input);
close(output);
end.
