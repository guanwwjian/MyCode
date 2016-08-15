  var
  i,j,k,n:longint;
  begin
  assign(input,'square.in');reset(input);
  assign(output,'square.out');rewrite(output);
  readln(n);
  for i:= 1 to n do
   begin
    write('*');
    if (i=1)or(i=n) then
     for j:= 1 to n-2 do
      write(' *')
    else
    for j:= 1 to n-2 do
      write('  ');
    write(' *');
    writeln;
   end;
  close(input);
  close(output);
 end.

