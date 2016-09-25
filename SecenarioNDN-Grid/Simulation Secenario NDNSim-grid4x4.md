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
