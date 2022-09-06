#include <acb_calc.h>
#include <arf.h>
#include <acb_elliptic.h>
#include <flint/flint.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct INPUT{
  int IsF,prec,ymax,NT;
  double f,er,ei;
};

struct OUTPUT{
  double **Gr,**Gi,*GFr,*GFi;
  int **nxlist,**nylist;
  double *Gr_d,*Gi_d;
};

void G0(struct INPUT GP,struct OUTPUT GV);

/*void LoadG0(struct PARAMETERS GP,struct DYNAMIC_VARIABLES GV);
void G0_00_f_mp_test(struct PARAMETERS GP,struct DYNAMIC_VARIABLES GV);
void G0_11_f_mp_test(struct PARAMETERS GP,struct DYNAMIC_VARIABLES GV);
void G0_00_c_mp_test(struct PARAMETERS GP,struct DYNAMIC_VARIABLES GV);
void G0_11_c_mp_test(struct PARAMETERS GP,struct DYNAMIC_VARIABLES GV);
void g0f_mp_test(struct PARAMETERS GP,struct DYNAMIC_VARIABLES GV);
*/
