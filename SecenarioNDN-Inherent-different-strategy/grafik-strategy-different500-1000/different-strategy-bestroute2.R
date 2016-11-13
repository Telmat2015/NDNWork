# install.packages('ggplot2')
library(ggplot2)
# install.packages('scales')
library(scales)

# install.packages('doBy')
library(doBy)

#########################
# Rate trace processing #
#########################
data = read.table("/home/ardi/R/ndn-multi-forwarding-strategy-inherent-per-prefix/different-strategy-bestroute-5s-1000Int.txt", header=T)
data$Node = factor(data$Node)
data$DelayS <- data$DelayS
data$Type = factor(data$Type)

Node.palembang        = subset(data, Node %in% c("palembang"))

palembang<-Node.palembang$Packets
palembang<-Node.palembang$PacketsRaw
palembang<-Node.palembang$Kilobytes
palembang<-Node.palembang$KilobytesRaw

png("/home/ardi/R/ndn-multi-forwarding-strategy-inherent-per-prefix/different-strategy-bestroute-5s-1000Int-palembang", width=1280, height=720)

plot(ecdf(palembang), main=NA,  
     xlab="", ylab="",verticals = TRUE, do.points=FALSE, lwd=2, lty=1, col="red", cex.lab=1.25, cex.axis=1.25)

retval <- dev.off()

