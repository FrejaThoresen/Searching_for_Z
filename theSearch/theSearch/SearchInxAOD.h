#ifndef theSearch_SearchInxAOD_H
#define theSearch_SearchInxAOD_H
#include "JetSelectorTools/JetCleaningTool.h"

#include <EventLoop/Algorithm.h>
#include <TTree.h>
#include "TLorentzVector.h"
#include "TBranch.h"
using namespace std;

class SearchInxAOD : public EL::Algorithm
{
    // put your configuration variables here as public variables.
    // that way they can be set directly from CINT and python.
public:
    // float cutValue;
    string outputName;
    TTree* tree_Z_mu; //!
    TTree* tree_Z_e; //!
    TTree* tree_Z_j; //!


    int EventNumber; //!


    TBranch *branch_e_m;//!
    TBranch *branch_mu_m ;//!
    TBranch *branch_j_m ;//!
    TBranch *branch_e_pt;//!
    TBranch *branch_mu_pt;//!
    TBranch *branch_j_pt ;//!

    //m_jetCleaning = new JetCleaningTool("JetCleaning");


    vector<TLorentzVector> Z_from_muons; //!
    vector<TLorentzVector> Z_from_electrons; //!
    vector<TLorentzVector> Z_from_jets; //!

    double Z_m_e;//!
    double Z_m_mu;//!
    double Z_m_j;//!
    double Z_pt_e;//!
    double Z_pt_mu;//!
    double Z_pt_j;//!

    // variables that don't get filled at submission time should be
    // protected from being send from the submission node to the worker
    // node (done by the //!)
public:
    // Tree *myTree; //!
    // TH1 *myHist; //!
    int m_eventCounter; //!

    JetCleaningTool *m_jetCleaning; //!

    // this is a standard constructor
    SearchInxAOD ();

    // these are the functions inherited from Algorithm
    virtual EL::StatusCode setupJob (EL::Job& job);
    virtual EL::StatusCode fileExecute ();
    virtual EL::StatusCode histInitialize ();
    virtual EL::StatusCode changeInput (bool firstFile);
    virtual EL::StatusCode initialize ();
    virtual EL::StatusCode execute ();
    virtual EL::StatusCode postExecute ();
    virtual EL::StatusCode finalize ();
    virtual EL::StatusCode histFinalize ();

    // this is needed to distribute the algorithm to the workers
    ClassDef(SearchInxAOD, 1);
};

#endif
