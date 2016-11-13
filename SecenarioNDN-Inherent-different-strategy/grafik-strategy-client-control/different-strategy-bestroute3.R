# install.packages('ggplot2')
library(ggplot2)
# install.packages('scales')
library(scales)

# install.packages('doBy')
library(doBy)

#########################
# Rate trace processing #
#########################
data = read.table("/home/ardi/R/ndn-multi-forwarding-strategy-inherent-per-prefix/strategy-client-control/strategy-clientcontrol-5s.txt", header=T)
data$Node = factor(data$Node)
data$Kilobits <- data$Kilobytes * 8
data$Type = factor(data$Type)

# combine stats from all faces
data.combined = summaryBy(. ~ Time + Node + Type, data=data, FUN=sum)

data.pontianak = subset (data.combined, Node == "pontianak")
data.leaves = subset(data.combined, Node %in% c("kendari", "manado", "makasar", "pontianak", "palembang"))

# graph rates on all nodes in Kilobits
g.all <- ggplot(data.combined) +
  geom_point(aes (x=Time, y=Kilobits.sum, color=Type), size=1) +
  ylab("Rate [Kbits/s]") +
  facet_wrap(~ Node)

print(g.all)

# graph rates on the root nodes in Packets
g.pontianak <- ggplot(data.pontianak) +
  geom_point(aes (x=Time, y=Kilobits.sum, color=Type), size=2) +
  geom_line(aes (x=Time, y=Kilobits.sum, color=Type), size=0.5) +
  ylab("Rate [Kbits/s]")

print(g.pontianak)

png("/home/ardi/R/ndn-multi-forwarding-strategy-inherent-per-prefix/strategy-client-control/strategy-clientcontrol-pontianak2", width=1280, height=720)
print(g.pontianak)
retval <- dev.off()
