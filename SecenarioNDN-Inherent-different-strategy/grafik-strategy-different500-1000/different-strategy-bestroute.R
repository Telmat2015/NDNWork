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
data$Kilobits <- data$Kilobytes * 8
data$Type = factor(data$Type)

# graph rates on all nodes in Kilobits
g.all <- ggplot(data, aes(x=Time, y=Kilobits, color=Type)) +
  geom_point(size=2) +
  geom_line() +
  ylab("Packet drop rate [Kbits/s]") +
  facet_wrap(~ Node) +
  theme_bw()
png("/home/ardi/R/ndn-multi-forwarding-strategy-inherent-per-prefix/different-strategy-bestroute-5s-1000Int.png", width=1280, height=720)

print(g.all)
x = dev.off()
