from AllocationFunctions.AllocationFunctions import *
from NumPy_Array_From_Pointers import *
from scipy import zeros
initialize()
class Data:
    def __init__(self,InitialAllocatedSize,type='float',dimension=1,InitialAllocatedSize2=0,verbose=False):
        self.type=type
        self.dimension=dimension
        if dimension==1:
            self.AllocatedSize=InitialAllocatedSize
            tmp=zeros(InitialAllocatedSize,self.type)
        elif dimension==2:
            self.Size1=InitialAllocatedSize
            self.Size2=InitialAllocatedSize2
        else:
            raise ValueError ("dimension of array must be 1 or 2 (default 1)")
        self.Allocate(verbose=verbose)
        if self.dimension==1:
            self.PythonPointer[:]=tmp[:]
            del(tmp)
    def Allocate(self,verbose=False):
        """
        This routine should be called only when the data
        are initialized. By the time it is done, a C array
        has been created at the initial desired size,
        and a Python array has been created that
        is attached to the same memory location
        """
        if verbose:
            print('Creating array of dimension ',self.dimension)
        if self.dimension==1:
            if self.type=='float':
                self.CPointer=allocate_vector(self.AllocatedSize)
                args=(self.CPointer,self.AllocatedSize)
                self.PythonPointer=Pointer_To_NumPy(*args)
            elif self.type=='int':
                self.CPointer=allocate_int_vector(self.AllocatedSize)
                args=(self.CPointer,self.AllocatedSize)
                self.PythonPointer=Pointer_To_NumPy_Int(*args)
            else:
                raise ValueError ("Type must be float or int")
        elif self.dimension==2:
            if verbose:
                print('Creating 2-d array')
            if self.type=='float':
                self.CPointer=allocate_array(self.Size1,self.Size2)
            elif self.type=='int':
                self.CPointer=allocate_array_int(self.Size1,self.Size2)
            args=(self.CPointer,self.Size1,self.Size2,self.type)
            if verbose:
                print ('Allocating array from pointer')
            self.PythonPointer=NumPy_Array_From_Pointers(*args)
        else:
            raise ValueError ("Array dimension must be 1 or 2")


    def ReAllocate(self,ExpandFactor=1.25):
        NewSize=int(self.AllocatedSize*ExpandFactor)
        if self.dimension==1:
            if self.type=='float':
                self.CPointer=reallocate_vector(self.CPointer,NewSize)
                args=(self.CPointer,NewSize)
                self.PythonPointer=Pointer_To_NumPy(*args)
            elif self.type=='int':
                self.CPointer=reallocate_vector_int(self.CPointer,NewSize)
                args=(self.CPointer,NewSize)
                self.PythonPointer=Pointer_To_NumPy_Int(*args)
            else:
                raise ValueError ("Type must be float or int")
            self.PythonPointer[self.AllocatedSize:NewSize]=zeros(NewSize-self.AllocatedSize,self.type)
        elif self.dimension==2:
            reallocate_array(self.CPointer,NewSize1,NewSize2)
            args=(self.CPointer,NewSize1,NewSize2,self.type)
            raise ValueError("Cannot resize 2-d arrays yet!")
        else:
            raise ValueError ("Array dimension must be 1 or 2")
        self.AllocatedSize=NewSize

    def InsertData(self,data):
        length=len(data)
        while length<self.AllocatedSize:
            self.Reallocate()
        PythonPointer[0:length]=data[:]
        self.OccupiedSize=len(data)
    def AppendData(self,data):
        newlength=len(data)+self.OccupiedSize
        if newlength>self.AllocatedSize:
            self.Reallocate()
        for i in range(self.OccupiedSize,newlength):
            PythonPointer[i+self.OccupiedSize]=data[i]
        self.OccupiedSize=newlength
            
        

        
