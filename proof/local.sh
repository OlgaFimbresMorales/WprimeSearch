export SAMPLEFILE="files/listtempmc.txt"
export ENTRYLISTFILE=""
export YEARP=2018
export OutputLabel="test"
export NCORES=1
NFSTART=1
NFEND=1
export SPACING_FACTOR=1.15
export LIMIT_EDGE=1350.0
export FIRSTBIN_LEFTEDGE=60.0
export FIRSTBIN_RIGHTEDGE=70.0

ROOTCommand="\""$OutputLabel"\",\""$SAMPLEFILE"\","$NCORES",\""$ENTRYLISTFILE"\",$NFSTART,$NFEND";

root -l -b -q "Selector.C("$ROOTCommand")";
