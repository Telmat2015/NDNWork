
#  Simple scenario

The first example [<b>(ndn-simple.cpp)</b>](https://github.com/syaifulahdan/ndndlearn/blob/master/Simple-scenario-Coding/ndn-simple.cpp)  shows very basics of ndnSIM. In the simulated topology there are 3 nodes, connected with point-to-point links, one NDN consumer, and one NDN producer:

Consumer is simulated using  The first example [<b>(ConsumerCbr)</b>](http://ndnsim.net/2.0/doxygen/classns3_1_1ndn_1_1ConsumerCbr.html)reference application and generates Interests towards the producer with frequency of 10 Interests per second (see [<b>ndnSIM applications</b>](http://ndnsim.net/2.0/applications.html)).

Producer is simulated using [<b>(Producer)</b>](http://ndnsim.net/2.0/doxygen/classns3_1_1ndn_1_1Producer.html) class, which is used to satisfy all incoming Interests with virtual payload data (1024 bytes).FIB on every node is populated using default routes (see [<b>ndnSIM helpers</b>](http://ndnsim.net/2.0/helpers.html)) and the content store structure of the original ndnSIM is used. The following code represents all that is necessary to run such a simple scenario

##### Tabel Of Content

   -  Assignment 1: <b>Simulation Simple </b>[[read] ](https://github.com/Telmat2015/NDNWork/blob/master/SecenarioNDN-Simple/Simulation-Simple.md) | [[discussion and source code]] (https://github.com/Telmat2015/NDNWork/blob/master/SecenarioNDN-Simple/ndn-simple.cpp)
   
   -  Assignment 2: <b>Simulation Simple 6 Node </b>[[read] ](https://github.com/Telmat2015/NDNWork/blob/master/SecenarioNDN-Simple/Simulation-Simple-6node.md) | [[discussion and source code]] (https://github.com/Telmat2015/NDNWork/blob/master/SecenarioNDN-Simple/simulation-simple-6node.py) | [[Output to LOG File]] (https://github.com/Telmat2015/NDNWork/blob/master/SecenarioNDN-Simple/LOG_Simple2.txt)
