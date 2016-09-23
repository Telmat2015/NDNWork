
### 1. Topology Simulation-Simple-6node

![alt tag](https://github.com/syaifulahdan/ndndlearn/blob/master/SecenarioNDN-Simple/image/Screenshot%20from%202016-09-22%2022-57-38.png)



### 2. Sourcecode Simulation-Simple-6node


<pre>
  <i><b>// Creating nodes</b></i>
  NodeContainer nodes;
  nodes.Create(6);
</pre>
  
<pre>  
  <i><b>// Connecting nodes using 5 links</b></i>

  PointToPointHelper p2p;
  p2p.Install(nodes.Get(0), nodes.Get(1));
  p2p.Install(nodes.Get(1), nodes.Get(2));
  p2p.Install(nodes.Get(2), nodes.Get(3));
  p2p.Install(nodes.Get(3), nodes.Get(4));
  p2p.Install(nodes.Get(4), nodes.Get(5));
</b>
</pre>

<pre>

  <i><b>// Consumer</b></i>
  ndn::AppHelper consumerHelper("ns3::ndn::ConsumerCbr");
  <i><b>// Consumer will request /prefix/0, /prefix/1, ...</i></b>
  consumerHelper.SetPrefix("/prefix");
  consumerHelper.SetAttribute("Frequency", StringValue("100"));<b> // 100 interests a second</b>
  consumerHelper.Install(nodes.Get(0));<b>// first node</b>
</pre>

<pre>
  <i><b>// Producer</b></i>
  ndn::AppHelper producerHelper("ns3::ndn::Producer");
  <i><b>// Producer will reply to all requests starting with /prefix</b></i>
  producerHelper.SetPrefix("/prefix");
  producerHelper.SetAttribute("PayloadSize", StringValue("1024"));
  producerHelper.Install(nodes.Get(5)); <i><b>// last node</b></i>
</pre>

### 3. Running Simulation All Node

![alt tag](https://github.com/syaifulahdan/ndndlearn/blob/master/SecenarioNDN-Simple/image/Screenshot%20from%202016-09-22%2023-49-37.png)


### 4. Running Simulation Selected Node

![alt tag](https://github.com/syaifulahdan/ndndlearn/blob/master/SecenarioNDN-Simple/image/Screenshot%20from%202016-09-23%2000-19-43.png)

![alt tag](https://github.com/syaifulahdan/ndndlearn/blob/master/SecenarioNDN-Simple/image/Screenshot%20from%202016-09-23%2000-23-21.png)


### 4. Running Simulation with LOG Model

<pre>
root@bertopeng17-ThinkPad-T520:/home/bertopeng17/ndnSIM/ns-3#  <b>NS_LOG=ndn.Producer:ndn.Consumer ./waf --run=ndn-simple2</b>
</pre>

<b>output</b>
<pre>
0s -1 ndn.Consumer:Consumer()
0s -1 ndn.Producer:Producer()
0s 0 ndn.Consumer:StartApplication()
0s 5 ndn.Producer:StartApplication()
0s 0 ndn.Consumer:SendPacket()
0s 0 ndn.Consumer:SendPacket(): [INFO ] > Interest for 0
0s 0 ndn.Consumer:WillSendOutInterest(): [DEBUG] Trying to add 0 with +0.0ns. already 0 items
0.01s 0 ndn.Consumer:SendPacket()
0.01s 0 ndn.Consumer:SendPacket(): [INFO ] > Interest for 1
0.01s 0 ndn.Consumer:WillSendOutInterest(): [DEBUG] Trying to add 1 with +10000000.0ns. already 1 items
0.02s 0 ndn.Consumer:SendPacket()
0.02s 0 ndn.Consumer:SendPacket(): [INFO ] > Interest for 2
0.02s 0 ndn.Consumer:WillSendOutInterest(): [DEBUG] Trying to add 2 with +20000000.0ns. already 2 items
0.03s 0 ndn.Consumer:SendPacket()
0.03s 0 ndn.Consumer:SendPacket(): [INFO ] > Interest for 3
0.03s 0 ndn.Consumer:WillSendOutInterest(): [DEBUG] Trying to add 3 with +30000000.0ns. already 3 items
0.04s 0 ndn.Consumer:SendPacket()
0.04s 0 ndn.Consumer:SendPacket(): [INFO ] > Interest for 4
0.04s 0 ndn.Consumer:WillSendOutInterest(): [DEBUG] Trying to add 4 with +40000000.0ns. already 4 items
0.05s 0 ndn.Consumer:SendPacket()
|
|
|
|
99.99s 0 ndn.Consumer:WillSendOutInterest(): [DEBUG] Trying to add 9999 with +99990000000.0ns. already 14 items
99.9912s 5 ndn.Producer:OnInterest(0x9835f58, 0x98f847c)
99.9912s 5 ndn.Producer:OnInterest(): [INFO ] node(5) responding with Data: /prefix/%FE%27%0A
99.9936s 0 ndn.Consumer:OnData(0x984b408, 0xa0b8ba4)
99.9936s 0 ndn.Consumer:OnData(): [INFO ] < DATA for 9985
99.9936s 0 ndn.Consumer:OnData(): [DEBUG] Hop count: 5
</pre>
