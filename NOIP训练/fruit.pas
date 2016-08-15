var
i,j,k,n,m,s,l,r:longint;
a:array[1..100000] of extended;
f:array[0..100000] of extended;
begin
assign(input,'fruit.in');reset(input);
assign(output,'fruit.out');rewrite(output);
 readln(n);
 for i:= 1 to n do
  begin
   readln(a[i]);
  end;
 s:=0;
 f[0]:=-maxlongint;
 for i:= 1 to n do
  begin
   if a[i]>f[s] then
    begin
     inc(s);
     f[s]:=a[i];
    end
   else
    begin
     l:=0;r:=s;
     while l<r-1 do
      begin
       if a[i]<=f[(l+r) div 2] then
        begin
         r:=(l+r) div 2;
        end
       else
        begin
         l:=(l+r) div 2;
        end;
      end;
     f[r]:=a[i];
    end;
  end;
 writeln
 (s);


close(input);
close(output);
end.
1