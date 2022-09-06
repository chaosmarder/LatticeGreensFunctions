#include <stdio.h>
#include <stdlib.h>
double *allocate_vector(int SIZE){
  double *z;
  z=(double *)malloc(SIZE*sizeof(double));
  return z;
}
int *allocate_int_vector(int SIZE){
  int *z;
  z=(int *)malloc(SIZE*sizeof(int));
  return z;
}

char *allocate_string(int SIZE){
  char *z;
  z=(char *)malloc(SIZE*sizeof(char));
  return z;
}

double *reallocate_vector(double *p,int SIZE){
  double *z;
  z=(double *)realloc(p,SIZE*sizeof(double));
  return z;
}
int *reallocate_int_vector(int *p,int SIZE){
  int *z;
  z=(int *)realloc(p,SIZE*sizeof(int));
  return z;
}

char *reallocate_string(char *p,int SIZE){
  char *z;
  z=(char *)realloc(p,SIZE*sizeof(char));
  return z;
}

double **allocate_array(int SIZE1,int SIZE2){
  double **z;
  int i;
  z=(double **)malloc(SIZE1*sizeof(double *));
  for(i=0;i<SIZE1;i++){
    z[i]=(double *)malloc(SIZE2*sizeof(double));
  }
  return z;
}

int **allocate_array_int(int SIZE1,int SIZE2){
  int **z;
  int i;
  z=(int **)malloc(SIZE1*sizeof(int *));
  for(i=0;i<SIZE1;i++){
    z[i]=(int *)malloc(SIZE2*sizeof(int));
  }
  return z;
}

double *get_array_pointer(double **p,int i){
  return p[i];
}

int *get_array_pointer_int(int **p,int i){
  return p[i];
}

void write_vector(double *z,int i, double value){
  z[i]=value;
}

void write_array(double **z,int i, int j, double value){
  z[i][j]=value;
}

double read_vector(double *z,int i){
  return z[i];
}

double read_array(double **z,int i, int j){
  return z[i][j];
}
