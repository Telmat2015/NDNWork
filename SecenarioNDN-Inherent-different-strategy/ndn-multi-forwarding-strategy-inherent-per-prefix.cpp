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


  Ptr<Node> consumer1 = Names::Find<Node>("banda-aceh");
  Ptr<Node> consumer2 = Names::Find<Node>("jkt-ui");

  // Install NDN applications
  std::string prefix1 = "/prefix1";
  std::string prefix2 = "/prefix2";
 
 

 /* // Install different forwarding strategies
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      if (row < 2)
        StrategyChoiceHelper::Install (Names::Find<Node> ("serang"), "/prefix",
                                      "/localhost/nfd/strategy/best-route");
      else
        StrategyChoiceHelper::Install(Names::Find<Node> ("jayapura"), "/prefix",
                                      "/localhost/nfd/strategy/multicast");
    }
  }
*/


  // Install different forwarding strategies for prefix1, prefix2
  StrategyChoiceHelper::InstallAll(prefix1, "/localhost/nfd/strategy/multicast");
  StrategyChoiceHelper::InstallAll(prefix2, "/localhost/nfd/strategy/best-route");



  
  AppHelper consumerHelper("ns3::ndn::ConsumerCbr");
  consumerHelper.SetPrefix(prefix1);
  consumerHelper.SetAttribute("Frequency", StringValue("500")); // 500 interests a second
  consumerHelper.Install(consumer1);

  consumerHelper.SetPrefix(prefix2);
  consumerHelper.Install(consumer2);


  AppHelper producerHelper("ns3::ndn::Producer");
  producerHelper.SetPrefix(prefix1);
  producerHelper.SetAttribute("PayloadSize", StringValue("1024"));
  producerHelper.Install(producer1);

  producerHelper.SetPrefix(prefix2);
  producerHelper.Install(producer2);


  // Add /prefix1 and /prefix2 origins to ndn::GlobalRouter
  ndnGlobalRoutingHelper.AddOrigins(prefix1, producer1);
  ndnGlobalRoutingHelper.AddOrigins(prefix2, producer2);

  // Calculate and install FIBs
  GlobalRoutingHelper::CalculateRoutes();
  L2RateTracer::InstallAll("/home/ardi/ndnSIM/ns-3/load-balancer-l2trace-inherent-1000-5s.txt");

  Simulator::Stop(Seconds(05.0));
  

  Simulator::Run();
  Simulator::Destroy();

  return 0;
}


