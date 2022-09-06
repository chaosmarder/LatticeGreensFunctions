%inline %{
#include "arrayobject.h"
typedef   double* ndarray;

void initialize(){
     import_array();
}


 PyObject *Pointer_To_NumPy(double *p, int size)
   {

     /*
       This routine take a pointer to a double and returns a NumPy 1-d array that
       has access to the exact same data
     */
     npy_intp dim[1];
     PyArrayObject *numpy;
     dim[0]=size;
     numpy = (PyArrayObject *) PyArray_SimpleNewFromData(1, dim, NPY_DOUBLE,(void *)p);
     return (PyObject*) numpy;
   }

 PyObject *Pointer_To_NumPy_Int(int *p, int size)
   {
     /*
       This routine take a pointer to an int and returns a NumPy 1-d array that
       has access to the exact same data
     */
     npy_intp dim[1];
     PyArrayObject *numpy;
     dim[0]=size;
     numpy = (PyArrayObject *) PyArray_SimpleNewFromData(1, dim, NPY_INT,(void *)p);
     return (PyObject*) numpy;
   }
 
 PyObject *Pointer_To_NumPy_Array(double **p, int size1,int size2)
   {
     /*
       This routine take a pointer to a pointer to double and returns a NumPy 2-d array
       that has access to the exact same data
     */
     npy_intp dim[2];
     PyArrayObject *numpy;
     dim[0]=size1;
     dim[1]=size2;
     numpy = (PyArrayObject *) PyArray_SimpleNewFromData(2, dim, NPY_DOUBLE,(void *)p);
     return (PyObject*) numpy;
   }
 PyObject *Pointer_To_NumPy_Array_Int(int **p, int size1,int size2)
   {
     /*
       This routine take a pointer to a pointer to int and returns a NumPy 2-d array
       that has access to the exact same data
     */
     npy_intp dim[2];
     PyArrayObject *numpy;
     dim[0]=size1;
     dim[1]=size2;
     numpy = (PyArrayObject *) PyArray_SimpleNewFromData(2, dim, NPY_INT,(void *)p);
     return (PyObject*) numpy;
   }

char *File(PyObject *strng){
   char *f="";
   if  (!(PyString_Check(strng))){
     printf("Please use valid character string for this variable.\n");
     return f;
   }
   else{
     return PyString_AsString(strng);
   }
 }
%}

%typemap(in) char[50] {
  $1=File($input);
}

/*%typemap(out) char[50] {
	//printf("Writing chacter\n");
	strncpy($1,$result,50);
}
*/

%typemap(in) ndarray(int size) {
  /*This typemap takes a Python numpy ndarray,and returns in arg1 a pointer to the data in the
    array, and in size1 the size of the array.
  */
  size=PyArray_Size((PyObject*)$input);
  $1=(ndarray) PyArray_GETPTR1((PyArrayObject*)$input,0);
}

%typemap(out) ndarray{
  /*The functioning of this typemap depends upon the assumption that the function in 
    question had at least one input object that was a NumArray, and that the first
    one had a dimension the same size as the desired output. If this is not the case,
    use different typemaps! The variable size1 is what SWIG will do with the variable size 
    coming from the input typemap.
  */
  $result=(PyObject *)Pointer_To_NumArray((NumArray) $1,size1);
}

