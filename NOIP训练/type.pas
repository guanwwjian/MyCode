var
i,j,k,n,m,t,l,x1,x2,z:longint;
s:array[1..20] of ansistring;
a:array[1..20,1..20,1..20] of longint;
b:array[1..20,1..400] of longint;
flag:boolean;
procedure left(x:longint);
var
i,j:longint;
begin
 for i:= 1 to n do
  for j:= 1 to l do
   begin
    if abs(b[i,j])=x then
     begin
      b[i,j-1]:=b[i,j];
      b[i,j]:=b[i,j+1];
     end;
   end;
end;
begin
assign(input,'type.in');reset(input);
assign(output,'type.out');rewrite(output);
 readln(n);
 for i:= 1 to n do
  readln(s[i]);
  l:=length(s[1]);
 for i:= 1 to n do
  begin
   z:=1;
   for j:= 1 to length(s[i]) do
    begin
     if s[i,j]=' ' then
      begin
       z:=z+1;
       t:=j;
       b[i,j]:=0;
      end
      else if s[i,j]='#' then
       begin
        a[z,i,j-t]:=z;
        b[i,j]:=z;
       end
       else if s[i,j]='0' then
        begin
         a[z,i,j-t]:=-z;
         b[i,j]:=-z;
        end
        else
         begin
          a[k,i,j-t]:=0;
          b[i,j]:=0;
         end;
    end;
  end;
 for i:= 2 to z do
  begin
   flag:=true;
   while flag do
    begin
     for j:= 1 to n do
      for k:= 1 to l do
       begin
        if abs(b[j,k])=i then
         begin
          if (b[j,k-2]<>0)and(abs(b[j,k-2])<>i) then flag:=false;
         end;
       end;
     if flag then left(i);
    end;
  end;
 x1:=maxlongint;
 x2:=0;
 for i:= 1 to n do
  for j:= 1 to l do
   begin
    if b[i,j]<>0 then
     begin
      if j<x1 then x1:=j;
      if x2<j then x2:=j;
     end;
   end;
 for i:= 1 to n do
  begin
  for j:= x1 to x2 do
   begin
    if b[i,j]<=0 then write('.')
     else if b[i,j]>0 then write('#')
   end;
  writeln;
  end;
close(input);
close(output);
end.
