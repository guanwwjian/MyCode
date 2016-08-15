var
i,j,k,n,m,sa,sb,sc,ans:longint;
a,b,c:array[1..1000000] of longint;
d,e:array[1..1000000] of longint;
begin
 assign(input,'card.in');reset(input);
 assign(output,'card.out');rewrite(output);
  readln(n,m);
  sb:=n;
  for i:= 1 to n do
   begin
    b[i]:=n-i+1;
   end;
  while sb>0 do
   begin
    if sb>0 then
     begin
      inc(sa);
      a[sa]:=b[sb];
      dec(sb);
     end;
    if sb>0 then
     begin
      inc(sc);
      c[sc]:=b[sb];
      dec(sb);
     end;
   end;
  while sa>0 do
   begin
    inc(sb);
    b[sb]:=a[sa];
    dec(sa);
   end;
  while sc>0 do
   begin
    inc(sb);
    b[sb]:=c[sc];
    dec(sc);
   end;
 for i:= 1 to n do
  d[i]:=b[n-i+1];
 for i:= 1 to n do
  begin
   e[d[i]]:=i;
  end;
 ans:=1;
 for i:= 1 to m do
  begin
   ans:=e[ans];
  end;
 writeln(ans);
 close(input);
 close(output);
end.