
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
