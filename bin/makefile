# MakeFile

# Set the Compiler
CC = g++

# Include the root libraries
LIBFLAGS = `root-config --libs` -O3 -lXMLIO -lMLP -lMinuit

# the directory for the base library that enables the analysis
LIBDIR = ../lib/

# the directory for the cut selection objects specific to the analysis
SDIR = ../selection/

# include the libdir and sdir and the root libraries
CFLAGS = -I${LIBDIR} -I${SDIR} -c -g `root-config --cflags`

# The name of the .cxx file you want to compile into an executable
#MAIN = zcorr80X_v2
#MAIN = nm1_v2
#MAIN = make80XMCHist_v2
#MAIN = synch_v2
#MAIN = compareDataMC80X
#MAIN = compareDataMC80XCat
#MAIN = fewzCompare_v2
MAIN = overlayFewz
#MAIN = categorize_v2

# link all of the objects to the main program
${MAIN}: ${LIBDIR}Sample.o ${SDIR}SelectionCuts.o ${SDIR}CategorySelection_v2.o ${SDIR}JetSelectionTools.o ${LIBDIR}DiMuPlottingSystem.o ${MAIN}.o ${LIBDIR}Cut.h ${LIBDIR}CutSet.h ${SDIR}SelectionCuts.h ${SDIR}JetSelectionTools.h
	$(CC) $(LIBFLAGS) ${LIBDIR}Sample.o ${SDIR}SelectionCuts.o ${SDIR}CategorySelection_v2.o ${SDIR}JetSelectionTools.o ${LIBDIR}DiMuPlottingSystem.o ${MAIN}.o -o ${MAIN}

${MAIN}.o: ${MAIN}.cxx EventTools_v2.cxx SignificanceMetrics.cxx PUTools.cxx ${LIBDIR}DataFormats.h 
	$(CC) $(CFLAGS) ${MAIN}.cxx -o ${MAIN}.o

# compile the dependencies
${SDIR}SelectionCuts.o: ${SDIR}SelectionCuts.cxx ${SDIR}SelectionCuts.h ${LIBDIR}Cut.h ${LIBDIR}CutSet.h ${SDIR}JetSelectionTools.h ${LIBDIR}VarSet.h ${LIBDIR}DataFormats.h
	$(CC) $(CFLAGS) ${SDIR}SelectionCuts.cxx -o ${SDIR}SelectionCuts.o

${SDIR}CategorySelection_v2.o: ${SDIR}CategorySelection_v2.cxx ${SDIR}CategorySelection_v2.h ${SDIR}JetSelectionTools.h ${LIBDIR}VarSet.h ${LIBDIR}DataFormats.h
	$(CC) $(CFLAGS) ${SDIR}CategorySelection_v2.cxx -o ${SDIR}CategorySelection_v2.o

${SDIR}JetSelectionTools.o: ${SDIR}JetSelectionTools.cxx ${SDIR}JetSelectionTools.h ${LIBDIR}VarSet.h ${LIBDIR}DataFormats.h
	$(CC) $(CFLAGS) ${SDIR}JetSelectionTools.cxx -o ${SDIR}JetSelectionTools.o

${LIBDIR}Sample.o: ${LIBDIR}Sample.cxx ${LIBDIR}Sample.h ${LIBDIR}VarSet.h ${LIBDIR}DataFormats.h
	$(CC) $(CFLAGS) ${LIBDIR}Sample.cxx -o ${LIBDIR}Sample.o

${LIBDIR}DiMuPlottingSystem.o: ${LIBDIR}DiMuPlottingSystem.cxx ${LIBDIR}DiMuPlottingSystem.h ${LIBDIR}Sample.h 
	$(CC) $(CFLAGS) ${LIBDIR}DiMuPlottingSystem.cxx -o ${LIBDIR}DiMuPlottingSystem.o

clean:
	rm *.o

cleanall:
	rm *.o
	rm ${LIBDIR}*.o
	rm ${SDIR}*.o
