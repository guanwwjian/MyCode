classdef kfacility

    properties
        m %地址个数
        n %顾客个数
        oc %建设代价
        cap 
        dm 
        sc %服务代价
        F %用来存储选址全集
        nf  
        k %k中心选址中的k
    end
    methods
        function this=kfacility(loc,k) %构造函数用来初始化问题 loc：数据地址 k：k中心选址中的k
            fid=fopen(loc);
            tt=textscan(fid,'%n');
            data=tt{1};
            this.F=1:this.m;
            p=1;
            this.m=data(p);
            p=p+1;
            this.n=data(p);
            p=p+1;
            this.cap=data(p:2:p+this.m*2-1);
            this.oc=data(p+1:2:p+this.m*2-1);
            p=p+2*this.m;
            j=p:(this.m+1):p+(this.m+1)*this.n-1;
            i=setdiff(p:p+(this.m+1)*this.n-1,j);
            this.dm=data(j);
            this.sc=reshape(data(i),this.m,this.n);
            this.F=1:this.m;  
            
            this.k=k;
            this.nf=this.m;
        end;
        function cost=calcost(this,S,p,deltaflag) %计算代价 S：选址集合 p：交换个数 deltaflag决定代价计算的方式
            cost=0;
            if deltaflag==1
                delta=1+1/p+sqrt(3+2/p+1/p/p);
            else
                delta=1;
            end;
            for i=1:this.m
                if ismember(i,S)
                    cost=cost+this.oc(i)*delta;
                end;
            end;
            for j=1:this.n
                tcost=inf;
                for i=1:this.m
                    if ismember(i,S)&&(this.sc(i,j)<tcost)
                        tcost=this.sc(i,j);
                    end;
                end;
                cost=cost+tcost;
            end;
        end;
        function [res,flag]=findns(this,S,p,e)%寻找下一个符合条件的选址集合 S：当前选址集合 p：交换个数
            NIS=setdiff(this.F,S);
            costS=this.calcost(S,p,1);
            if length(S)<this.k
                for i=NIS
                    ts=union(S,i);
                    costts=this.calcost(ts,p,1);
                    if costts<=(1-e/(this.nf*this.nf+this.nf))*costS
                        flag=1;
                        res=ts;
                        return;
                    end;
                end;
            end;
            if length(S)>1
                for i=S
                    ts=setdiff(S,i);
                    costts=this.calcost(ts,p,1);
                    if costts<=(1-e/(this.nf*this.nf+this.nf))*costS
                        flag=1;
                        res=ts;
                        return;
                    end;
                end;
            end;
            mp=p;
            if mp>length(S)
                mp=length(S);
            end;
            if mp>length(NIS)
                mp=length(NIS);
            end;
            
            for i=1:mp
                for j=nchoosek(S,i)'
                    for l=nchoosek(NIS,i)'
                        ts=union(setdiff(S,j'),l');
                        costts=this.calcost(ts,p,1);
                        if costts<=(1-e/(this.nf*this.nf+this.nf))*costS
                            flag=1;
                            res=ts;
                            return;
                        end;
                    end;
                end;
            end;
            
            flag=0;
            res=S;
            return;
            
        end;
        function [cost,res]=bestcost(this,S0,p,e) %局部搜索局部解 S：当前选址集合 p：交换个数
            flag=1;
            S=S0;
            while flag==1
                [S,flag]=this.findns(S,p,e);
            end;
            cost=this.calcost(S,p,0);
            res=S;
        end;
        
        function [cost,res]=multical(this,times) %多次采样计算局部解 times采样次数
            e=0.001;
            p=1;
            cost=inf;
            res=[];
            for i=1:times
                S=[];
                for j=1:this.m
                    if randi(2)==1
                        S=union(S,j);
                    end;
                end;
                [tcost,tres]=this.bestcost(S,p,e);
                if (tcost<cost)
                    cost=tcost;
                    res=tres;
                end; 
            end;
        end;
    end
    
end

