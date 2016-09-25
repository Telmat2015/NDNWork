### 1. Topology Simulation-Grid4x4

![alt tag](https://github.com/syaifulahdan/ndndlearn/blob/master/SecenarioNDN-Grid/image/Screenshot%20from%202016-09-25%2021-02-11.png)


### 2. Sourcecode Simulation-Grid4x4

<pre>
  <i><b>//  Creating 4x4 topology </b></i>
  PointToPointHelper p2p;
  PointToPointGridHelper grid(4, 4, p2p);
  grid.BoundingBox(100, 100, 200, 200);
</pre>


<pre>
<i><b>// Getting containers for the consumer/producer</b></i>
  Ptr<Node> producer = grid.GetNode(0, 0);
  NodeContainer consumerNodes;
  consumerNodes.Add(grid.GetNode(3, 3));
</pre>


<pre>

  ndn::AppHelper consumerHelper("ns3::ndn::ConsumerCbr");
  consumerHelper.SetPrefix(prefix);
  consumerHelper.SetAttribute("Frequency", StringValue("100")); <i><b>// 100 interests a second</b></i>
  consumerHelper.Install(consumerNodes);

</pre>


<pre>
  ndn::AppHelper producerHelper("ns3::ndn::Producer");
  producerHelper.SetPrefix(prefix);
  producerHelper.SetAttribute("PayloadSize", StringValue("1024"));
  producerHelper.Install(producer);
</pre>


### 3. Running Simulation All Node

![alt tag](https://github.com/syaifulahdan/ndndlearn/blob/master/SecenarioNDN-Grid/image/Screenshot%20from%202016-09-25%2022-09-51.png)


### 4. Running Simulation Selected Node

![alt tag](https://github.com/syaifulahdan/ndndlearn/blob/master/SecenarioNDN-Grid/image/Screenshot%20from%202016-09-25%2023-19-37.png)

![alt tag](https://github.com/syaifulahdan/ndndlearn/blob/master/SecenarioNDN-Grid/image/Screenshot%20from%202016-09-25%2023-13-45.png)

