
#  Grid scenario

This scenario (ndn-grid.cpp) simulates a grid topology, which is constructed using PointToPointLayout NS-3 module. FIB is populated using GlobalRoutingHelper (see ndnSIM helpers). The content store structure of NFD is used in all the nodes. Consumer is simulated using ConsumerCbr reference application and generates Interests towards the producer with frequency of 100 interests per second (see ndnSIM applications). Producer is simulated using Producer class, which is used to satisfy all incoming Interests with virtual payload data (1024 bytes).

The following code represents all that is necessary to run such a simple scenario
##### Tabel Of Content

   -  Assignment 1: <b>Simulation Simple </b>[[read] ](https://github.com/Telmat2015/NDNWork/blob/master/SecenarioNDN-Simple/Simulation-Simple.md) | [[discussion and source code]] (https://github.com/Telmat2015/NDNWork/blob/master/SecenarioNDN-Simple/ndn-simple.cpp)
   
   -  Assignment 2: <b>Simulation Simple 6 Node </b>[[read] ](https://github.com/Telmat2015/NDNWork/blob/master/SecenarioNDN-Simple/Simulation-Simple-6node.md) | [[discussion and source code]] (https://github.com/Telmat2015/NDNWork/blob/master/SecenarioNDN-Simple/simulation-simple-6node.py) | [[Output to LOG File]] (https://github.com/Telmat2015/NDNWork/blob/master/SecenarioNDN-Simple/LOG_Simple2.txt)
