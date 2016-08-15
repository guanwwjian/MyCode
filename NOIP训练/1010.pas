var
i,j,k,n,m:longint;
flag:boolean;
t:array[1..3] of longint;
b:array[0..9] of boolean;
begin
 for i:= 111 to 333 do
  begin
   fillchar(b,sizeof(b),false);
   flag:=false;
   b[0]:=true;
   t[1]:=i;
   t[2]:=2*i;
   t[3]:=3*i;
   for j:= 1 to 3 do
    for k:= 1 to 3 do
    begin
     if b[t[j] mod 10] then
      begin
       flag:=true;
      end
     else b[t[j] mod 10]:=true;
    t[j]:=t[j] div 10;
    end;
   if not flag then
    writeln(i,' ',i*2,' ',i*3);
  end;
end.
