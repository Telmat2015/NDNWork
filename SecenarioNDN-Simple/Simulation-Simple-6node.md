
### Simulation-Simple-6node



![alt tag](https://github.com/syaifulahdan/ndndlearn/blob/master/Simple-scenario-Coding/Simulation-Simple-6node.md/image/Screenshot%20from%202016-09-22%2022-21-52.png)


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


 // Consumer
 <b> ndn::AppHelper consumerHelper("ns3::ndn::ConsumerCbr");</b>
  // Consumer will request /prefix/0, /prefix/1, ...
  <b>consumerHelper.SetPrefix("/prefix");</b>
  <b>consumerHelper.SetAttribute("Frequency", StringValue("10"));</b> // 10 interests a second
  <b>consumerHelper.Install(nodes.Get(0));</b>                        // first node
