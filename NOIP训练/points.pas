var
i,j,k,m,gr,z:longint;
n,r,ans,d1,d3:qword;
{s:array[1..100000] of boolean;}
a:array[1..100000] of longint;
begin
assign(input,'points.in');reset(input);
assign(output,'points.out');rewrite(output);
 readln(r);
 n:=r*r;
 d1:=0;
 d3:=0;
 gr:=trunc(sqrt(r));
 z:=0;
 for i:= 1 to gr do
  begin
   if (r mod i)=0 then
    begin
     if (i mod 2)=1 then
      begin
       z:=z+1;
       a[z]:=i;
      end;
    end;
  end;
 for i:= 1 to z do
  for j:= i to z do
   begin
    if a[i]*a[j] mod 4 =1 then inc(d1);
    if a[i]*a[j] mod 4 =3 then inc(d3);
   end;
 ans:=4*(d1-d3);
 writeln(ans);

close(input);
close(output);
end.
