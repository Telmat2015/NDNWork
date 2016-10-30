# install.packages('ggplot2')
library(ggplot2)
# install.packages('scales')
library(scales)

# install.packages('doBy')
library(doBy)

#########################
# Rate trace processing #
#########################
data5 = read.table("/home/ardi/R/load-balancer-drop/load-balancer-l2trace-inherent-drop-5s.txt", header=T)
data10 = read.table("/home/ardi/R/load-balancer-drop/load-balancer-l2trace-inherent-drop-10s.txt", header=T)
data15 = read.table("/home/ardi/R/load-balancer-drop/load-balancer-l2trace-inherent-drop-15s.txt", header=T)
data20 = read.table("/home/ardi/R/load-balancer-drop/load-balancer-l2trace-inherent-drop-20s.txt", header=T)

Drop.data5   = subset(data5, Type %in% c("Drop"))
Drop.data10    = subset(data10, Type %in% c("Drop"))
Drop.data15    = subset(data15, Type %in% c("Drop"))
Drop.data20     = subset(data20, Type %in% c("Drop"))

data5<-Drop.data5$Packets
data10<-Drop.data10$Packets
data15<-Drop.data15 $Packets
data20<-Drop.data20$Packets

png("/home/ardi/Desktop/Rcrot/load-balancer-l2trace-inherent-drop.png", width=1280, height=720)

plot(ecdf(data5), main=NA,  
     xlab="Delay (micro Seconds)", ylab="Ecdf",verticals = TRUE, do.points=FALSE, lwd=2, lty=1, col="red", cex.lab=1.25, cex.axis=1.25)
lines(ecdf(data10), verticals= TRUE, do.points=FALSE, lwd=2, lty=2, col="green", cex.lab=1.25, cex.axis=1.25)
lines(ecdf(data15), verticals=TRUE, do.points=FALSE, lwd=2, lty=3, col="blue", cex.lab=1.25, cex.axis=1.25)
lines(ecdf(data20), verticals=TRUE, do.points=FALSE, lwd=2, lty=4, col="black", cex.lab=1.25, cex.axis=1.25)

legend("bottomright", legend=c("data5", "data10", "data15", 
                               "data20"),
       col=c("red", "green", "blue", "black"), lwd=c(2,2,2,2),
       lty=c(1,2,3,4), cex=0.8, box.lty=0, bg=NA) 

retval <- dev.off()

