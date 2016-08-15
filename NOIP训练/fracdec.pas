var
i,j,k,n,m,a,b,l:longint;
st,tt,sa,sb:ansistring;
flag,f1:boolean;
v:array[1..100000] of boolean;
begin
assign(input,'fracdec.in');reset(input);
assign(output,'fracdec.out');rewrite(output);
 readln(n,m);
 a:=n div m;
 b:=n mod m;
 write(a,'.');
 if b=0 then writeln('0')
  else
  begin
   while b<>0 do
    begin
     if not(v[b]) then v[b]:=true
      else f1:=true;
     b:=b*10;
     str(b div m,tt);
     b:=b mod m;
     st:=st+tt;
     l:=length(st);
     for i:= l downto 1 do
      begin
       if (pos(copy(st,l-i+1,i),st)=(l-i*2+1))and f1 then
        begin
         sa:=copy(st,1,l-i*2);
         sb:=copy(st,l-i+1,i);
         flag:=true;
         break;
        end;
      end;
     if flag then break;

  end;
  writeln(sa,'(',sb,')');
 end;
close(input);
close(output);
end.
