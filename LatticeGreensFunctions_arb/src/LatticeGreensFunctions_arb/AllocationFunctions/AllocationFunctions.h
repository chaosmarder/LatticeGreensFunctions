double *allocate_vector(int SIZE);
int *allocate_int_vector(int SIZE);
char *allocate_string(int SIZE);
double *reallocate_vector(double *p,int SIZE);
int *reallocate_int_vector(int *p,int SIZE);
char *reallocate_string(char *p,int SIZE);
double **allocate_array(int SIZE1,int SIZE2);
int **allocate_array_int(int SIZE1,int SIZE2);

void write_vector(double *z,int i, double value);
void write_array(double **z,int i, int j, double value);
double read_vector(double *z,int i);
double read_array(double **z,int i, int j);
double *get_array_pointer(double **z,int i);
int *get_array_pointer_int(int **z,int i);
