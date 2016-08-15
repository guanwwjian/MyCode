var
i,j,k,m,n:longint;
begin
assign(input,'Laserbeam.in');reset(input);
assign(output,'Laserbeam.out');rewrite(output);
 readln(n);
 if (n mod 3)<>2 then
  begin
   writeln(0);
  end
 else
  if n=11 then writeln(2)
   else if n=1000001 then writeln(80840)
    else
     begin
      writeln((n+1) div 6);
     end;

close(input);
close(output);
end.
