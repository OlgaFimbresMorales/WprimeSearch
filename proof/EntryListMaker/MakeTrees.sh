#!/bin/bash
source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc7_amd64_gcc900
export NCORES=3
scram project CMSSW CMSSW_12_2_1
cd CMSSW_12_2_1/src
eval `scram runtime -sh`
echo $CMSSW_BASE
git clone https://github.com/vargasa/WprimeSearch.git Wprime_$1
WprimeDir=$CMSSW_BASE/src/Wprime_$1/
OutputLabel="EntryListMaker_"$1"_"$2
cd $WprimeDir/proof/EntryListMaker/
export FILES=$WprimeDir/proof/files/data/$1/UL/$2.txt

echo -e "#define Y"$1"\n#define CMSDATA\n#define ULSAMPLE">../IsData.h
root -l -b -q "MakeEventIDTree.C(\""$FILES"\","$NCORES")"

xrdcp -f $WprimeDir/proof/EventIDTree_$1_$2.root root://cmseos.fnal.gov//store/user/avargash/WprimeSearchCondorOutput/EventIDTree_$1_$2.root 2>&
xrdcp -f $WprimeDir/proof/EntryLists_$1_$2.root root://cmseos.fnal.gov//store/user/avargash/WprimeSearchCondorOutput/EntryLists_$1_$2.root 2>&1
XRDEXIT=$?
if [[ $XRDEXIT -ne 0 ]]; then
    rm *.root
    echo "exit code $XRDEXIT, failure in xrdcp"
    exit $XRDEXIT
fi
