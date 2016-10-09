
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/ndnSIM-module.h"
#include "ns3/netanim-module.h"

namespace ns3 {

int
main(int argc, char* argv[])
{
  CommandLine cmd;
  cmd.Parse(argc, argv);

  AnnotatedTopologyReader topologyReader("", 25);
  topologyReader.SetFileName("src/ndnSIM/examples/topologies/topo-indonesia-inheren.txt");
  topologyReader.Read();

  // Install NDN stack on all nodes
  ndn::StackHelper ndnHelper;
  ndnHelper.InstallAll();

  // Set BestRoute strategy
  ndn::StrategyChoiceHelper::InstallAll("/", "/localhost/nfd/strategy/best-route");

  // Installing global routing interface on all nodes
  ndn::GlobalRoutingHelper ndnGlobalRoutingHelper;
  ndnGlobalRoutingHelper.InstallAll();

  //Getting containers for the consumer/producer
  Ptr<Node> producer = Names::Find<Node>("banda-aceh");
  NodeContainer consumerNodes;
  consumerNodes.Add(Names::Find<Node>("jayapura"));
  consumerNodes.Add(Names::Find<Node>("padang"));
  consumerNodes.Add(Names::Find<Node>("surabaya"));


  //Ptr<Node> consumers[6] = {Names::Find<Node>("medan"), Names::Find<Node>("pekanbaru"), Names::Find<Node>("palembang"),
                            //Names::Find<Node>("padang"), Names::Find<Node>("jambi"), Names::Find<Node>("bengkulu")};
  //Ptr<Node> producers[2] = {Names::Find<Node>("banda-aceh"), Names::Find<Node>("bandar-lampung")};

 


  // Install NDN applications
  std::string prefix = "/prefix";

  ndn::AppHelper consumerHelper("ns3::ndn::ConsumerCbr");
  consumerHelper.SetPrefix(prefix);
  consumerHelper.SetAttribute("Frequency", StringValue("100")); // 100 interests a second
  consumerHelper.Install(consumerNodes);

  ndn::AppHelper producerHelper("ns3::ndn::Producer");
  producerHelper.SetPrefix(prefix);
  producerHelper.SetAttribute("PayloadSize", StringValue("1024"));
  producerHelper.Install(producer);

  // Add /prefix origins to ndn::GlobalRouter
  ndnGlobalRoutingHelper.AddOrigins(prefix, producer);

  // Calculate and install FIBs
  ndn::GlobalRoutingHelper::CalculateRoutes();

  Simulator::Stop(Seconds(20.0));

AnimationInterface anim ("ndn-indonesia-inheren.xml");

anim.SetBackgroundImage("/home/ardi/Pictures/map_indo",2321.33,-269.49,0.77,0.80,0.5);


anim.UpdateNodeDescription (0, "banda-aceh");
anim.UpdateNodeDescription (1, "medan");
anim.UpdateNodeDescription (2, "padang");
anim.UpdateNodeDescription (3, "jambi");
anim.UpdateNodeDescription (4, "pekanbaru");
anim.UpdateNodeDescription (5, "bengkulu");
anim.UpdateNodeDescription (6, "palembang");
anim.UpdateNodeDescription (7, "Bandar lampung");
anim.UpdateNodeDescription (8, "serang");
anim.UpdateNodeDescription (9, "jkt-ui");
anim.UpdateNodeDescription (10, "jkt-dikti");
anim.UpdateNodeDescription (11, "bandung");
anim.UpdateNodeDescription (12, "semarang");
anim.UpdateNodeDescription (13, "jogjakarta");
anim.UpdateNodeDescription (14, "surabaya");
anim.UpdateNodeDescription (15, "malang");
anim.UpdateNodeDescription (16, "pontianak");
anim.UpdateNodeDescription (17, "palangkaraya");
anim.UpdateNodeDescription (18, "banjarmasin");
anim.UpdateNodeDescription (18, "samarinda");
anim.UpdateNodeDescription (19, "palangkaraya");
anim.UpdateNodeDescription (20, "gorontalo");
anim.UpdateNodeDescription (21, "manado");
anim.UpdateNodeDescription (22, "palu");
anim.UpdateNodeDescription (23, "makasar");
anim.UpdateNodeDescription (24, "kendari");
anim.UpdateNodeDescription (25, "denpasar");
anim.UpdateNodeDescription (26, "mataram");
anim.UpdateNodeDescription (27, "kupang");
anim.UpdateNodeDescription (28, "ternate");
anim.UpdateNodeDescription (29, "ambon");
anim.UpdateNodeDescription (30, "manokwari");
anim.UpdateNodeDescription (31, "jayapura");
anim.UpdateNodeDescription (32, "host");

anim.UpdateNodeColor (32, 0, 255, 0);
anim.UpdateNodeSize (32, 40, 40);

anim.UpdateNodeSize (0, 10, 10);
anim.UpdateNodeSize (1, 10, 10);
anim.UpdateNodeSize (2, 10, 10);
anim.UpdateNodeSize (3, 10, 10);
anim.UpdateNodeSize (4, 10, 10);
anim.UpdateNodeSize (5, 10, 10);
anim.UpdateNodeSize (6, 10, 10);
anim.UpdateNodeSize (7, 10, 10);
anim.UpdateNodeSize (8, 10, 10);
anim.UpdateNodeSize (9, 10, 10);
anim.UpdateNodeSize (10, 10, 10);
anim.UpdateNodeSize (11, 10, 10);
anim.UpdateNodeSize (12, 10, 10);
anim.UpdateNodeSize (13, 10, 10);
anim.UpdateNodeSize (14, 10, 10);
anim.UpdateNodeSize (15, 10, 10);
anim.UpdateNodeSize (16, 10, 10);
anim.UpdateNodeSize (17, 10, 10);
anim.UpdateNodeSize (18, 10, 10);
anim.UpdateNodeSize (19, 10, 10);
anim.UpdateNodeSize (20, 10, 10);
anim.UpdateNodeSize (21, 10, 10);
anim.UpdateNodeSize (22, 10, 10);
anim.UpdateNodeSize (23, 10, 10);
anim.UpdateNodeSize (24, 10, 10);
anim.UpdateNodeSize (25, 10, 10);
anim.UpdateNodeSize (26, 10, 10);
anim.UpdateNodeSize (27, 10, 10);
anim.UpdateNodeSize (28, 10, 10);
anim.UpdateNodeSize (29, 10, 10);
anim.UpdateNodeSize (30, 10, 10);
anim.UpdateNodeSize (31, 10, 10);




  Simulator::Run();
  Simulator::Destroy();

  return 0;
}

} // namespace ns3

int
main(int argc, char* argv[])
{
  return ns3::main(argc, argv);
}
