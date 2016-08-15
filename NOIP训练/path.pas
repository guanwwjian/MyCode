var
i,j,k,n,z1,z2,same,zm:longint;
str1,str2:string;
s1,s2:array[1..100] of string;
c:char;
ans:string;
flag:boolean;
begin
assign(input,'path.in');reset(input);
assign(output,'path.out');rewrite(output);
 flag:=true;
 z1:=0;z2:=0;
 readln(str1);
 for i:= 1 to length(str1) do
  begin
   c:=str1[i];
   if c='/' then z1:=z1+1
    else s1[z1]:=s1[z1]+c;
  end;
  readln(str2);
 for i:= 1 to length(str2) do
  begin
   c:=str2[i];
   if c='/' then z2:=z2+1
    else s2[z2]:=s2[z2]+c;
  end;
  if str1='/' then z1:=0;
  if str2='/' then z2:=0;
  zm:=z1;
  if z2<zm then zm:=z2;
  for i:= 1 to zm do
   if s1[i]=s2[i] then same:=i
    else break;
  for i:= same+1 to z2 do
   ans:=ans+'../';
  for i:= same+1 to z1 do
   if flag then
    begin
     ans:=ans+s1[i];
     flag:=false;
    end
   else
    begin
     ans:=ans+'/';
     ans:=ans+s1[i];
    end;
  writeln(ans);
 close(input);
 close(output);
end.
