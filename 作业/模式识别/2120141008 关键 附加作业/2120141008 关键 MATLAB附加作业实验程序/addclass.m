function [ newX,newY ] = addclass(oldX,oldY,location,filediscribe,clano)
    picstr=dir([location,'\',filediscribe]);
    [rowpos,colpos]=size(picstr);
    newX=oldX;
    newY=oldY;
    for i=1:rowpos
        newX=[newX;readpic([location,'\',picstr(i).name])];
        newY=[newY,clano];
    end
    
end

