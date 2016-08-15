function [ newX ] = addtests(oldX,location,filediscribe)
    picstr=dir([location,'\',filediscribe]);
    [rowpos,colpos]=size(picstr);
    newX=oldX;
    for i=1:rowpos
        newX=[newX;readpic([location,'\',picstr(i).name])];
    end
end
