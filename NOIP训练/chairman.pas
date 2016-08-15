  var
   con,i,j,k,n,xc,dc,xz,dz,xj,dj:longint;
   str,fu:array[1..1000] of string;
   s:string;
   chi,zhong,jia:array[1..1000] of longint;
  begin
  assign(input,'chairman.in');reset(input);
  assign(output,'chairman.out');rewrite(output);
   readln(n);
   for i:= 1 to n do
    begin
     readln(str[i]);
     readln(chi[i]);
     readln(zhong[i]);
     readln(jia[i]);
    end;
   readln(xc,dc);
   readln(xz,dz);
   readln(xj,dj);
  con:=0;
  for i:= 1 to n do
   if (chi[i]<dc)and(zhong[i]<dz)and(jia[i]<dj)and(chi[i]>xc)and(zhong[i]>xz)and(jia[i]>xj) then
    begin
     con:=con+1;
     fu[con]:=str[i]
    end;
  for i:= 1 to con do
   for j:= i to con do
    if fu[i]>fu[j] then
    begin
     s:=fu[i];fu[i]:=fu[j];fu[j]:=s;
    end;
  for i:= 1 to con do
   writeln(fu[i]);
 close(input);
 close(output);
 end.