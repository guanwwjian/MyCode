var
i,j,k,l,m,t,tt,za,zb,zh,zc,max,xian,zaj,x1,x2,ww:longint;
str:ansistring;
a,b,he,cha,aji:array[0..1000] of longint;
ji:array[1..1000,1..1000] of longint;
zj:array[1..1000] of longint;
c:array[1..1000,1..1000] of char;
fu:boolean;
begin
assign(input,'arith.in');reset(input);
assign(output,'arith.out');rewrite(output);
 readln(t);
 for l:= 1 to t do
  begin
  max:=0;xian:=0;
  zaj:=0;
  x1:=0;
  x2:=0;
  zb:=0;
  za:=0;
  tt:=0;
  zc:=0;
  zh:=0;
  fillchar(c,sizeof(c),' ');
  fillchar(ji,sizeof(ji),0);
  fillchar(zj,sizeof(zj),0);
  for i:= 0 to 1000 do
   begin
   a[i]:=0;
   b[i]:=0;
   he[i]:=0;
   cha[i]:=0;
   aji[i]:=0;
   end;
   readln(str);
   tt:=pos('+',str);
   if tt>0 then
    begin
     za:=0;
     for i:= tt-1 downto 1 do
     begin
      za:=za+1;
      a[za]:=ord(str[i])-ord('0');
     end;
     zb:=0;
     for i:= length(str) downto tt+1 do
      begin
       zb:=zb+1;
       b[zb]:=ord(str[i])-ord('0');
      end;
     max:=za;
     if zb>max then max:=zb;
    zh:=max;
    for i:= 1 to max do
     begin
      he[i]:=a[i]+b[i]+he[i-1] div 10;
      he[i-1]:=he[i-1] mod 10;
     end;
     if he[max]>=10 then
      begin
       zh:=zh+1;
       he[zh]:=he[zh-1] div 10;
       he[zh-1]:=he[zh-1] mod 10;
      end;
    for i:= 1 to za do
     c[1,i]:=chr(a[i]+ord('0'));
    for i:= 1 to zb do
     c[2,i]:=chr(b[i]+ord('0'));
     c[2,zb+1]:='+';
    if zb+1>max then max:=zb+1;
    if zc>max then max:=zc;
    for i:= 1 to max do
     c[3,i]:='-';
    for i:= 1 to zh do
     c[4,i]:=chr(he[i]+ord('0'));
    for i:= 1 to 4 do
     begin
     for j:= max  downto 1 do
      write(c[i,j]);
     writeln;
     end;
    writeln;
    end;
   tt:=pos('-',str);
   if tt>0 then
    begin
    za:=0;
    for i:= tt-1 downto 1 do
     begin
      za:=za+1;
      a[za]:=ord(str[i])-ord('0');
     end;
     zb:=0;
     for i:= length(str) downto tt+1 do
      begin
       zb:=zb+1;
       b[zb]:=ord(str[i])-ord('0');
      end;
     max:=za;
     if zb>max then max:=zb;
    zh:=max;
    for i:= 1 to max do
     begin
      cha[i]:=a[i]-b[i];
      if cha[i-1]<0 then
       begin
       cha[i]:=cha[i]-1;
       end;
     end;
     zc:=max;
     while (cha[zc]=0)and(zc>1) do inc(zc);
     if zb+1>max then max:=zb+1;
     xian:=zc;
     if zb+1>xian then xian:=zb+1;
     for i:= 1 to za do
      c[1,i]:=chr(a[i]+ord('0'));
     for i:= 1 to zb do
      c[2,i]:=chr(b[i]+ord('0'));
     c[2,zb+1]:='-';
     for i:= 1 to xian do
      c[3,i]:='-';
     for i:= 1 to zc do
      c[4,i]:=chr(cha[i]+ord('0'));
     for i:= 1 to 4 do
      begin
      for j:= max downto 1 do
       write(c[i,j]);
      writeln;
      end;
     writeln;
    end;
   tt:=pos('*',str);
   if tt>0 then
    begin
     za:=0;
     for i:= tt-1 downto 1 do
     begin
      za:=za+1;
      a[za]:=ord(str[i])-ord('0');
     end;
     zb:=0;
     for i:= length(str) downto tt+1 do
      begin
       zb:=zb+1;
       b[zb]:=ord(str[i])-ord('0');
      end;
     max:=za;
     if max<zb then max:=zb;
      for i:= 1 to zb do
       begin
       if b[i]<>0 then
        begin
          for j:= 1 to za do
           begin
            ji[i,j]:=a[j]*b[i]+(ji[i,j-1]) div 10;
            ji[i,j-1]:=ji[i,j-1] mod 10;
           end;
          zj[i]:=za;
          while ji[i,zj[i]]>=10 do
           begin
            inc(zj[i]);
            inc(ji[i,zj[i]],(ji[i,zj[i]-1] div 10));
            ji[i,zj[i]-1]:=(ji[i,zj[i]-1] mod 10)
           end;
        end
        else
         begin
          zj[i]:=1;
          ji[i,1]:=0;
         end;
       end;
     for i:= 1 to zb do
      for j:= 1 to zj[i] do
       begin
        inc(aji[i+j-1],ji[i,j]);
       end;
     for i:= 1 to (zb+za-1) do
      begin
       aji[i]:=aji[i]+(aji[i-1] div 10);
       aji[i-1]:=aji[i-1] mod 10;
      end;
     zaj:=zb+za-1;
     while (aji[zaj]>10)or(aji[zaj+1]>0) do
      begin
       zaj:=zaj+1;
       aji[zaj]:=aji[zaj]+aji[zaj-1] div 10;
       aji[zaj-1]:=aji[zaj-1] mod 10;
      end;
     max:=zaj;
     x2:=max;
     x1:=zb+1;
     if zj[1]>zb then x1:=zj[1];
     for i:= 1 to za do
      begin
       c[1,i]:=chr(a[i]+ord('0'));
      end;
     for i:= 1 to zb do
       c[2,i]:=chr(b[i]+ord('0'));
      c[2,zb+1]:='*';
     for i:= 1 to x1 do
      c[3,i]:='-';

     for i:= 1 to zb do
      for j:= 1 to zj[i] do
       begin
        c[3+i,i+j-1]:=chr(ji[i,j]+ord('0'));
       end;
     for i:= 1 to x2 do
      c[4+zb,i]:='-';
     for i:= 1 to zaj do
      c[5+zb,i]:=chr(aji[i]+ord('0'));

      if zb>1 then  ww:=zb+5 else ww:=4;
      if zb+1>max then max:=zb+1;
     for i:= 1 to ww do
      begin
       for j:= max downto 1 do
        write(c[i,j]);
       writeln;
      end;
     writeln;
    end;
  end;

close(input);
close(output);
end.
