#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/ndnSIM-module.h"

using namespace ns3;
using ns3::ndn::StackHelper;
using ns3::ndn::AppHelper;
using ns3::ndn::GlobalRoutingHelper;
using ns3::ndn::StrategyChoiceHelper;

int
main(int argc, char* argv[])
{
  CommandLine cmd;
  cmd.Parse(argc, argv);

  AnnotatedTopologyReader topologyReader("", 25);
  topologyReader.SetFileName("/home/ardi/ndnSIM/ns-3/src/ndnSIM/examples/topologies/topo-indonesia-inheren.txt");
  topologyReader.Read();

  // Install NDN stack on all nodes
  StackHelper ndnHelper;
  ndnHelper.InstallAll();

  // Installing global routing interface on all nodes
  GlobalRoutingHelper ndnGlobalRoutingHelper;
  ndnGlobalRoutingHelper.InstallAll();

  // Getting containers for the consumer/producer
  Ptr<Node> producer1 = Names::Find<Node>("palembang");
  Ptr<Node> producer2 = Names::Find<Node>("malang");
  Ptr<Node> producer3 = Names::Find<Node>("manado");
  Ptr<Node> producer4 = Names::Find<Node>("palangkaraya");
  Ptr<Node> producer5 = Names::Find<Node>("jayapura");


  Ptr<Node> consumer1 = Names::Find<Node>("banda-aceh");
  Ptr<Node> consumer2 = Names::Find<Node>("jkt-ui");
  Ptr<Node> consumer3 = Names::Find<Node>("pontianak");
  Ptr<Node> consumer4 = Names::Find<Node>("makasar");
  Ptr<Node> consumer5 = Names::Find<Node>("host");

  // Install NDN applications
  std::string prefix = "/prefix";
 

// Install different forwarding strategies
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      if (row < 2)
        StrategyChoiceHelper::Install (Names::Find<Node> (""), "/prefix",
                                      "/localhost/nfd/strategy/best-route");
      else
        StrategyChoiceHelper::Install(Names::Find<Node> (""), "/prefix",
                                      "/localhost/nfd/strategy/multicast");
    }
  }

  
  AppHelper consumerHelper("ns3::ndn::ConsumerCbr");
  consumerHelper.SetPrefix(prefix);
  consumerHelper.SetAttribute("Frequency", StringValue("500")); // 500 interests a second
  consumerHelper.Install(consumer1);
  consumerHelper.Install(consumer2);
  consumerHelper.Install(consumer3);
  consumerHelper.Install(consumer4);
  consumerHelper.Install(consumer5);



  AppHelper producerHelper("ns3::ndn::Producer");
  producerHelper.SetPrefix(prefix);
  producerHelper.SetAttribute("PayloadSize", StringValue("1024"));
  producerHelper.Install(producer1);
  producerHelper.Install(producer2);
  producerHelper.Install(producer3);
  producerHelper.Install(producer4);
  producerHelper.Install(producer5);


  // Add /prefix1 and /prefix2 origins to ndn::GlobalRouter
  ndnGlobalRoutingHelper.AddOrigins(prefix, producer1);
  ndnGlobalRoutingHelper.AddOrigins(prefix, producer2);
  ndnGlobalRoutingHelper.AddOrigins(prefix, producer3);
  ndnGlobalRoutingHelper.AddOrigins(prefix, producer4);
  ndnGlobalRoutingHelper.AddOrigins(prefix, producer5);

  // Calculate and install FIBs
  //GlobalRoutingHelper::CalculateRoutes();
  //L2RateTracer::InstallAll("/home/ardi/ndnSIM/ns-3/load-balancer-l2trace-inherent-1000-5s.txt");

  Simulator::Stop(Seconds(5.0));
  

  Simulator::Run();
  Simulator::Destroy();

  return 0;
}


