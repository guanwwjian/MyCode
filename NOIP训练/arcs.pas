var
i,j,k,n,m,r,x,t1,t2,tt,ii:longint;
ch:char;
b:array[1..50,1..50] of longint;
fx,tx,fy,ty:array[1..4] of longint;
begin
assign(input,'arc.in');reset(input);
assign(output,'arc.out');rewrite(output);
{ readln(n,m);
 for i:= 1 to n do
  begin
  for j:= 1 to m do
   begin
   read(ch);
   if ch='.' then b[i,j]:=true
    else b[i,j]:=false;
   end;
   readln;
  end;
 min:=n;
 if m<min then min:=m
 if m<min then min:=m;
 for i:= 0 to n do
  for j:= 0 to m do
   for r:= 1 to min do
    begin
     fx[1]:=i+1;fx[2]:=i-r+1;fx[3]:=i+1;fx[4]:=i-r+1;
     tx[1]:=i+r;tx[2]:=i;tx[3]:=i+r;tx[4]:=i;
     fy[1]:=j+1;fy[2]:=j+1;fy[3]:=j-r+1;fy[4]:=j-r+1;
     ty[1]:=j+r;ty[2]:=j+r;ty[3]:=j;ty[4]:=j;
    for ii:=1 to 4 do
     begin
     flag:=true;
     for x:= fx[ii] to tx[ii] do
      for y:= fy[ii] to ty[ii] do
       begin
        tt:=0;
        for t1:=x-1 to x do
         for t2:=y-1 to y do
          begin
           if t1*t1+t2*t2-r*r<0 then tt:=tt+1;
          end;
        if (tt>0)and(tt<4) then
         if not(b[x,y]) then flag:=false;
       end;
      if flag then
       begin

       end;
     end;
    end;}
 writeln(-1);
close(input);
close(output);
end.
