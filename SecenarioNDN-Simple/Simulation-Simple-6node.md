
### Simulation-Simple-6node

<pre>
// Creating nodes
  NodeContainer nodes;
  nodes.Create(6);

  // Connecting nodes using two links
  PointToPointHelper p2p;
  p2p.Install(nodes.Get(0), nodes.Get(1));
  p2p.Install(nodes.Get(1), nodes.Get(2));
  p2p.Install(nodes.Get(2), nodes.Get(3));
  p2p.Install(nodes.Get(3), nodes.Get(4));
  p2p.Install(nodes.Get(4), nodes.Get(5));
</pre>
