var
i,j,k,n,m,s,l,x,y,z,min,p:longint;
a:array[1..15,1..3] of longint;
b:array[0..1000,1..3] of longint;
c:array[1..3] of longint;
flag:boolean;
begin
assign(input,'Olympic.in');reset(input);
assign(output,'Olympic.out');rewrite(output);
 readln(n);
 for i:= 1 to n do
  begin
   readln(a[i,1],a[i,2],a[i,3]);
  end;
  c[1]:=maxlongint;c[2]:=maxlongint;
  c[3]:=maxlongint;
 for j:= 1 to 3 do
  for i:= 1 to 1000 do
   begin
    b[i,j]:=0;
    for k:= 2 to n do
     if a[k,j]*i>a[1,j]*i then inc(b[i,j]);
    if b[i,j]<c[j] then c[j]:=b[i,j];
   end;
 min:=maxlongint;
 flag:=true;
 p:=0;
 for i:= 1 to 1000 do
  if (b[i,1]<>b[i-1,1]) then
   for j:= 1 to i do
    if (b[j,2]<>b[j-1,2]) then
     for k:= 1 to j do
      if (b[k,3]<>b[k-1,3]) then
       begin
        s:=0;
        for l:= 2 to n do
         begin
         if a[l,1]*i+a[l,2]*j+a[l,3]*k>a[1,1]*i+a[1,2]*j+a[1,3]*k then inc(s);
         inc(p);
         end;
        if s<min then
         begin
          min:=s;
          x:=i;y:=j;z:=k;
         end;
       end;
 writeln(x,' ',y,' ',z);
close(input);
close(output);
end.
