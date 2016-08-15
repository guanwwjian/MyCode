headers=c("season","size","speed","mxPH","mnO2","Cl","NO3","NH4","oPO4","PO4","Chla","a1","a2","a3","a4","a5","a6","a7")
data<-read.table("F:\\关键\\研究生\\数据挖掘\\Analysis.txt",header = F,na.string=c("XXXXXXX"),col.names=headers)
summary(data)
library(car)
library(lattice)
library(DMwR)
for (i in 4:length(data)){
target=as.numeric(as.character(data[,i]))
dev.new()
par(mfrow=c(1,3),pin=c(1.7,2))
hist(target,prob=T,xlab='',main=paste(headers[i],' 直方图'))
#lines(density(target,na.rm=T))
rug(jitter(target))
qq.plot(target,main=paste(headers[i],' Q-Q图'))
boxplot(target,main=paste(headers[i],' 盒图'))
}
#for (i in 12:length(data))
#{
#for (j in 1:3){
#i=18
#j=2
#dev.new()
#bwplot(get(headers[i])~get(headers[j]),data=data,ylab=headers[i],xlab=headers[j],main=paste(headers[i],"~",headers[j]," 条件盒图"))
#for (k in 1:10000000){}
#}
#}

j=1
i=12
dev.new()
bwplot(get(headers[i])~get(headers[j]),data=data,ylab=headers[i],xlab=headers[j],main=paste(headers[i],"~",headers[j]," 条件盒图"))
i=13
dev.new()
bwplot(get(headers[i])~get(headers[j]),data=data,ylab=headers[i],xlab=headers[j],main=paste(headers[i],"~",headers[j]," 条件盒图"))
i=14
dev.new()
bwplot(get(headers[i])~get(headers[j]),data=data,ylab=headers[i],xlab=headers[j],main=paste(headers[i],"~",headers[j]," 条件盒图"))
i=15
dev.new()
bwplot(get(headers[i])~get(headers[j]),data=data,ylab=headers[i],xlab=headers[j],main=paste(headers[i],"~",headers[j]," 条件盒图"))
i=16
dev.new()
bwplot(get(headers[i])~get(headers[j]),data=data,ylab=headers[i],xlab=headers[j],main=paste(headers[i],"~",headers[j]," 条件盒图"))
i=17
dev.new()
bwplot(get(headers[i])~get(headers[j]),data=data,ylab=headers[i],xlab=headers[j],main=paste(headers[i],"~",headers[j]," 条件盒图"))
i=18
dev.new()
bwplot(get(headers[i])~get(headers[j]),data=data,ylab=headers[i],xlab=headers[j],main=paste(headers[i],"~",headers[j]," 条件盒图"))

j=2
i=12
dev.new()
bwplot(get(headers[i])~get(headers[j]),data=data,ylab=headers[i],xlab=headers[j],main=paste(headers[i],"~",headers[j]," 条件盒图"))
i=13
dev.new()
bwplot(get(headers[i])~get(headers[j]),data=data,ylab=headers[i],xlab=headers[j],main=paste(headers[i],"~",headers[j]," 条件盒图"))
i=14
dev.new()
bwplot(get(headers[i])~get(headers[j]),data=data,ylab=headers[i],xlab=headers[j],main=paste(headers[i],"~",headers[j]," 条件盒图"))
i=15
dev.new()
bwplot(get(headers[i])~get(headers[j]),data=data,ylab=headers[i],xlab=headers[j],main=paste(headers[i],"~",headers[j]," 条件盒图"))
i=16
dev.new()
bwplot(get(headers[i])~get(headers[j]),data=data,ylab=headers[i],xlab=headers[j],main=paste(headers[i],"~",headers[j]," 条件盒图"))
i=17
dev.new()
bwplot(get(headers[i])~get(headers[j]),data=data,ylab=headers[i],xlab=headers[j],main=paste(headers[i],"~",headers[j]," 条件盒图"))
i=18
dev.new()
bwplot(get(headers[i])~get(headers[j]),data=data,ylab=headers[i],xlab=headers[j],main=paste(headers[i],"~",headers[j]," 条件盒图"))

j=3
i=12
dev.new()
bwplot(get(headers[i])~get(headers[j]),data=data,ylab=headers[i],xlab=headers[j],main=paste(headers[i],"~",headers[j]," 条件盒图"))
i=13
dev.new()
bwplot(get(headers[i])~get(headers[j]),data=data,ylab=headers[i],xlab=headers[j],main=paste(headers[i],"~",headers[j]," 条件盒图"))
i=14
dev.new()
bwplot(get(headers[i])~get(headers[j]),data=data,ylab=headers[i],xlab=headers[j],main=paste(headers[i],"~",headers[j]," 条件盒图"))
i=15
dev.new()
bwplot(get(headers[i])~get(headers[j]),data=data,ylab=headers[i],xlab=headers[j],main=paste(headers[i],"~",headers[j]," 条件盒图"))
i=16
dev.new()
bwplot(get(headers[i])~get(headers[j]),data=data,ylab=headers[i],xlab=headers[j],main=paste(headers[i],"~",headers[j]," 条件盒图"))
i=17
dev.new()
bwplot(get(headers[i])~get(headers[j]),data=data,ylab=headers[i],xlab=headers[j],main=paste(headers[i],"~",headers[j]," 条件盒图"))
i=18
dev.new()
bwplot(get(headers[i])~get(headers[j]),data=data,ylab=headers[i],xlab=headers[j],main=paste(headers[i],"~",headers[j]," 条件盒图"))








par(mfrow=c(1,1))

dim(data)[1]-sum(complete.cases(data))
data[!complete.cases(data),]
delna<-na.omit(data)

mostna<-data
mostna<-data[-manyNAs(data)]
mostna<-centralImputation(mostna)

symnum(cor(data[,4:18],use="complete.obs"))
corna<-data[-manyNAs(data)]
lm(PO4~oPO4,data=corna)
lm(oPO4~PO4,data=corna)
fillPO4<-function(oP)
{
	if (is.na(oP)) return(NA)
	else return(42.897+1.293*oP)
}
filloPO4<-function(oP)
{
	if (is.na(oP)) return(NA)
	else return(-15.6142+0.6466*oP)
}
corna[is.na(algae$PO4),"PO4"]<-sapply(algae[is.na(algae$PO4),"oPO4"],fillPO4)
corna[is.na(algae$oPO4),"oPO4"]<-sapply(algae[is.na(algae$oPO4),"PO4"],filloPO4)

likena<-knnImputation(data)

write.table(delna,file="F:\\文件\\R语言\\delna.txt",row.names=FALSE,col.names=TRUE)
write.table(mostna,file="F:\\文件\\R语言\\mostna.txt",row.names=FALSE,col.names=TRUE)
write.table(corna,file="F:\\文件\\R语言\\corna.txt",row.names=FALSE,col.names=TRUE)
write.table(likena,file="F:\\文件\\R语言\\likena.txt",row.names=FALSE,col.names=TRUE)


