var
i,j,k,t,jin,z:longint;
c:char;
str:string;
a:array[0..100000] of longint;
begin
assign(input,'Kbased.in');reset(input);
assign(output,'Kbased.out');rewrite(output);
 a[0]:=0;
 readln(t);
 for i:= 1 to t do
  begin
   readln(jin);
   readln(str);
   for z:= 1 to length(str) do
    begin
     if (str[z]>='0')and(str[z]<='9') then a[z]:=ord(str[z])-ord('0')
      else if (str[z]>='A')and(str[z]<='F') then a[z]:=10+ord(str[z])-ord('A');
    end;
   for j:= 1 to z do
    begin
     a[j]:=a[j]+a[j-1]*jin;
     a[j]:=a[j] mod (jin-1)
    end;
    if a[z]=0 then writeln('yes')
     else writeln('no');
    end;
 close(input);
 close(output);
end.
