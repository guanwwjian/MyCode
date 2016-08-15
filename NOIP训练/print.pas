var
i,j,k,n,m,ans,t,l,r,max:longint;
a:array[1..100] of longint;
d:array[1..20000] of longint;
c:array[1..9] of longint;
begin
assign(input,'print.in');reset(input);
assign(output,'print.out');rewrite(output);
 readln(n,m);
 for i:= 1 to n do
  begin
   read(a[i]);
   a[i]:=10-a[i];
   inc(c[a[i]]);
  if a[i]>max then max:=a[i];
  end;
 readln;
 ans:=0;
 for i:= 1 to n do
  d[i]:=i;
 l:=1;r:=n;
 while l<=r do
  begin
   if a[d[l]]=max then
    begin
     inc(ans);
     dec(c[max]);
     while c[max]=0 do dec(max);
     if d[l]=m then break;
     inc(l);

    end
   else
    begin
     inc(r);
     d[r]:=d[l];
     inc(l);
    end;
  end;
 writeln(ans);
close(input);
close(output);
end.