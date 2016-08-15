var
i,j,k,n,p,q,x,y:longint;
ans:longint;
function zheng(i:double):longint;
 begin
  if i>0 then exit(trunc(i))
   else exit(-10);
 end;

function ff(i:longint):longint;
var
j,k,l:longint;
 begin
  if i<=0 then exit(1)
   else
    begin
     exit(ff(zheng(i/p-x))+ff(zheng(i/q-y)));
    end;
 end;

begin
assign(input,'infinite.in');reset(input);
assign(output,'infinite.out');rewrite(output);
 readln(n,p,q,x,y);
 ans:=ff(n);
 writeln(ans);

close(input);
close(output);
end.
