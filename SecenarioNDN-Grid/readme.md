
#  Grid scenario

This scenario (ndn-grid.cpp) simulates a grid topology, which is constructed using PointToPointLayout NS-3 module. FIB is populated using [GlobalRoutingHelper ](http://ndnsim.net/2.0/doxygen/classns3_1_1ndn_1_1GlobalRoutingHelper.html) ( see [ndnSIM helpers ](http://ndnsim.net/2.0/helpers.html)). The content store structure of NFD is used in all the nodes. Consumer is simulated using [ConsumerCbr ](http://ndnsim.net/2.0/doxygen/classns3_1_1ndn_1_1GlobalRoutingHelper.html) reference application and generates Interests towards the producer with frequency of 100 interests per second ( see [ndnSIM ndnSIM applications ](http://ndnsim.net/2.0/applications.html)). Producer is simulated using  [GlobalRoutingHelper ](http://ndnsim.net/2.0/doxygen/classns3_1_1ndn_1_1Producer.html)class, which is used to satisfy all incoming Interests with virtual payload data (1024 bytes).

The following code represents all that is necessary to run such a simple scenario
##### Tabel Of Content

   -  Assignment 1: <b>Simulation Grid 9 Node </b>[[read] ](https://github.com/Telmat2015/NDNWork/blob/master/SecenarioNDN-Grid/Simulation%20Secenario%20NDNSim-grid.md) | [[discussion and source code]] (https://github.com/Telmat2015/NDNWork/blob/master/SecenarioNDN-Simple/ndn-simple.cpp)
   
   -  Assignment 2: <b>Simulation Grid 16 Node </b>[[read] ](https://github.com/Telmat2015/NDNWork/blob/master/SecenarioNDN-Grid/Simulation%20Secenario%20NDNSim-grid4x4.md) | [[discussion and source code]] (https://github.com/Telmat2015/NDNWork/blob/master/SecenarioNDN-Simple/simulation-simple-6node.py) | [[Output to LOG File]] (https://github.com/Telmat2015/NDNWork/blob/master/SecenarioNDN-Simple/LOG_Simple2.txt)
