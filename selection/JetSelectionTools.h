//JetSelectionTools.h

#ifndef ADD_JETSELECTIONTOOLS
#define ADD_JETSELECTIONTOOLS

#include "VarSet.h"
#include <vector>

class JetSelectionTools
{
    public:
        JetSelectionTools();
        JetSelectionTools(float cJetSelectionPtMin, float cJetSelectionEtaMax, float cJetSelectiondRMax);

        float cJetSelectionPtMin; 
        float cJetSelectionEtaMax;       
        float cJetSelectiondRMax;
 
        float dR(float eta1, float phi1, float eta2, float phi2);
        int getNValidJets(VarSet& vars);
        void getValidJetsdR(VarSet& vars, std::vector<TLorentzVector>& jetvec);
        void getValidJets(VarSet& vars, std::vector<TLorentzVector>& jetvec);
};

#endif
