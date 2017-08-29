// ndn-simple.cpp

#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/ndnSIM-module.h"

namespace ns3 {

int
main(int argc, char* argv[])
{
  // setting default parameters for PointToPoint links and channels
  Config::SetDefault("ns3::PointToPointNetDevice::DataRate", StringValue("1024Mbps"));
  Config::SetDefault("ns3::PointToPointChannel::Delay", StringValue("1ms"));
  Config::SetDefault("ns3::DropTailQueue::MaxPackets", StringValue("20"));

  // Read optional command-line parameters (e.g., enable visualizer with ./waf --run=<> --visualize
  CommandLine cmd;
  cmd.Parse(argc, argv);

  // Creating nodes
  NodeContainer nodes;
  nodes.Create(147);

  // Connecting nodes using two links
  PointToPointHelper p2p;
  //link area sumatera
  p2p.Install(nodes.Get(0), nodes.Get(1)); //sabang-> aceh
  p2p.Install(nodes.Get(1), nodes.Get(2)); //aceh-> lhokseumawe
  p2p.Install(nodes.Get(1), nodes.Get(3)); //aceh-> blangpidie
  p2p.Install(nodes.Get(3), nodes.Get(4)); //blangpidie -> simeleu
  p2p.Install(nodes.Get(4), nodes.Get(7)); //simeleu-> gunungsitoli
  p2p.Install(nodes.Get(2), nodes.Get(5)); //lhokseumawe -> medan
  p2p.Install(nodes.Get(5), nodes.Get(3)); //medan -> blangpidie
  p2p.Install(nodes.Get(5), nodes.Get(6)); //medan -> singkil
  p2p.Install(nodes.Get(6), nodes.Get(7)); //singkil -> gunungsitoli
  p2p.Install(nodes.Get(7), nodes.Get(9)); //gunungsitoli -> mentawai
  p2p.Install(nodes.Get(6), nodes.Get(8)); //singkil -> padang
  p2p.Install(nodes.Get(8), nodes.Get(9)); //padang -> mentawai
  p2p.Install(nodes.Get(8), nodes.Get(10)); //padang -> pekanbaru
  p2p.Install(nodes.Get(8), nodes.Get(20)); //padang -> bengkulu
  p2p.Install(nodes.Get(10), nodes.Get(5)); //pekanbaru -> medan
  p2p.Install(nodes.Get(10), nodes.Get(11)); //pekanbaru -> bengkalis
  p2p.Install(nodes.Get(11), nodes.Get(13)); //bengkalis -> batam
  p2p.Install(nodes.Get(11), nodes.Get(15)); //bengkalis -> singapore
  p2p.Install(nodes.Get(13), nodes.Get(15)); //batam -> singapore
  p2p.Install(nodes.Get(13), nodes.Get(12)); //batam -> kepmeranti
  p2p.Install(nodes.Get(13), nodes.Get(16)); //batam -> tarempa
  p2p.Install(nodes.Get(13), nodes.Get(46)); //batam -> pontianak
  p2p.Install(nodes.Get(13), nodes.Get(14)); //batam -> lingga
  p2p.Install(nodes.Get(13), nodes.Get(23)); //batam -> pulaubangka
  p2p.Install(nodes.Get(16), nodes.Get(17)); //tarempa -> natuna
  p2p.Install(nodes.Get(10), nodes.Get(18)); //pekanbaru -> jambi
  p2p.Install(nodes.Get(18), nodes.Get(19)); //jambi -> palembang
  p2p.Install(nodes.Get(19), nodes.Get(22)); //palembang -> baturaja
  p2p.Install(nodes.Get(19), nodes.Get(23)); //palembang -> pulaubangka
  p2p.Install(nodes.Get(23), nodes.Get(27)); //pulaubangka -> jakarta
  p2p.Install(nodes.Get(22), nodes.Get(25)); //baturaja -> lampung
  p2p.Install(nodes.Get(22), nodes.Get(21)); //baturaja -> pagaralam
  p2p.Install(nodes.Get(21), nodes.Get(20)); //pagaralam -> bengkulu
  p2p.Install(nodes.Get(25), nodes.Get(20)); //lampung -> bengkulu
  //link area sumatera
  p2p.Install(nodes.Get(26), nodes.Get(25)); //serang -> lampung
  p2p.Install(nodes.Get(26), nodes.Get(27)); //serang -> jakarta
  p2p.Install(nodes.Get(27), nodes.Get(28)); //jakarta -> kseribu
  p2p.Install(nodes.Get(27), nodes.Get(31)); //jakarta -> cirebon
  p2p.Install(nodes.Get(27), nodes.Get(30)); //jakarta -> subangopt1
  p2p.Install(nodes.Get(30), nodes.Get(31)); //subangopt1 -> cirebon
  p2p.Install(nodes.Get(30), nodes.Get(29)); //subangopt1 -> bandung
  p2p.Install(nodes.Get(31), nodes.Get(32)); //cirebon -> pklonganopt2
  p2p.Install(nodes.Get(32), nodes.Get(34)); //pklonganopt2-> semarang
  p2p.Install(nodes.Get(32), nodes.Get(33)); //pklonganopt2-> purwokerto
  p2p.Install(nodes.Get(33), nodes.Get(35)); //purwokerto-> jogjakarta
  p2p.Install(nodes.Get(35), nodes.Get(34)); //jogjakarta-> semarang
  p2p.Install(nodes.Get(35), nodes.Get(36)); //jogjakarta-> gunungkidul
  p2p.Install(nodes.Get(35), nodes.Get(37)); //jogjakarta-> ponorogo
  p2p.Install(nodes.Get(37), nodes.Get(38)); //ponorogo-> surabaya
  p2p.Install(nodes.Get(38), nodes.Get(34)); //surabaya-> semarang 
  p2p.Install(nodes.Get(38), nodes.Get(82)); //surabaya-> makasar
  p2p.Install(nodes.Get(38), nodes.Get(39)); //surabaya-> malang
  p2p.Install(nodes.Get(39), nodes.Get(41)); //malang-> probolinggo
  p2p.Install(nodes.Get(41), nodes.Get(40)); //probolinggo-> situbondo
  p2p.Install(nodes.Get(41), nodes.Get(42)); //probolinggo-> banyuwangi
  p2p.Install(nodes.Get(42), nodes.Get(44)); //banyuwangi-> denpasar
  p2p.Install(nodes.Get(40), nodes.Get(43)); //situbondo-> karangasem
  p2p.Install(nodes.Get(43), nodes.Get(45)); //karangasem-> mataram
  p2p.Install(nodes.Get(43), nodes.Get(44)); //karangasem-> denpasar
  //link area kalimantan
  p2p.Install(nodes.Get(46), nodes.Get(47)); //pontianak -> semitau
  p2p.Install(nodes.Get(46), nodes.Get(24)); //pontianak -> pulaubelitung
  p2p.Install(nodes.Get(24), nodes.Get(27)); //pulaubelitung -> jakarta
  p2p.Install(nodes.Get(46), nodes.Get(49)); //pontianak -> javaseaopt1
  p2p.Install(nodes.Get(49), nodes.Get(48)); //javaseaopt1 -> ketapang
  p2p.Install(nodes.Get(49), nodes.Get(50)); //javaseaopt1 -> javaseaopt2
  p2p.Install(nodes.Get(50), nodes.Get(51)); //javaseaopt2 -> palangkaraya
  p2p.Install(nodes.Get(50), nodes.Get(52)); //javaseaopt2 -> banjarmasin
  p2p.Install(nodes.Get(52), nodes.Get(53)); //banjarmasin -> tanahgrogot
  p2p.Install(nodes.Get(53), nodes.Get(56)); //tanahgrogot -> kutaibarat
  p2p.Install(nodes.Get(53), nodes.Get(54)); //tanahgrogot -> balikpapan
  p2p.Install(nodes.Get(54), nodes.Get(55)); //balikpapan -> samarinda
  p2p.Install(nodes.Get(55), nodes.Get(57)); //samarinda -> tebangan
  p2p.Install(nodes.Get(57), nodes.Get(58)); //tebangan -> tarakan
  p2p.Install(nodes.Get(58), nodes.Get(59)); //tarakan -> nunukan
  p2p.Install(nodes.Get(58), nodes.Get(60)); //tarakan -> bunyu
  p2p.Install(nodes.Get(52), nodes.Get(38)); //banjarmasin -> surabaya
  p2p.Install(nodes.Get(52), nodes.Get(82)); //banjarmasin -> makasar
  p2p.Install(nodes.Get(57), nodes.Get(61)); //tebangan -> donggala
  //link area kalimantan
  p2p.Install(nodes.Get(61), nodes.Get(62)); //donggala -> tolitoliopt1
  p2p.Install(nodes.Get(61), nodes.Get(64)); //donggala -> morowaliopt2
  p2p.Install(nodes.Get(61), nodes.Get(69)); //donggala -> torajaopt4
  p2p.Install(nodes.Get(62), nodes.Get(65)); //tolitoliopt1 -> gorontalo
  p2p.Install(nodes.Get(62), nodes.Get(63)); //tolitoliopt1 -> poso
  p2p.Install(nodes.Get(65), nodes.Get(66)); //gorontalo -> manado
  p2p.Install(nodes.Get(66), nodes.Get(71)); //manado -> kotamobogu
  p2p.Install(nodes.Get(66), nodes.Get(72)); //manado -> ondongsiau
  p2p.Install(nodes.Get(72), nodes.Get(73)); //ondongsiau -> tahuna
  p2p.Install(nodes.Get(73), nodes.Get(74)); //tahuna -> talaud
  p2p.Install(nodes.Get(73), nodes.Get(90)); //tahuna -> bandaseaopt4
  p2p.Install(nodes.Get(71), nodes.Get(67)); //kotamobagu -> luwuk
  p2p.Install(nodes.Get(67), nodes.Get(70)); //luwuk -> banggai
  p2p.Install(nodes.Get(67), nodes.Get(64)); //luwuk -> morowaliopt2
  p2p.Install(nodes.Get(64), nodes.Get(68)); //morowaliopt2 -> boneopt3
  p2p.Install(nodes.Get(68), nodes.Get(69)); //boneopt3 -> torajaopt4
  p2p.Install(nodes.Get(68), nodes.Get(75)); //boneopt3 -> kendari
  p2p.Install(nodes.Get(69), nodes.Get(81)); //torajaopt4 -> parepare
  p2p.Install(nodes.Get(69), nodes.Get(82)); //torajaopt4 -> makasar
  p2p.Install(nodes.Get(81), nodes.Get(82)); //parepare -> makasar
  p2p.Install(nodes.Get(82), nodes.Get(83)); //makasar -> selayar
  p2p.Install(nodes.Get(82), nodes.Get(100)); //makasar -> ende
  p2p.Install(nodes.Get(75), nodes.Get(78)); //kendari -> baubau
  p2p.Install(nodes.Get(76), nodes.Get(77)); //bombana -> muna
  p2p.Install(nodes.Get(77), nodes.Get(78)); //muna -> baubau
  p2p.Install(nodes.Get(78), nodes.Get(80)); //baubau -> wakatobi
  p2p.Install(nodes.Get(78), nodes.Get(79)); //baubau -> burangga
  //link area maluku
  p2p.Install(nodes.Get(84), nodes.Get(75)); //ambon -> kendari
  p2p.Install(nodes.Get(84), nodes.Get(85)); //ambon -> serambarat
  p2p.Install(nodes.Get(84), nodes.Get(116)); //ambon -> fakfak
  p2p.Install(nodes.Get(84), nodes.Get(87)); //ambon -> bandaseaopt1
  p2p.Install(nodes.Get(87), nodes.Get(86)); //bandaseaopt1 -> pulauburu
  p2p.Install(nodes.Get(87), nodes.Get(88)); //bandaseaopt1 -> bandaseaopt2
  p2p.Install(nodes.Get(88), nodes.Get(111)); //bandaseaopt2 -> sorong
  p2p.Install(nodes.Get(88), nodes.Get(89)); //bandaseaopt2 -> bandaseaopt3
  p2p.Install(nodes.Get(89), nodes.Get(94)); //bandaseaopt3 -> palamea
  p2p.Install(nodes.Get(89), nodes.Get(90)); //bandaseaopt3 -> bandaseaopt4
  p2p.Install(nodes.Get(90), nodes.Get(91)); //bandaseaopt4 -> ternate
  p2p.Install(nodes.Get(91), nodes.Get(92)); //ternate -> halmaheratim
  p2p.Install(nodes.Get(91), nodes.Get(93)); //ternate -> pulaumorotai
  //link area nusatenggara
  p2p.Install(nodes.Get(99), nodes.Get(100)); //labuhanbajo -> ende
  p2p.Install(nodes.Get(100), nodes.Get(102)); //ende -> savuseaopt1
  p2p.Install(nodes.Get(102), nodes.Get(101)); //savuseaopt1 -> waingapu
  p2p.Install(nodes.Get(102), nodes.Get(98)); //savuseaopt1 -> bima
  p2p.Install(nodes.Get(98), nodes.Get(45)); //bima -> mataram
  p2p.Install(nodes.Get(100), nodes.Get(107)); //ende -> larantuka
  p2p.Install(nodes.Get(100), nodes.Get(103)); //ende -> kupang
  p2p.Install(nodes.Get(103), nodes.Get(105)); //kupang -> pulaurote
  p2p.Install(nodes.Get(105), nodes.Get(104)); //pulaurote -> seba
  p2p.Install(nodes.Get(103), nodes.Get(106)); //kupang -> atambua
  p2p.Install(nodes.Get(106), nodes.Get(109)); //atambua -> pulaualor
  p2p.Install(nodes.Get(109), nodes.Get(107)); //pulaualor -> larantuka
  p2p.Install(nodes.Get(109), nodes.Get(108)); //pulaualor -> tiakur
  p2p.Install(nodes.Get(107), nodes.Get(100)); //larantuka -> ende
  //link area papua
  p2p.Install(nodes.Get(110), nodes.Get(111));   //rajaampat-> sorong
  p2p.Install(nodes.Get(111), nodes.Get(112)); //sorong -> teminabuan
  p2p.Install(nodes.Get(111), nodes.Get(118)); //sorong -> pulaunum
  p2p.Install(nodes.Get(111), nodes.Get(115)); //sorong -> telukbintuni
  p2p.Install(nodes.Get(112), nodes.Get(113)); //teminabuan> kumurkek
  p2p.Install(nodes.Get(113), nodes.Get(114)); //kumurkek -> tabrauw  
  p2p.Install(nodes.Get(118), nodes.Get(110)); //pulaunum -> rajaampat  
  p2p.Install(nodes.Get(118), nodes.Get(120)); //pulaunum -> pacificopt1 
  p2p.Install(nodes.Get(120), nodes.Get(121)); //pacificopt1-> teba  
  p2p.Install(nodes.Get(120), nodes.Get(137)); //pacificopt1-> jayapura
  p2p.Install(nodes.Get(137), nodes.Get(139)); //jayapura -> keerom
  p2p.Install(nodes.Get(139), nodes.Get(138)); //keerom -> yalimo
  p2p.Install(nodes.Get(138), nodes.Get(143)); //yalimo -> pegbintang  
  p2p.Install(nodes.Get(143), nodes.Get(144)); //pegbintang-> tanahmerah  
  p2p.Install(nodes.Get(144), nodes.Get(146)); //tanahmerah-> merauke  
  p2p.Install(nodes.Get(144), nodes.Get(145)); //tanahmerah-> keppimappi
  p2p.Install(nodes.Get(145), nodes.Get(135)); //keppimappi-> agats 
  p2p.Install(nodes.Get(134), nodes.Get(135)); //arafuruopt2-> agats 
  p2p.Install(nodes.Get(134), nodes.Get(133)); //arafuruopt2-> timika  
  p2p.Install(nodes.Get(134), nodes.Get(146)); //arafuruopt2-> merauke  
  p2p.Install(nodes.Get(133), nodes.Get(96)); //timika -> aru
  p2p.Install(nodes.Get(133), nodes.Get(116)); //timika -> fakfak
  p2p.Install(nodes.Get(96), nodes.Get(95)); //aru -> tual  
  p2p.Install(nodes.Get(96), nodes.Get(97)); //aru -> seumlaki  
  p2p.Install(nodes.Get(97), nodes.Get(108)); //seumlaki-> tiakur  
  p2p.Install(nodes.Get(143), nodes.Get(142)); //pegbintang-> yahukimo  
  p2p.Install(nodes.Get(143), nodes.Get(138)); //pegbintang-> yalimo 
  p2p.Install(nodes.Get(142), nodes.Get(139)); //yahukimo -> keerom  
  p2p.Install(nodes.Get(125), nodes.Get(119)); //telukwondama -> pacificopt3  
  p2p.Install(nodes.Get(119), nodes.Get(118)); //pacificopt3 -> pulaunum  
  p2p.Install(nodes.Get(118), nodes.Get(117)); //pulaunum-> supiori
  p2p.Install(nodes.Get(119), nodes.Get(122)); //pacificopt3->pulauyapen
  p2p.Install(nodes.Get(122), nodes.Get(117)); //pulauyapen -> supiori  
  p2p.Install(nodes.Get(123), nodes.Get(124)); //waropen -> membramoraya  
  p2p.Install(nodes.Get(123), nodes.Get(127)); //waropen -> nabire  
  p2p.Install(nodes.Get(127), nodes.Get(126)); //nabire -> dogiyai  
  p2p.Install(nodes.Get(127), nodes.Get(128)); //nabire -> intanjaya  
  p2p.Install(nodes.Get(128), nodes.Get(132)); //intanjaya -> enorotali
  p2p.Install(nodes.Get(128), nodes.Get(130)); //intanjaya -> puncakjaya
  p2p.Install(nodes.Get(130), nodes.Get(129)); //puncakjaya -> tiom
  p2p.Install(nodes.Get(129), nodes.Get(131)); //tiom -> ilaga
  p2p.Install(nodes.Get(138), nodes.Get(136)); //yalimo -> tolikara 
  p2p.Install(nodes.Get(132), nodes.Get(133)); //enorotali -> timika 
  p2p.Install(nodes.Get(131), nodes.Get(136)); //ilaga -> tolikara  
  p2p.Install(nodes.Get(131), nodes.Get(140)); //ilaga -> wamena 
  p2p.Install(nodes.Get(140), nodes.Get(141)); //wamena -> nduga  
  p2p.Install(nodes.Get(141), nodes.Get(142)); //nduga -> yahukimo
  // Install NDN stack on all nodes
  ndn::StackHelper ndnHelper;
  ndnHelper.SetDefaultRoutes(true);
  ndnHelper.SetOldContentStore("ns3::ndn::cs::Lru", "MaxSize", "1024");
  ndnHelper.InstallAll();

  // Choosing forwarding strategy
  ndn::StrategyChoiceHelper::InstallAll("/", "/localhost/nfd/strategy/best-route");

  // Installing applications

  // Consumer
  ndn::AppHelper consumerHelper("ns3::ndn::ConsumerCbr");
  //Consumer will request /prefix/0, /prefix/1, ...
  consumerHelper.SetPrefix("/");
  consumerHelper.SetAttribute("Frequency", StringValue("200")); // 100 interests a second
  consumerHelper.Install(nodes.Get(10)); // consumerA1-pekanbaru
  consumerHelper.Install(nodes.Get(20)); // consumerA2-bengkulu
  consumerHelper.Install(nodes.Get(38)); // consumerA3-surabaya
  consumerHelper.Install(nodes.Get(56)); // consumerA4-kutaibarat
  consumerHelper.Install(nodes.Get(80)); // consumerA5-wakatobi
  consumerHelper.Install(nodes.Get(94)); // consumerA6-palamea
  consumerHelper.Install(nodes.Get(142)); // consumerA7-yahukomo
  consumerHelper.Install(nodes.Get(74)); // consumerA8-talaud
  consumerHelper.Install(nodes.Get(105)); // consumerA9-pulaurote
  consumerHelper.Install(nodes.Get(133)); // consumerA10-membramoraya
  consumerHelper.Install(nodes.Get(65)); // consumerA11-gorontalo
  consumerHelper.Install(nodes.Get(44)); // consumerA12-denpasar
  consumerHelper.Install(nodes.Get(60)); // consumerA13-bunyu
  consumerHelper.Install(nodes.Get(0)); // consumerA14-sabang
  consumerHelper.Install(nodes.Get(17)); // consumerA14-natuna

  // Producer
  ndn::AppHelper producerHelper("ns3::ndn::Producer");
  // Producer will reply to all requests starting with /prefix
  producerHelper.SetPrefix("/");
  producerHelper.SetAttribute("PayloadSize", StringValue("1024"));
  producerHelper.Install(nodes.Get(5)); // produserA-medan
  
 ndn::AppDelayTracer::InstallAll("/home/bertopeng17/ndnSIM/ns-3/data-tracer-thesis/Delay-palaparingICWT-100int-bestroute-5s.txt");
 
  Simulator::Stop(Seconds(5.0));




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
