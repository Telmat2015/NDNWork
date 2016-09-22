
### Simulation-Simple-6node

<pre>
  <i>// Creating nodes</i>
  NodeContainer nodes;
  nodes.Create(6);
  
  
  // Connecting nodes using two links

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
