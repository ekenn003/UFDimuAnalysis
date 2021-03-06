//SelectionCuts.h

#ifndef ADD_SELECTIONCUTS
#define ADD_SELECTIONCUTS

#include "Cut.h"

// Define the different cuts
class TightMuonIdCuts : public Cut
{
    public:

        TightMuonIdCuts();
        TightMuonIdCuts(int numTrackerLayers, int numValidMuonHits, int numValidPixelHits, int numOfMatchedStations, 
                        int normChiSquare, float d0_pV, float dz_PV);

        int cNumTrackerLayers;     // >
        int cNumValidMuonHits;     // >
        int cNumValidPixelHits;    // >
        int cNumOfMatchedStations; // >
        int cNormChiSquare;        // <
        float cd0_PV;              // <
        float cdz_PV;              // <
        
        bool evaluate(VarSet& vars);
        void makeCutSet();
        TString string();
};

class SynchEventSelectionCuts : public Cut
{
    public:
        SynchEventSelectionCuts();
        SynchEventSelectionCuts(float cDimuMassMin, float cDimuMassMax, float cTrigMuPtMin, float cTrigMuEtaMax, 
                                float cPVzMax, int cNDFpv, int cNPV, int nJets);

        float cDimuMassMin;        // >
        float cDimuMassMax;        // <
        float cTrigMuPtMin;        // >
        float cTrigMuEtaMax;       // <
        float cPVzMax;             // < 
        int cNDFpv;                // >
        int cNPV;                  // > 
        int cNJets;                // <=

        void makeCutSet();
        bool evaluate(VarSet& vars);
        bool passesVertexSelection(_VertexInfo& vertices);
        TString string();
};

class SynchMuonSelectionCuts : public Cut
{
    public:
        SynchMuonSelectionCuts();
        SynchMuonSelectionCuts(float minPt, float maxEta, float maxRelIso);

        float cMinPt;               // >
        float cMaxEta;              // <
        float cMaxRelIso;           // <

        void makeCutSet();
        bool evaluate(VarSet& vars);
        bool evaluate(_MuonInfo& recoMu, int m);
        TString string();
};

class Run1EventSelectionCuts : public Cut
{
    public:
        Run1EventSelectionCuts();
        Run1EventSelectionCuts(float trigMuPtMin, float dimuMassMin);

        float cTrigMuPtMin;        // >
        float cDimuMassMin;        // >

        void makeCutSet();
        bool evaluate(VarSet& vars);
        TString string();
};

class Run1EventSelectionCuts80X : public Cut
{
// CMSSW 8_0_X is missing HLT Info so we can't use HLT in event selection
// We have to apply other cuts and scale for trigger efficiency

    public:
        Run1EventSelectionCuts80X();
        Run1EventSelectionCuts80X(bool isData);
        Run1EventSelectionCuts80X(float trigMuPtMin, float dimuMassMin);
        Run1EventSelectionCuts80X(bool isData, float trigMuPtMin, float dimuMassMin);

        bool isData = 0;
        float cTrigMuPtMin;        // >
        float cDimuMassMin;        // >

        void makeCutSet();
        bool evaluate(VarSet& vars);
        TString string();
};

class Run1EventSelectionSigCuts : public Cut
{
    public:
        Run1EventSelectionSigCuts();
        Run1EventSelectionSigCuts(float trigMuPtMin, float dimuMassMin, float dimuMassMax);

        float cTrigMuPtMin;        // >
        float cDimuMassMin;        // >
        float cDimuMassMax;        // <

        void makeCutSet();
        bool evaluate(VarSet& vars);
        TString string();
};

class Run1MuonSelectionCuts : public Cut
{
    public:
        Run1MuonSelectionCuts();
        Run1MuonSelectionCuts(float minPt, float maxEta, float maxRelIso);

        float cMinPt;               // >
        float cMaxEta;              // <
        float cMaxRelIso;           // <

        void makeCutSet();
        bool evaluate(VarSet& vars);
        bool evaluate(_MuonInfo& recoMu, int m);
        TString string();
};

class FEWZCompareCuts : public Cut
{
    public:
        FEWZCompareCuts();
        FEWZCompareCuts(float leadPtMin, float subleadPtMin, float maxEta, float dimuMassMin, float dimuMassMax, float maxRelIso);

        float cLeadPtMin;           
        float cSubleadPtMin;        
        float cMaxEta;              
        float cDimuMassMin;         
        float cDimuMassMax;         
        float cMaxRelIso;         

        void makeCutSet();
        bool evaluate(VarSet& vars);
        bool evaluate(_MuonInfo& recoMu, int m);
        TString string();
};
#endif
