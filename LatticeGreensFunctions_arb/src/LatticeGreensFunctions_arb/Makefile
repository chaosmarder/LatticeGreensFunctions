CFLAGS =   -fopenmp -O6

PYTHON_LIB = /usr/local/Cellar/python\@3.9/3.9.7/Frameworks/Python.framework/Versions/3.9/lib
PYTHON_INC = /usr/local/Cellar/python\@3.9/3.9.7/Frameworks/Python.framework/Versions/Current/include/python3.9/
NUMPY_INC = /usr/local/Cellar/python\@3.9/3.9.7/Frameworks/Python.framework/Versions/3.9/lib/python3.9/site-packages/numpy/core/include/numpy

ARB_LIB = /usr/local/Cellar/arb/2.21.0/lib/ 
ARB_INC = /usr/local/Cellar/arb/2.21.0/include/
FLINT_INC = /usr/local/include


LIBS =  -lm  -L $(ARB_LIB)  -L $(PYTHON_LIB)  -larb -lpython3.9

INC = -I $(PYTHON_INC) -I $(NUMPY_INC) -I $(ARB_INC) -I $(FLINT_INC)

GCC=/usr/local/Cellar/gcc/11.2.0/bin/gcc-11


all: LatticeGreensFunctions.c LatticeGreensFunctions.h
	make _LatticeGreensFunctions.so	

LatticeGreensFunctions_wrap.c: LatticeGreensFunctions.h LatticeGreensFunctions.i LatticeGreensFunctions.c
	swig -python -shadow LatticeGreensFunctions.i

LatticeGreensFunctions.o: LatticeGreensFunctions.c LatticeGreensFunctions.h
	$(GCC) $(CFLAGS) $(INC) -fpic -c  LatticeGreensFunctions.c -o LatticeGreensFunctions.o

LatticeGreensFunctions_wrap.o: LatticeGreensFunctions_wrap.c
	$(GCC) -fpic  -c $(INC) LatticeGreensFunctions_wrap.c -o LatticeGreensFunctions_wrap.o $(CFLAGS)

_LatticeGreensFunctions.so: LatticeGreensFunctions_wrap.o LatticeGreensFunctions.o
	 $(GCC) -shared LatticeGreensFunctions_wrap.o LatticeGreensFunctions.o -o _LatticeGreensFunctions.so $(CFLAGS) $(LIBS)
