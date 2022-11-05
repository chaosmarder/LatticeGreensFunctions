CFLAGS =   -fopenmp -O6

PYTHON_LIB = /usr/local/Cellar/python\@3.9/3.9.7/Frameworks/Python.framework/Versions/3.9/lib
PYTHON_INC = /usr/local/Cellar/python\@3.9/3.9.7/Frameworks/Python.framework/Versions/Current/include/python3.9/
NUMPY_INC = /usr/local/Cellar/python\@3.9/3.9.7/Frameworks/Python.framework/Versions/3.9/lib/python3.9/site-packages/numpy/core/include/numpy

LIBS =  -lm  -L $(PYTHON_LIB)  -lpython3.9
INC = -I $(PYTHON_INC) -I $(NUMPY_INC) 

GCC=/usr/local/Cellar/gcc/11.2.0/bin/gcc-11


AllocationFunctions:
	make _AllocationFunctions.so

AllocationFunctions_wrap.c: AllocationFunctions.i NumPy_Wrappers.i 
	swig -python -shadow AllocationFunctions.i

AllocationFunctions_wrap.o: AllocationFunctions_wrap.c
	$(GCC) -fpic -c $(INC) AllocationFunctions_wrap.c -o AllocationFunctions_wrap.o $(CFLAGS)

AllocationFunctions.o:  AllocationFunctions.c
	$(GCC) -fpic AllocationFunctions.c -c -o AllocationFunctions.o $(CFLAGS)

_AllocationFunctions.so: AllocationFunctions_wrap.o AllocationFunctions.o
	$(GCC) -shared AllocationFunctions_wrap.o AllocationFunctions.o -o _AllocationFunctions.so $(CFLAGS) $(LIBS)

clean: 	
	 rm  -rf  *.o *.so 
