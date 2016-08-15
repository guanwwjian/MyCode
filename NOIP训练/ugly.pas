var
ans,i,j,k,n,z,ss:longint;
b:array[1..300] of boolean;
s:array[1..300] of longint;
function ugly(k:longint):boolean;
var
i,j:longint;
 begin
  if ((k mod 2)<>0)and((k mod 3)<>0)and((k mod 5)<>0)and((k mod 7)<>0)
   then exit(false);
  if k=1 then exit(false);
  i:=1;
  while s[i]*s[i]<=k do
   begin
    if (k mod s[i])=0 then exit(false);
    i:=i+1;
   end;
  exit(true);
 end;
begin
assign(input,'ugly.in');reset(input);
assign(output,'ugly.out');rewrite(output);
fillchar(b,sizeof(b),true);
b[1]:=false;
 for i:= 1 to 300 do
  begin
   if b[i] then
    begin
     j:=1;
     while ((i*j)<=300) do
      begin
       j:=j+1;
       b[i*j]:=false;
      end;
    end;
  end;
 z:=0;
 for i:= 11 to 300 do
  begin
   if b[i] then
    begin
     z:=z+1;
     s[z]:=i;
    end;
  end;
 readln(n);
 ss:=0;i:=0;
 while ss<n do
  begin
   i:=i+1;
   if ugly(i) then ss:=ss+1;
   if ss=n then
    begin
     ans:=i;
     break;
    end;
  end;
writeln(ans);
close(input);
close(output);

end.
