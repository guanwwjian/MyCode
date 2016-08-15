var
i,j,k,n,m,tt,tt1,tt2,ii,jj,ans:longint;
a:array[1..3000,1..3000] of longint;
b:array[1..3000] of integer;
b1,b2:boolean;
ch:char;
begin
assign(input,'harmony.in');reset(input);
assign(output,'harmony.out');rewrite(output);
 readln(n);
 for i:= 1 to n do
  begin
   for j:= 1 to n do
    begin
     read(ch);
     a[i,j]:=ord(ch)-ord('0');
    end;
   readln;
  end;
 for i:= 1 to n do
  for j:= n downto 1 do
   begin
    b[i]:=n+1;
    if a[i,j]=1 then
     begin
      b[i]:=n-j+1;
      break;
     end;
   end;
 ans:=0;
 {for i:= n downto 1 do
  if b[i]<i then
  begin
   for j:= i-1 downto 1 do
    if (b[j]>=i)and(b[i]>=j) then break;
   ii:=i;jj:=j;
   tt:=b[i];b[i]:=b[j];b[j]:=tt;
   ans:=ans+i-j;
  end; }
  for i:= n downto 1 do
   begin
    while b[i]<i do
     begin
      for j:= i-1 downto 1 do
       begin
        if b[j]>=i then break;
       end;
      ans:=ans+i-j;
     tt:=b[j];
     move(b[j+1],b[j],2*(i-j));
     b[i]:=tt;
     end;
   end;
  writeln(ans);
close(input);
close(output);
end.
