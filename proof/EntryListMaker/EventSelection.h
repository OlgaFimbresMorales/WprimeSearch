#ifndef EVENTSELECTION
#define EVENTSELECTION
#include "TTreeReaderValue.h"
#include "TTreeReader.h"
#include "TSelector.h"
#include "TH2F.h"
#include "TH2D.h"
#include "../IsData.h"

class EventSelection : public TSelector{

 protected:
  TTreeReader fReader;
  std::string fullPath;

  std::vector<const char*> BranchNamesList;
  const char *MakeBranchList(const char *bname);
  Bool_t DefineHLT(std::unique_ptr<TTreeReaderValue<Bool_t>>& hltp);

#if defined(Y2016)
  std::unique_ptr<TTreeReaderValue<Bool_t>> HLT_Ele27_WPTight_Gsf;
  std::unique_ptr<TTreeReaderValue<Bool_t>> HLT_Photon175;
  std::unique_ptr<TTreeReaderValue<Bool_t>> HLT_Mu50;
  std::unique_ptr<TTreeReaderValue<Bool_t>> HLT_TkMu50;
  TTreeReaderValue<Bool_t> Flag_globalSuperTightHalo2016Filter = {fReader, MakeBranchList("Flag_globalSuperTightHalo2016Filter")};//o
  TTreeReaderValue<Bool_t> Flag_hcalLaserEventFilter = {fReader, MakeBranchList("Flag_hcalLaserEventFilter")};//o solo se aplica en 2016
  TTreeReaderValue<Bool_t> Flag_EcalDeadCellTriggerPrimitiveFilter = {fReader, MakeBranchList("Flag_EcalDeadCellTriggerPrimitiveFilter")};//o
  TTreeReaderValue<Bool_t> Flag_BadPFMuonFilter = {fReader, MakeBranchList("Flag_BadPFMuonFilter")};//o
  TTreeReaderValue<Bool_t> Flag_BadPFMuonSummer16Filter = {fReader, MakeBranchList("Flag_BadPFMuonSummer16Filter")};//o solo se aplica en 2016
  TTreeReaderValue<Bool_t> Flag_HBHENoiseFilter = {fReader, MakeBranchList("Flag_HBHENoiseFilter")};//o en data tiene una etiqueta extra "_pRECO"
  TTreeReaderValue<Bool_t> Flag_HBHENoiseIsoFilter = {fReader, MakeBranchList("Flag_HBHENoiseIsoFilter")};//o en data tiene una etiqueta extra "_pRECO"
  TTreeReaderValue<Bool_t> Flag_goodVertices = {fReader, MakeBranchList("Flag_goodVertices")};//o en data tiene una etiqueta extra "_pRECO"
  TTreeReaderValue<Bool_t> Flag_eeBadScFilter = {fReader, MakeBranchList("Flag_eeBadScFilter")};//o en data tiene una etiqueta extra "_pRECO"
  //TTreeReaderValue<Bool_t> Flag_hfNoisyHitsFilter = {fReader, MakeBranchList("Flag_hfNoisyHitsFilter")};//x en mc
  //TTreeReaderValue<Bool_t> Flag_BadPFMuonDzFilter = {fReader, MakeBranchList("Flag_BadPFMuonDzFilter")};//x en mc
#elif defined(Y2017)
  // 2017 HLTs && Flags
  std::unique_ptr<TTreeReaderValue<Bool_t>> HLT_Mu50;
  std::unique_ptr<TTreeReaderValue<Bool_t>> HLT_OldMu100;
  std::unique_ptr<TTreeReaderValue<Bool_t>> HLT_TkMu100;
  std::unique_ptr<TTreeReaderValue<Bool_t>> HLT_Ele35_WPTight_Gsf;
  std::unique_ptr<TTreeReaderValue<Bool_t>> HLT_Photon200;
  TTreeReaderValue<Bool_t> Flag_goodVertices = {fReader, MakeBranchList("Flag_goodVertices")};//o
  TTreeReaderValue<Bool_t> Flag_globalSuperTightHalo2016Filter = {fReader, MakeBranchList("Flag_globalSuperTightHalo2016Filter")};//o
  TTreeReaderValue<Bool_t> Flag_HBHENoiseFilter = {fReader, MakeBranchList("Flag_HBHENoiseFilter")};//o
  TTreeReaderValue<Bool_t> Flag_HBHENoiseIsoFilter = {fReader, MakeBranchList("Flag_HBHENoiseIsoFilter")};
  TTreeReaderValue<Bool_t> Flag_EcalDeadCellTriggerPrimitiveFilter = {fReader, MakeBranchList("Flag_EcalDeadCellTriggerPrimitiveFilter")};
  TTreeReaderValue<Bool_t> Flag_BadPFMuonFilter = {fReader, MakeBranchList("Flag_BadPFMuonFilter")};
  TTreeReaderValue<Bool_t> Flag_BadChargedCandidateFilter = {fReader, MakeBranchList("Flag_BadChargedCandidateFilter")};
  TTreeReaderValue<Bool_t> Flag_eeBadScFilter = {fReader, MakeBranchList("Flag_eeBadScFilter")};
 // TTreeReaderValue<Bool_t> Flag_hfNoisyHitsFilter = {fReader, MakeBranchList("Flag_hfNoisyHitsFilter")};
  //TTreeReaderValue<Bool_t> Flag_BadPFMuonDzFilter = {fReader, MakeBranchList("Flag_BadPFMuonDzFilter")};
#if defined(ULSAMPLE)
  TTreeReaderValue<Bool_t> Flag_ecalBadCalibFilter = {fReader, MakeBranchList("Flag_ecalBadCalibFilter")}; //2017 y 2018 //o en data tiene una etiqueta extra "_pRECO"
#else
  TTreeReaderValue<Bool_t> Flag_ecalBadCalibFilter = {fReader, MakeBranchList("Flag_ecalBadCalibFilterV2")}; //2017 y 2018 //o mc
#endif
#elif defined(Y2018)
  // 2018 HLTs && Flags
  std::unique_ptr<TTreeReaderValue<Bool_t>> HLT_Ele32_WPTight_Gsf;
  std::unique_ptr<TTreeReaderValue<Bool_t>> HLT_Photon200;
  std::unique_ptr<TTreeReaderValue<Bool_t>> HLT_Mu50;
  std::unique_ptr<TTreeReaderValue<Bool_t>> HLT_OldMu100;
  std::unique_ptr<TTreeReaderValue<Bool_t>> HLT_TkMu100;
  TTreeReaderValue<Bool_t> Flag_goodVertices = {fReader, MakeBranchList("Flag_goodVertices")};
  TTreeReaderValue<Bool_t> Flag_globalSuperTightHalo2016Filter = {fReader, MakeBranchList("Flag_globalSuperTightHalo2016Filter")};
  TTreeReaderValue<Bool_t> Flag_HBHENoiseFilter = {fReader, MakeBranchList("Flag_HBHENoiseFilter")};
  TTreeReaderValue<Bool_t> Flag_HBHENoiseIsoFilter = {fReader, MakeBranchList("Flag_HBHENoiseIsoFilter")};
  TTreeReaderValue<Bool_t> Flag_EcalDeadCellTriggerPrimitiveFilter = {fReader, MakeBranchList("Flag_EcalDeadCellTriggerPrimitiveFilter")};
  TTreeReaderValue<Bool_t> Flag_BadPFMuonFilter = {fReader, MakeBranchList("Flag_BadPFMuonFilter")};
  TTreeReaderValue<Bool_t> Flag_BadChargedCandidateFilter = {fReader, MakeBranchList("Flag_BadChargedCandidateFilter")};
  TTreeReaderValue<Bool_t> Flag_eeBadScFilter = {fReader, MakeBranchList("Flag_eeBadScFilter")};
  //TTreeReaderValue<Bool_t> Flag_hfNoisyHitsFilter = {fReader, MakeBranchList("Flag_hfNoisyHitsFilter")};
  //TTreeReaderValue<Bool_t> Flag_BadPFMuonDzFilter = {fReader, MakeBranchList("Flag_BadPFMuonDzFilter")};
#if defined(ULSAMPLE)
  TTreeReaderValue<Bool_t> Flag_ecalBadCalibFilter = {fReader, MakeBranchList("Flag_ecalBadCalibFilter")};
#else
  TTreeReaderValue<Bool_t> Flag_ecalBadCalibFilter = {fReader, MakeBranchList("Flag_ecalBadCalibFilterV2")};
#endif
#endif

  TTreeReaderValue<Int_t> PV_npvsGood = {fReader, MakeBranchList("PV_npvsGood")}; // total number of reconstructed primary vertices
  TTreeReaderValue<UInt_t> nMuon = {fReader, MakeBranchList("nMuon")};
  TTreeReaderValue<UInt_t> nElectron = {fReader, MakeBranchList("nElectron")};
  Int_t Year;
  Bool_t IsMissingBranch{};
  Bool_t MinLeptons{};
  Bool_t ElectronHLTs{};
  Bool_t MuonHLTs{};
  Bool_t Flags{};

#if !defined(CMSDATA)
  // Just because we won't override Notify()
  TList *SFDb;
  TH2F* SFElectronLooseID;
  TH2F* SFElectronMediumID;
  TH2F* SFElectronTightID;
  TH2F* SFMuonHighPtID;
  TH2F* SFMuonTrkHighPtID;
  TH2F* SFMuonTrigger;
  TH1F* SFPileup;
  TH1F* SFPileupUp;
  TH1F* SFPileupDown;
#if defined(Y2016) && !defined(ULSAMPLE)
  TH2D* SFMuonHighPtIDBF;
  TH2D* SFMuonHighPtIDGH;
  TH2F* SFMuonTriggerBF;
  TH2F* SFMuonTriggerGH;
#endif
#if defined(Y2016) && defined(ULSAMPLE)
  Bool_t IsPreVFP{};
  TH1F* SFPileuppreVFP;
  TH1F* SFPileuppostVFP;
  TH1F* SFPileupUppreVFP;
  TH1F* SFPileupUppostVFP;
  TH1F* SFPileupDownpreVFP;
  TH1F* SFPileupDownpostVFP;
  TH2F* SFMuonTriggerpreVFP;
  TH2F* SFMuonTriggerpostVFP;
  TH2F* SFMuonHighPtIDpreVFP;
  TH2F* SFMuonHighPtIDpostVFP;
  TH2F* SFMuonTrkHighPtIDpreVFP;
  TH2F* SFMuonTrkHighPtIDpostVFP;
  TH2F* SFElectronLooseIDpreVFP;
  TH2F* SFElectronLooseIDpostVFP;
  TH2F* SFElectronMediumIDpreVFP;
  TH2F* SFElectronMediumIDpostVFP;
  TH2F* SFElectronTightIDpreVFP;
  TH2F* SFElectronTightIDpostVFP;
  TH2F* SFElectronHLTLoosepreVFP;
  TH2F* SFElectronHLTLoosepostVFP;
  TH2F* SFElectronHLTMediumpreVFP;
  TH2F* SFElectronHLTMediumpostVFP;
  TH2F* SFElectronHLTTightpreVFP;
  TH2F* SFElectronHLTTightpostVFP;
#endif
#endif

  const std::unordered_map<std::string, std::unique_ptr<TTreeReaderValue<Bool_t>>*> HLTsMap {
#if defined(Y2016)
    { "HLT_Ele27_WPTight_Gsf", &HLT_Ele27_WPTight_Gsf },
    { "HLT_Photon175", &HLT_Photon175 },
    { "HLT_Mu50", &HLT_Mu50},
    { "HLT_TkMu50", &HLT_TkMu50}
#elif defined(Y2017)
    { "HLT_Ele35_WPTight_Gsf", &HLT_Ele35_WPTight_Gsf },
    { "HLT_Photon200", &HLT_Photon200 },
    { "HLT_Mu50", &HLT_Mu50},
    { "HLT_OldMu100", &HLT_OldMu100},
    { "HLT_TkMu100", &HLT_TkMu100}
#elif defined(Y2018)
    { "HLT_Ele32_WPTight_Gsf", &HLT_Ele32_WPTight_Gsf },
    { "HLT_Photon200", &HLT_Photon200 },
    { "HLT_Mu50", &HLT_Mu50},
    { "HLT_OldMu100", &HLT_OldMu100},
    { "HLT_TkMu100", &HLT_TkMu100}
#endif
  };

 public:

  EventSelection() {};
  ~EventSelection() {};
  Bool_t ElectronTest() const { return ElectronHLTs; };
  void Init(TTree *tree);
  Bool_t MuonTest() const { return MuonHLTs; };
  Bool_t FlagsTest() const { return Flags; };
  Bool_t MinLeptonsTest() const { return MinLeptons; };
  Bool_t ReadEntry(const Long64_t& entry);
  Bool_t Notify();
};

void EventSelection::Init(TTree *tree)
{

#if defined(Y2016)
  Year = 2016;
#elif defined(Y2017)
  Year = 2017;
#elif defined(Y2018)
  Year = 2018;
#endif

  fReader.SetTree(tree);

}

Bool_t EventSelection::Notify() {

  fullPath = std::string((fReader.GetTree())->GetCurrentFile()->GetEndpointUrl()->GetUrl());
  std::clog << Form("Processing: %s\t%lld\n",fullPath.c_str(),fReader.GetCurrentEntry());

  Long64_t nentry = fReader.GetCurrentEntry();
  TTree* t_ = fReader.GetTree();

  fReader.Restart();

  for(auto brn: HLTsMap){
    brn.second->reset();
    TTree* tree = fReader.GetTree();
    const TBranch *b = tree->FindBranch(brn.first.c_str());
    if(b != nullptr){
      brn.second->reset(new TTreeReaderValue<Bool_t>{fReader, brn.first.c_str()});
    } else {
      std::cerr << "EventSelection::Init Error: Tree " << tree->GetName()
                << " Branch: " << brn.first.c_str() << " not found " << Year << std::endl;
      std::cerr << "\tURL: " << tree->GetCurrentFile()->GetEndpointUrl()->GetUrl() <<std::endl;
    }
  }

  fReader.SetTree(t_);
  fReader.SetEntry(nentry);

#if defined(Y2016) and !defined(CMSDATA) and defined(ULSAMPLE)
  if (fullPath.find("preVFP") != std::string::npos) {
    SFPileup = SFPileuppreVFP;
    SFPileupUp = SFPileupUppreVFP;
    SFPileupDown = SFPileupDownpreVFP;
    SFElectronLooseID = SFElectronLooseIDpreVFP;
    SFElectronTightID = SFElectronTightIDpreVFP;
    SFMuonHighPtID = SFMuonHighPtIDpreVFP;
    SFMuonTrkHighPtID = SFMuonTrkHighPtIDpreVFP;
    SFMuonTrigger = SFMuonTriggerpreVFP;
    IsPreVFP = true;
    std::clog << "Notify: Setting preVFP Muon and Electron SFs\t";
  } else {
    SFPileup = SFPileuppostVFP;
    SFPileupUp = SFPileupUppostVFP;
    SFPileupDown = SFPileupDownpostVFP;
    SFElectronLooseID = SFElectronLooseIDpostVFP;
    SFElectronTightID = SFElectronTightIDpostVFP;
    SFMuonHighPtID = SFMuonHighPtIDpostVFP;
    SFMuonTrkHighPtID = SFMuonTrkHighPtIDpostVFP;
    SFMuonTrigger = SFMuonTriggerpostVFP;
    IsPreVFP = false;
    std::clog << "Notify: Setting postVFP Muon and Electron SFs\t";
  }
  std::clog << "[Ok]\n";
#endif
  return kTRUE;
}

const char* EventSelection::MakeBranchList(const char *bname){
  BranchNamesList.emplace_back(bname);
  return bname;
};

Bool_t EventSelection::DefineHLT(std::unique_ptr<TTreeReaderValue<Bool_t>>& hltp){
  return hltp != nullptr? **hltp: false;
};

Bool_t EventSelection::ReadEntry(const Long64_t& entry){

  fReader.SetEntry(entry);

  MinLeptons = (*nElectron + *nMuon) > 2;

#if defined(Y2016)
  ElectronHLTs = DefineHLT(HLT_Ele27_WPTight_Gsf) or DefineHLT(HLT_Photon175);
  MuonHLTs = DefineHLT(HLT_Mu50) or DefineHLT(HLT_TkMu50);
  Flags = *Flag_goodVertices and *Flag_globalSuperTightHalo2016Filter
    and *Flag_HBHENoiseFilter and *Flag_HBHENoiseIsoFilter
    and *Flag_EcalDeadCellTriggerPrimitiveFilter
    and *Flag_BadPFMuonFilter and *Flag_eeBadScFilter
   // and *Flag_hfNoisyHitsFilter and *Flag_BadPFMuonDzFilter
    and *PV_npvsGood > 0;
#elif defined(Y2017)
  ElectronHLTs = DefineHLT(HLT_Ele35_WPTight_Gsf) or
    DefineHLT(HLT_Photon200);
  MuonHLTs = DefineHLT(HLT_Mu50) or DefineHLT(HLT_OldMu100) or
    DefineHLT(HLT_TkMu100);
  Flags = *Flag_goodVertices and *Flag_globalSuperTightHalo2016Filter
    and *Flag_HBHENoiseFilter and *Flag_HBHENoiseIsoFilter
    and *Flag_EcalDeadCellTriggerPrimitiveFilter
    and *Flag_BadPFMuonFilter and *Flag_ecalBadCalibFilter
    and *Flag_eeBadScFilter //and *Flag_hfNoisyHitsFilter
    and *Flag_BadPFMuonDzFilter
    and *PV_npvsGood > 0;
#elif defined(Y2018)
  ElectronHLTs = DefineHLT(HLT_Ele32_WPTight_Gsf) or DefineHLT(HLT_Photon200);
  MuonHLTs = DefineHLT(HLT_Mu50) or DefineHLT(HLT_OldMu100) or DefineHLT(HLT_TkMu100);
  Flags = *Flag_goodVertices and *Flag_globalSuperTightHalo2016Filter
    and *Flag_HBHENoiseFilter and *Flag_HBHENoiseIsoFilter
    and *Flag_EcalDeadCellTriggerPrimitiveFilter and *Flag_BadPFMuonFilter
    and *Flag_ecalBadCalibFilter //and *Flag_BadPFMuonDzFilter
    and *Flag_eeBadScFilter //and *Flag_hfNoisyHitsFilter
    and *PV_npvsGood > 0;
#endif

  return kTRUE;

}
#endif
