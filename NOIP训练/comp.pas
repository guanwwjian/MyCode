program comp;
var
i,j,k,n,m,s,l:longint;
str1,str2:string;
begin
assign(input,'comp.in');reset(input);
assign(output,'comp.out');rewrite(output);
 readln(n);
 for i:= 1 to n do
  begin
   readln(str1);
   readln(str2);
   s:=0;
   for j:= 1 to length(str1) do
    begin
     if str1[j]<>str2[j] then inc(s);
    end;
   if (s<=1)and(length(str1)=length(str2)) then writeln('Yes')
    else writeln('No');
  end;

close(input);
close(output);
end.

