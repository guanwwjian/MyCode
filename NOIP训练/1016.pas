var
i,j,k,n,m,s,x,t1,t2:longint;
begin
 readln(n);
 s:=0;
 x:=trunc((-1+sqrt(1+8*n))/2);
 if (1+x)*x div 2=n then dec(x);
 t1:=n-(1+x)*x div 2;
 t2:=x+2-t1;
 if (x mod 2)=1 then writeln(t1,'/',t2)
  else writeln(t2,'/',t1);

end.
