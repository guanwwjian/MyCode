var
i,j,k,n,m,x,y,z,ans,tt,l,r:longint;
a,v:array[1..200,1..200] of longint;
s:array[1..200] of longint;
c:array[1..200] of longint;
b,d,p,t,ff:array[0..2000] of longint;
e,te,f:array[0..2000,0..2000] of longint;
begin
assign(input,'money.in');reset(input);
assign(output,'money.out');rewrite(output);
  readln(n,m);
  for i:= 1 to m do
   begin
    readln(x,y,z);
    inc(x);inc(y);
    inc(s[x]);
    a[x,s[x]]:=y;
    v[x,s[x]]:=z;
    inc(s[y]);
    a[y,s[y]]:=x;
    v[y,s[y]]:=z;
   end;
  ans:=maxlongint;
  for i:= 1 to n do
   if b[i]=0 then
    begin
     l:=1;r:=1;
     fillchar(p,sizeof(p),0);
     fillchar(b,sizeof(b),0);
     d[l]:=i;t[l]:=0;ff[l]:=0;
     p[1]:=1;
     e[1,1]:=i;
     while l<=r do
      if b[d[l]]=0 then
       begin
        inc(b[d[l]]);
        f[d[l],b[d[l]]]:=l;
        for j:= 1 to s[d[l]] do
        if a[d[l],j]<>ff[l] then
         begin
          inc(r);
          d[r]:=a[d[l],j];
          t[r]:=t[l]+v[d[l],j];
          ff[r]:=d[l];
          e[r]:=e[l];
          te[r]:=te[l];
          p[r]:=p[l]+1;
          e[r,p[r]]:=d[r];
          te[r,p[r]]:=t[r];
         end;
        inc(l);
       end
      else
       begin
        for j:= 1 to b[d[l]] do
         begin
         for k:= p[l]-1 downto 1 do
          if e[l,k]=e[f[d[l],j],k] then break;
         tt:=t[l]+t[f[d[l],j]]-2*te[l,k];
         if ans>tt then
          ans:=tt;
         end;
        inc(b[d[l]]);
        f[d[l],b[d[l]]]:=l;
        inc(l);
       end;
    end;
 if ans<maxlongint then writeln(ans)
  else writeln('No solution.');

close(input);
close(output);
end.
