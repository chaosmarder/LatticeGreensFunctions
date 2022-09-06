from AllocationFunctions.AllocationFunctions import *
from scipy import zeros
def NumPy_Array_From_Pointers(array,size1,size2,type):
#    print 'In NumPyArrayfromPointers, type=',type
    if (type=='i') or (type =='int') :
        out=zeros(size1,'object')
        for i in range(size1):
            out[i]=Pointer_To_NumPy_Int(get_array_pointer_int(array,i),size2)
    else:
        if (type=='f') or (type=='d') or (type=='float') or (type=='double'):
            out=zeros(size1,'object')
            for i in range(size1):
                out[i]=Pointer_To_NumPy(get_array_pointer(array,i),size2)
                out[i][:]=zeros(size2)[:]
        else:
            print ('Invalid type',type,'in NumPy_Array_From_Pointers')
            return 1
    return out
    
