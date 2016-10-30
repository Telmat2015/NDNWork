# install.packages('ggplot2')
library(ggplot2)
# install.packages('scales')
library(scales)

# install.packages('doBy')
library(doBy)

#########################
# Rate trace processing #
#########################

data5 = read.table("/home/ardi/Desktop/Rinfix/load-balancer-500/load-balancer-l2trace-inherent-500-20s.txt", header=T)

data5$Node = factor(data5$Node)
data5$Kilobits <- data5$Kilobytes * 8
data5$Type = factor(data5$Type)
data5$Packets = factor(data5$Packets)
data5$KilobytesRaw = factor(data5$KilobytesRaw)
data5$Kilobits = factor(data5$Kilobits)
data5$PacketsRaw = factor(data5$PacketsRaw)


# graph rates on all nodes in Kilobits
g.all <- ggplot(data5, aes(x=Time, y=Kilobits, color=Type)) +
  geom_point(size=2) +
  geom_line() +
  ylab("Packet drop rate [Kbits/s]") +
  facet_wrap(~ Node) +
  theme_bw()

png("/home/ardi/Desktop/Rinfix/load-balancer-500/load-balancer-l2trace-inherent-500-20s.png", width=800, height=500)
print(g.all)
x = dev.off()
