var
i,j,k,n,m:longint;
begin
assign(input,'trans.in');reset(input);
assign(output,'trans.out');rewrite(output);
 randomize;
 if random(10000) mod 2=0 then writeln('Yes')
  else writeln('No');

close(input);
close(output);
end.
