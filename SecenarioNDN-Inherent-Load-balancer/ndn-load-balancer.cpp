#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/ndnSIM-module.h"

#include "ndn-load-balancer/random-load-balancer-strategy.hpp"

using namespace ns3;

using ns3::ndn::StackHelper;
using ns3::ndn::AppHelper;
using ns3::ndn::GlobalRoutingHelper;
using ns3::ndn::StrategyChoiceHelper;
using ns3::AnnotatedTopologyReader;

int
main(int argc, char* argv[])
{
  CommandLine cmd;
  cmd.Parse(argc, argv);

  AnnotatedTopologyReader topologyReader("", 25);
  topologyReader.SetFileName("/home/bertopeng17/ndnSIM/ns-3/src/ndnSIM/examples/topologies/topo-indonesia-inheren.txt");
  topologyReader.Read();

  // Install NDN stack on all nodes
  StackHelper ndnHelper;
  ndnHelper.InstallAll();

  // Installing global routing interface on all nodes
  GlobalRoutingHelper ndnGlobalRoutingHelper;
  ndnGlobalRoutingHelper.InstallAll();

  // Getting containers for the consumer/producer
  Ptr<Node> producer1 = Names::Find<Node>("jogjakarta");
  Ptr<Node> producer2 = Names::Find<Node>("banjarmasin");
  Ptr<Node> producer3 = Names::Find<Node>("malang");
  Ptr<Node> producer4 = Names::Find<Node>("makasar");

 


  NodeContainer consumerNodes;
  consumerNodes.Add(Names::Find<Node>("kupang"));


  // Install NDN applications
  std::string prefix = "/kupang/hello";


  // Install random-load-balancer forwarding strategy in
  // node Surabaya
  StrategyChoiceHelper::Install<nfd::fw::RandomLoadBalancerStrategy>(Names::Find<Node>("surabaya"),
                                                                     prefix);

  AppHelper consumerHelper("ns3::ndn::ConsumerCbr");
  consumerHelper.SetPrefix(prefix);
  consumerHelper.SetAttribute("Frequency", StringValue("1000")); // 500 interests a second
  consumerHelper.Install(consumerNodes);

  AppHelper producerHelper("ns3::ndn::Producer");
  producerHelper.SetPrefix(prefix);
  producerHelper.SetAttribute("PayloadSize", StringValue("1024"));
  producerHelper.Install(producer1);
  producerHelper.Install(producer2);
  producerHelper.Install(producer3);
  producerHelper.Install(producer4);



  // Add /prefix origins to ndn::GlobalRouter
  ndnGlobalRoutingHelper.AddOrigins(prefix, producer1);
  ndnGlobalRoutingHelper.AddOrigins(prefix, producer2);
  ndnGlobalRoutingHelper.AddOrigins(prefix, producer3);
  ndnGlobalRoutingHelper.AddOrigins(prefix, producer4);
 


  // Calculate and install FIBs
  GlobalRoutingHelper::CalculateRoutes();
  L2RateTracer::InstallAll("/home/bertopeng17/ndnSIM/ns-3/data-tracer-inherent/load-balancer-l2trace-inherent-1000-5s.txt");

  Simulator::Stop(Seconds(20.0));
  

  Simulator::Run();
  Simulator::Destroy();

  return 0;
}


