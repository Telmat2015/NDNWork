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
  topologyReader.SetFileName("/home/bertopeng17/ndnSIM/ns-3/src/ndnSIM/examples/topologies/topo-indonesia-inheren.txt");
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
  Ptr<Node> producer3 = Names::Find<Node>("makasar");
  Ptr<Node> producer4 = Names::Find<Node>("pontianak");
  Ptr<Node> producer5 = Names::Find<Node>("manado");
  Ptr<Node> consumer1 = Names::Find<Node>("banda-aceh");
  Ptr<Node> consumer2 = Names::Find<Node>("jkt-ui");
  Ptr<Node> consumer3 = Names::Find<Node>("kupang");
  Ptr<Node> consumer4 = Names::Find<Node>("surabaya");
  Ptr<Node> consumer5 = Names::Find<Node>("banjarmasin");
  // Define name prefixes
  std::string prefix1 = "ndn/palembang/makanan/pempek";
  std::string prefix2 = "ndn/malang/makanan/baksomalang";
  std::string prefix3 = "ndn/makasar/makanan/cotomakasar";
  std::string prefix4 = "ndn/pontianak/wisata/tugukatulistiwa";
  std::string prefix5 = "ndn/manado/wisata/bunaken";
  // Install different forwarding strategies for prefix1, prefix2,  prefix3 , prefix4,  prefix5
  StrategyChoiceHelper::InstallAll (prefix1, "/localhost/nfd/strategy/best-route");
  StrategyChoiceHelper::InstallAll (prefix2, "/localhost/nfd/strategy/best-route");
  StrategyChoiceHelper::InstallAll (prefix3, "/localhost/nfd/strategy/best-route");
  StrategyChoiceHelper::InstallAll (prefix4, "/localhost/nfd/strategy/best-route");
  StrategyChoiceHelper::InstallAll (prefix5, "/localhost/nfd/strategy/best-route");
  // Install NDN applications
  AppHelper consumerHelper("ns3::ndn::ConsumerCbr");
  consumerHelper.SetPrefix(prefix1);
  consumerHelper.SetAttribute("Frequency", StringValue("500")); // 500 interests a second
  consumerHelper.Install(consumer1);
  consumerHelper.SetPrefix(prefix2);
  consumerHelper.SetAttribute("Frequency", StringValue("500")); // 500 interests a second
  consumerHelper.Install(consumer2);
  consumerHelper.SetPrefix(prefix3);
  consumerHelper.SetAttribute("Frequency", StringValue("500")); // 500 interests a second
  consumerHelper.Install(consumer3);
  consumerHelper.SetPrefix(prefix4);
  consumerHelper.SetAttribute("Frequency", StringValue("500")); // 500 interests a second
  consumerHelper.Install(consumer4);
  consumerHelper.SetPrefix(prefix5);
  consumerHelper.SetAttribute("Frequency", StringValue("500")); // 500 interests a second
  consumerHelper.Install(consumer5);



  AppHelper producerHelper("ns3::ndn::Producer");
  producerHelper.SetPrefix(prefix1);
  producerHelper.SetAttribute("PayloadSize", StringValue("1024"));
  producerHelper.Install(producer1);

  producerHelper.SetPrefix(prefix2);
  producerHelper.Install(producer2);

  producerHelper.SetPrefix(prefix3);
  producerHelper.Install(producer3);

  producerHelper.SetPrefix(prefix4);
  producerHelper.Install(producer4);

  producerHelper.SetPrefix(prefix5);
  producerHelper.Install(producer5);

  // Add /prefix1 and /prefix2 origins to ndn::GlobalRouter
  ndnGlobalRoutingHelper.AddOrigins(prefix1, producer1);
  ndnGlobalRoutingHelper.AddOrigins(prefix2, producer2);
  ndnGlobalRoutingHelper.AddOrigins(prefix3, producer3);
  ndnGlobalRoutingHelper.AddOrigins(prefix4, producer4);
  ndnGlobalRoutingHelper.AddOrigins(prefix5, producer5);
  // Calculate and install FIBs
  GlobalRoutingHelper::CalculateRoutes();
  L2RateTracer::InstallAll("/home/bertopeng17/ndnSIM/ns-3/data-tracer-inherent/different-strategy-forwading/different-strategy-bestroute-5s.txt");

  Simulator::Stop(Seconds(05.0));
  

  Simulator::Run();
  Simulator::Destroy();

  return 0;
}


