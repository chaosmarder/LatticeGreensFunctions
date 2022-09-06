from Data import Data
from AllocationFunctions.AllocationFunctions import *
from LatticeGreensFunctions_arb import INPUT,OUTPUT
def InitializeDataStructures(ymax):
    initialize()
    I=INPUT()
    O=OUTPUT()
    Grtmp=Data(int(ymax+1),dimension=2,InitialAllocatedSize2=int(ymax+1),type='float')
    O.Gr=Grtmp.CPointer
    O.GrP=Grtmp.PythonPointer
    Gitmp=Data(int(ymax+1),dimension=2,InitialAllocatedSize2=int(ymax+1),type='float')
    O.Gi=Gitmp.CPointer
    O.GiP=Gitmp.PythonPointer
    return(I,O)
