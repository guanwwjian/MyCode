var
ans,i,j,k,n,m,s,z:longint;
c:array[1..150,1..150] of char;
a:array[1..5000] of longint;
begin
assign(input,'Movie.in');reset(input);
assign(output,'Movie.out');rewrite(output);
 readln(n,m);
 z:=0;
 for i:= 1 to n do
  begin
   s:=0;
   for j:= 1 to m do
    begin
     read(c[i,j]);
     if c[i,j]='Y' then s:=s+1
      else
       begin
        z:=z+1;
        a[z]:=s;
        s:=0;
       end;
      end;
   z:=z+1;
   a[z]:=s;
   s:=0;
   readln
  end;
 for i:= 1 to z do
  ans:=ans+((a[i]+1) div 2);
 writeln(ans);
close(input);
close(output);
end.
