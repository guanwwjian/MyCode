var
i,j,k,n,m,tt,now,l:longint;
flag:boolean;
a,b:ansistring;
begin
assign(input,'matching.in');reset(input);
assign(output,'matching.out');rewrite(output);
 flag:=true;
 readln(a);
 readln(b);
 l:=length(b);
 tt:=pos(b,a);
 now:=0;
 while tt<>0 do
  begin
   writeln(now+tt);
   now:=now+tt+l-1;
   flag:=false;
   delete(a,1,tt+l-1);
   tt:=pos(b,a);
  end;
 if flag then writeln('Not Found!');
close(input);
close(output);
end.
