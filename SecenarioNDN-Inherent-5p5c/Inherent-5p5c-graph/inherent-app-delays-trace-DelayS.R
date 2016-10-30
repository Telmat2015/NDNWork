# install.packages('ggplot2')
library(ggplot2)
# install.packages('scales')
library(scales)

# install.packages('doBy')
library(doBy)

#########################
# Rate trace processing #
#########################
data = read.table("/home/ardi/R/inherent-app-delays-trace.txt", header=T)
data$Node = factor(data$Node)
data$DelayS <- data$DelayS
data$Type = factor(data$Type)

Node.jayapura         = subset(data, Node %in% c("jayapura"))
Node.surabaya         = subset(data, Node %in% c("surabaya"))
Node.manado           = subset(data, Node %in% c("manado"))
Node.palangkaraya     = subset(data, Node %in% c("palangkaraya"))
Node.palembang        = subset(data, Node %in% c("palembang"))

jayapura<-Node.jayapura$DelayS
surabaya<-Node.surabaya$DelayS
manado<-Node.surabaya$DelayS
palangkaraya<-Node.surabaya$DelayS
palembang<-Node.surabaya$DelayS

png("/home/ardi/Desktop/Rcrot/inherent-app-delays-trace-delayS.png", width=1280, height=720)

plot(ecdf(jayapura), main=NA,  
     xlab="", ylab="",verticals = TRUE, do.points=FALSE, lwd=2, lty=1, col="red", cex.lab=1.25, cex.axis=1.25)
lines(ecdf(surabaya), verticals= TRUE, do.points=FALSE, lwd=2, lty=2, col="green", cex.lab=1.25, cex.axis=1.25)
lines(ecdf(manado), verticals=TRUE, do.points=FALSE, lwd=2, lty=3, col="blue", cex.lab=1.25, cex.axis=1.25)
lines(ecdf(palangkaraya), verticals=TRUE, do.points=FALSE, lwd=2, lty=4, col="black", cex.lab=1.25, cex.axis=1.25)
lines(ecdf(palembang), verticals=TRUE, do.points=FALSE, lwd=2, lty=4, col="black", cex.lab=1.25, cex.axis=1.25)

legend("bottomright", legend=c("jayapura", "surabaya", "manado", 
                               "palangkaraya", "palembang"),
       col=c("red", "green", "blue", "black"), lwd=c(2,2,2,2),
      lty=c(1,2,3,4), cex=0.8, box.lty=0, bg=NA) 

retval <- dev.off()

