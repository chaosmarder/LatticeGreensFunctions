#include "LatticeGreensFunctions.h"

 
void G0_00_f_mp(acb_t G0, double f, acb_t e, int prec){
  /*
    This routine takes a real argument f and  produces e on the real line. e may require multiple precision, so it is necessary to start with f. In addition, for e on the 
    real line expressions are a bit different than elsewhere on the complex plane. Hence a separate routine.  Note with elliptic functions that scipy 
    defines the elliptic function with the square of the argument in comparision with Economou
  */
  acb_t negf,B,z,l,k,k2,kp2,Kl,Kr,two,pre,pi,G0r,G0i,i,one;
  arb_t zr;
  acb_init(two);
  acb_init(pre);
  acb_init(negf);
  acb_init(B);
  acb_init(z);
  acb_init(l);
  acb_init(k);
  acb_init(G0r);
  acb_init(G0i);
  acb_init(k2);
  acb_init(kp2);
  acb_init(Kl);
  acb_init(Kr);
  acb_init(pi);
  acb_init(i);
  acb_init(one);
  arb_init(zr);

  acb_onei(i);
  acb_set_si(two,2);
  acb_const_pi(pi,prec);

  acb_set_d(negf,f);
  acb_neg(negf,negf);
  acb_exp(e,negf,prec); 
  acb_neg(e,e);/*e=-exp(-f)*/

  acb_set_si(one,1);
  acb_set_si(B,4);
  acb_add(z,e,B,prec);
  acb_div(l,B,z,prec);
  acb_inv(k,l,prec);
  acb_mul(k2,k,k,prec);
  acb_sub(kp2,one,k2,prec);
  acb_elliptic_k(Kl,kp2,prec);
  acb_elliptic_k(Kr,k2,prec);
  acb_div(pre,two,B,prec);
  acb_div(pre,pre,pi,prec); /*pre=2/(pi * B)*/
  acb_mul(G0r,pre,Kr,prec);
  acb_get_real(zr,z);
  if (arb_is_positive(zr)){ }
  else{
    acb_neg(G0r,G0r);
  }
  acb_mul(G0i,pre,Kl,prec);
  acb_mul(G0i,G0i,i,prec);
  acb_add(G0,G0r,G0i,prec);

  /* Clear all the memory*/ 
  acb_clear(two);
  acb_clear(pre);
  acb_clear(negf);
  acb_clear(B);
  acb_clear(z);
  acb_clear(l);
  acb_clear(k);
  acb_clear(G0r);
  acb_clear(G0i);
  acb_clear(k2);
  acb_clear(kp2);
  acb_clear(Kl);
  acb_clear(Kr);
  acb_clear(pi);
  acb_clear(i);
  acb_clear(one);
  arb_clear(zr);

}

 
  
void G0_11_f_mp(acb_t G11,double f, acb_t e, int prec){

  acb_t negf,B,z,l,k,k2,kp2,two,pre,pi,G0r,G0i,i,G0,Ki,Kr,one;
  acb_t Kri,Kli,Krr,Klr,Ei,Er;
  acb_t p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12;
  acb_t G11r,G11i;
  arb_t zr;
  FILE *fp;
  acb_init(two);
  acb_init(pre);
  acb_init(negf);
  acb_init(B);
  acb_init(z);
  acb_init(l);
  acb_init(k);
  acb_init(G0r);
  acb_init(G0i);
  acb_init(k2);
  acb_init(kp2);
  acb_init(pi);
  acb_init(i);
  acb_init(G0);
  acb_init(Ei);
  acb_init(Er);
  acb_init(Kri);
  acb_init(Kli);
  acb_init(Krr);
  acb_init(Klr);
  acb_init(Kr);
  acb_init(Ki);
  acb_init(p1);
  acb_init(p2);
  acb_init(p3);
  acb_init(p4);
  acb_init(p5);
  acb_init(p6);
  acb_init(p7);
  acb_init(p8);
  acb_init(p9);
  acb_init(p10);
  acb_init(p11);
  acb_init(p12);
  acb_init(G11r);
  acb_init(G11i);
  acb_init(one);
  arb_init(zr);

  acb_set_si(one,1);
  acb_onei(i);
  acb_set_si(two,2);
  acb_const_pi(pi,prec);

  acb_set_d(negf,f);
  acb_neg(negf,negf);
  acb_exp(e,negf,prec); 
  acb_neg(e,e);/*e=-exp(-f)*/


  acb_set_si(B,4);
  acb_add(z,e,B,prec);
  acb_div(l,B,z,prec);
  acb_inv(k,l,prec);
  acb_mul(k2,k,k,prec);
  acb_sub(kp2,one,k2,prec);

   
   acb_elliptic_e(Kli,kp2,prec);

   
   acb_elliptic_k(Kri,kp2,prec);


   acb_elliptic_e(Klr,k2,prec);

   acb_elliptic_k(Krr,k2,prec);
   
  
  acb_div(pre,two,z,prec);
  acb_div(pre,pre,pi,prec); /*pre=2/(pi * z)*/

  acb_elliptic_k(Ki,kp2,prec);
  acb_mul(Ki,Ki,k,prec);    /* Ki=k*mp.ellipk(kp2)*/

  acb_elliptic_k(Kr,k2,prec);
  acb_mul(Kr,Kr,k,prec);    /* Kr=k*mp.ellipk(k2) */
 


  acb_mul(p1,k2,Kri,prec); /*k2*mp.ellipk(kp2)*/
  acb_sub(p2,p1,Kli,prec); /* -mp.ellipe(kp2)+k2*mp.ellipk(kp2) */
  acb_mul(Ei,l,p2,prec);
  acb_mul(p3,kp2,Krr,prec); /*kp2*mp.ellipk(k2)*/
  acb_sub(p4,Klr,p3,prec); /* ellipe(k2)-kp**2*ellipk(k2)*/
  acb_mul(Er,l,p4,prec);

  acb_mul_si(p5,k2,2,prec); /* 2 k2 */
  acb_sub_si(p6,p5,1,prec); /* 2 k2-1 */
  acb_mul(p7,p6,Ki,prec);  /* (2 k2-1 ) Ki */
  acb_mul(p8,p5,Ei,prec); /*2 k2 Ei */
  acb_sub(p9,p7,p8,prec); /* ((2*k2-1)*Ki-2*k2*Ei) */
  acb_mul(G11i,pre,p9,prec);

  acb_mul(p10,p6,Kr,prec); /* (2*k2-1)*Kr */
  acb_mul(p11,p5,Er,prec); /* 2 k2 Er */
  acb_sub(p12,p10,p11,prec); /*(2*k2-1)*Kr - 2 k2 Er */
  acb_mul(G11r,pre,p12,prec);
  acb_get_real(zr,z);

  
  if (arb_is_positive(zr)){ }
  else{
    acb_neg(G11r,G11r);
  }

  acb_mul(G11i,i,G11i,prec);
  acb_add(G11,G11r,G11i,prec);


  acb_clear(two);
  acb_clear(pre);
  acb_clear(negf);
  acb_clear(B);
  acb_clear(z);
  acb_clear(l);
  acb_clear(k);
  acb_clear(G0r);
  acb_clear(G0i);
  acb_clear(k2);
  acb_clear(kp2);
  acb_clear(pi);
  acb_clear(i);
  acb_clear(G0);
  acb_clear(Ei);
  acb_clear(Er);
  acb_clear(Kri);
  acb_clear(Kli);
  acb_clear(Krr);
  acb_clear(Klr);
  acb_clear(Kr);
  acb_clear(Ki);
  acb_clear(p1);
  acb_clear(p2);
  acb_clear(p3);
  acb_clear(p4);
  acb_clear(p5);
  acb_clear(p6);
  acb_clear(p7);
  acb_clear(p8);
  acb_clear(p9);
  acb_clear(p10);
  acb_clear(p11);
  acb_clear(p12);
  acb_clear(G11r);
  acb_clear(G11i);
  acb_clear(one);
  arb_clear(zr);


/*
    Ei=l*(-mp.ellipe(kp2)+k2*mp.ellipk(kp2)) #Way scipy defines integrals
    Er=l*(mp.ellipe(k2)-kp2*mp.ellipk(k2)) #Way scipy defines integrals
    i=mpf(2)/(mp.pi*z)*((mpf(2)*k2-mpf(1))*Ki-mpf(2)*k2*Ei)
    if z>0:
        r=mpf(2)/(mp.pi*z)*((mpf(2)*k2-mpf(1))*Kr-mpf(2)*k2*Er)
    else:
        r=-mpf(2)/(mp.pi*z)*((mpf(2)*k2-mpf(1))*Kr-mpf(2)*k2*Er)
    return r+1j*i
*/


}


void G0_00_c_mp(acb_t G0,acb_t e, int prec){
  acb_t B,z,l,k,k2,kp2,Kl,Kr,two,pre,pi,G0r,G0i,i,l2,pre2;
  acb_init(two);
  acb_init(pre);
  acb_init(B);
  acb_init(z);
  acb_init(l);
  acb_init(k);
  acb_init(G0r);
  acb_init(G0i);
  acb_init(k2);
  acb_init(kp2);
  acb_init(Kl);
  acb_init(Kr);
  acb_init(pi);
  acb_init(i);
  acb_init(l2);
  acb_init(pre2);

  acb_onei(i);
  acb_set_si(two,2);
  acb_const_pi(pi,prec);
  
  acb_set_si(B,4);
  acb_add(z,e,B,prec);
  acb_div(l,B,z,prec);
  acb_mul(l2,l,l,prec);

  acb_div(pre2,two,z,prec);
  acb_div(pre2,pre2,pi,prec); /* pre2=2/(pi * z)  */

  acb_elliptic_k(Kl,l2,prec);
    
  acb_mul(G0,Kl,pre2,prec);


  acb_clear(two);
  acb_clear(pre);
  acb_clear(B);
  acb_clear(z);
  acb_clear(l);
  acb_clear(k);
  acb_clear(G0r);
  acb_clear(G0i);
  acb_clear(k2);
  acb_clear(kp2);
  acb_clear(Kl);
  acb_clear(Kr);
  acb_clear(pi);
  acb_clear(i);
  acb_clear(l2);
  acb_clear(pre2);
  
}


void G0_11_c_mp(acb_t G11,acb_t e, int prec){
  acb_t B,z,l,k,k2,kp2,Kl,Kr,two,pre,pi,G0r,G0i,i,G0,l2,pre2;
  acb_t p1,p2,p3,p4,p5,p6,one;
  acb_init(two);
  acb_init(pre);
  acb_init(B);
  acb_init(z);
  acb_init(l);
  acb_init(k);
  acb_init(G0r);
  acb_init(G0i);
  acb_init(k2);
  acb_init(kp2);
  acb_init(Kl);
  acb_init(Kr);
  acb_init(pi);
  acb_init(i);
  acb_init(G0);
  acb_init(l2);
  acb_init(pre2);
  acb_init(p1);
  acb_init(p2);
  acb_init(p3);
  acb_init(p4);
  acb_init(p5);
  acb_init(p6);
  acb_init(one);

  acb_onei(i);
  acb_set_si(one,1);
  acb_set_si(two,2);
  acb_const_pi(pi,prec);
  
  acb_set_si(B,4);
  acb_add(z,e,B,prec);
  acb_div(l,B,z,prec);
  acb_mul(l2,l,l,prec);
  acb_inv(k,l,prec);
  acb_mul(k2,k,k,prec);
  acb_sub(kp2,one,k2,prec);
  acb_div(pre2,two,z,prec);
  acb_div(pre2,pre2,pi,prec); /* 2/(pi * z)  */
  acb_mul_si(p1,k2,2,prec); /*2 k2 */
  acb_sub_si(p2,p1,1,prec); /*(2 k2 -1)*/
  acb_elliptic_k(Kl,l2,prec);
  acb_mul_si(p3,k2,2,prec); /*2 k2*/
  acb_elliptic_e(Kr,l2,prec);
  acb_mul(p4,p2,Kl,prec); /* (2*k2-1)*ellipk(l2) */
  acb_mul(p5,p3,Kr,prec); /* 2*k2*ellipe(l2) */
  acb_sub(p6,p4,p5,prec); /* (2*k2-1)*ellipk(l2) -  2*k2*ellipe(l2) */
  acb_mul(G11,pre2,p6,prec);

  acb_clear(two);
  acb_clear(pre);
  acb_clear(B);
  acb_clear(z);
  acb_clear(l);
  acb_clear(k);
  acb_clear(G0r);
  acb_clear(G0i);
  acb_clear(k2);
  acb_clear(kp2);
  acb_clear(Kl);
  acb_clear(Kr);
  acb_clear(pi);
  acb_clear(i);
  acb_clear(G0);
  acb_clear(l2);
  acb_clear(pre2);
  acb_clear(p1);
  acb_clear(p2);
  acb_clear(p3);
  acb_clear(p4);
  acb_clear(p5);
  acb_clear(p6);
  acb_clear(one);
  /*G11=mpf(2)/(mp.pi*z)*((mpf(2)*k2-1)*mp.ellipk(l2)-mpf(2)*k2*mp.ellipe(l2))*/
}


acb_ptr g0f_mp(double f,acb_t e, int IsF, int ymax,int prec){
   acb_ptr g0;
   acb_t p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,yc;
   int y;

   acb_init(p1);
   acb_init(p2);
   acb_init(p3);
   acb_init(p4);
   acb_init(p5);
   acb_init(p6);
   acb_init(p7);
   acb_init(p8);
   acb_init(p9);
   acb_init(p10);
   acb_init(p11);
   acb_init(p12);
   acb_init(p13);
   acb_init(p14);
   acb_init(p15);
   acb_init(yc);


   g0= _acb_vec_init(ymax+1);

   if (IsF==1){
     G0_00_f_mp(&g0[0],f,e,prec);
     G0_11_f_mp(&g0[1],f,e,prec);
   }
   else{
     G0_00_c_mp(&g0[0],e,prec);
     G0_11_c_mp(&g0[1],e,prec);
   }     
   y=1;
   while (y<ymax){
     /*g0[y+1]= 4*y/(2*y+1)*((e+4)**2/8-1)*g0[y]-(2*y-1)/(2*y+1)*g0[y-1];*/
     acb_set_si(yc,y);
     acb_mul_si(p1,yc,4,prec); /*4 y */
     acb_mul_si(p2,yc,2,prec); /*2 *y */
     acb_add_si(p3,p2,1,prec);/*2 y +1 */
     acb_div(p4,p1,p3,prec); /* (4 y)/(2y+1) */
     acb_add_si(p5,e,4,prec); /* e+4 */
     acb_mul(p6,p5,p5,prec); /* (e+4)**2 */
     acb_div_si(p7,p6,8,prec);/* (e+4)**2/8 */
     acb_sub_si(p8,p7,1,prec); /* (e+4)**2/8 -1*/
     acb_mul(p9,p8,p4,prec); /* [ (e+4)**2/8 -1 ] [ 4y /(2y+1)] */
     acb_mul(p10,p9,&g0[y],prec);/* [ (e+4)**2/8 -1 ] [ 4y /(2y+1)] g0[y]*/

     acb_sub_si(p12,p3,2,prec); /* 2y-1 */
     acb_div(p13,p12,p3,prec);/* ( 2y-1)/(2y+1) */
     acb_mul(p14,p13,&g0[y-1],prec); /* ( 2y-1)/(2y+1) g0[y-1] */
     acb_sub(p15,p10,p14,prec); /* [ (e+4)**2/8 -1 ] [ 4y /(2y+1)] g0[y] -  ( 2y-1)/(2y+1) g0[y-1]  */
     acb_set(&g0[y+1],p15);
     y=y+1;
    }


   acb_clear(p1);
    acb_clear(p2);
    acb_clear(p3);
    acb_clear(p4);
    acb_clear(p5);
    acb_clear(p6);
    acb_clear(p7);
    acb_clear(p8);
    acb_clear(p9);
    acb_clear(p10);
    acb_clear(p11);
    acb_clear(p12);
    acb_clear(p13);
    acb_clear(p14);
    acb_clear(p15);
    acb_clear(yc);

    return (g0);
}


acb_ptr g1f_mp(acb_t e,int ymax,acb_ptr g0,int prec){
  acb_t p1,p2,p3,p4,p5,p6;
   acb_ptr g1;
   int y;

  acb_init(p1);
   acb_init(p2);
   acb_init(p3);
   acb_init(p4);
   acb_init(p5);
   acb_init(p6);

   g1= _acb_vec_init(ymax+1);

   acb_add_si(p1,e,4,prec); /* e+4*/
   acb_mul(p2,&g0[0],p1,prec); /* (e+4) g0[0] */
   acb_sub_si(p3,p2,1,prec); /* (e+4) g0[0] -1 */
   acb_div_si(&g1[0],p3,4,prec); /* ((e+4) g0[0] -1) / 4 */
   
   /*   g1[0]=((e+mpf(4))*g0[0]-mpf(1))/mpf(4) */
   y=1;
   while (y<ymax+1){
     acb_add_si(p1,e,4,prec); /* e+4*/
     acb_mul(p2,p1,&g0[y],prec); /* (e+4) g0[y] */
     acb_mul_si(p3,&g1[y-1],2,prec); /* 2 g1[y-1] */
     acb_sub(p4,p2,p3,prec); /* (e+4) g0[y] - 2 g1[y-1] */
     acb_div_si(&g1[y],p4,2,prec); /* ( (e+4) g0[y] - 2 g1[y-1] )/2 */
     /* g1[y]=((e+mpf(4))*g0[y]-mpf(2)*g1[y-1])/mpf(2)*/
     y=y+1;
   }
   acb_clear(p1);
   acb_clear(p2);
   acb_clear(p3);
   acb_clear(p4);
   acb_clear(p5);
   acb_clear(p6);

   return (g1);
}



void G0(struct INPUT GP, struct OUTPUT GV){
  FILE* fp;
  acb_t negf,e,p1,p2,p3,p4;
  arb_t Gr,Gi;
  acb_mat_t g;
  int y,s,i;
  int ymax,prec;
  acb_ptr g0,g1;
  acb_init(negf);
  acb_init(e);
  arb_init(Gr);
  arb_init(Gi);
   acb_init(p1);
   acb_init(p2);
   acb_init(p3);
   acb_init(p4);
  ymax=GP.ymax;
  prec=GP.prec;
  
  if (GP.IsF==1) {
    acb_set_d(negf,GP.f);
    acb_neg(negf,negf);
    acb_exp(e,negf,prec); 
    acb_neg(e,e);/*e=-exp(-f)*/
  }
  else {
    acb_set_d_d(e,GP.er,GP.ei);
  }
      
  acb_mat_init(g,ymax+1,ymax+1);
  g0=g0f_mp(GP.f,e,GP.IsF,GP.ymax,GP.prec);
  g1=g1f_mp(e,GP.ymax,g0,GP.prec);
  for(i=0;i<ymax+1;i++){
    acb_set(acb_mat_entry(g,0,i),&g0[i]);
    acb_set(acb_mat_entry(g,1,i),&g1[i]);
  }
  
  for(y=0;y<ymax+1;y++){
    acb_get_real(Gr,&g0[y]);   
    GV.Gr[y][y]=arf_get_d(arb_midref(Gr),ARF_RND_DOWN);
    acb_get_imag(Gi,&g0[y]);
    GV.Gi[y][y]=arf_get_d(arb_midref(Gi),ARF_RND_DOWN);
  }

  for( y=0;y< ymax; y++){
    acb_get_real(Gr,&g1[y]);
    GV.Gr[y+1][y]=arf_get_d(arb_midref(Gr),ARF_RND_DOWN);
    acb_get_imag(Gi,&g1[y]);
    GV.Gi[y+1][y]=arf_get_d(arb_midref(Gi),ARF_RND_DOWN);
  }
  for(s=1;s<ymax;s++){
    acb_add_si(p1,e,4,prec); /* e+4 */
    acb_mul(p2,p1,acb_mat_entry(g,s,0),prec); /* (e+4) * g[s,0] */
    acb_mul_si(p3,acb_mat_entry(g,s-1,1),2,prec);/* 2* g[s-1,1] */
    acb_sub(p4,p2,p3,prec);/*  (e+4) * g[s,0] - 2* g[s-1,1]  */
    acb_sub(acb_mat_entry(g,s+1,0),p4,acb_mat_entry(g,s-1,0),prec);
    /*g[s+1,0]=(e+mpf(4))*g[s,0]-mpf(2)*g[s-1,1]-g[s-1,0]*/
    acb_get_real(Gr,acb_mat_entry(g,s+1,0));
    GV.Gr[s+1][0]=arf_get_d(arb_midref(Gr),ARF_RND_DOWN);

    acb_get_imag(Gi,acb_mat_entry(g,s+1,0));
    GV.Gi[s+1][0]=arf_get_d(arb_midref(Gi),ARF_RND_DOWN);

    for (y=1;y<ymax-s;y++){
      acb_mul(p2,p1,acb_mat_entry(g,s,y),prec);/* (e+4) g[s,y] */
      acb_sub(p3,p2,acb_mat_entry(g,s-1,y+1),prec);
      acb_sub(p4,p3,acb_mat_entry(g,s-1,y),prec);
      acb_sub(acb_mat_entry(g,s+1,y),p4,acb_mat_entry(g,s+1,y-1),prec);
      /*g[s+1,y]=-g[s+1,y-1]-g[s-1,y]-g[s-1,y+1]+(e+mpf(4))*g[s,y]*/
      acb_get_real(Gr,acb_mat_entry(g,s+1,y));
      GV.Gr[y+s+1][y]=arf_get_d(arb_midref(Gr),ARF_RND_DOWN);

     acb_get_imag(Gi,acb_mat_entry(g,s+1,y));
     GV.Gi[y+s+1][y]=arf_get_d(arb_midref(Gi),ARF_RND_DOWN);
    }
  }

    _acb_vec_clear(g0, ymax+1); /*This memory was allocated in subroutines*/
    _acb_vec_clear(g1,ymax+1); 

  acb_mat_clear(g);
  
  acb_clear(negf);
  acb_clear(e);
  arb_clear(Gr);
  arb_clear(Gi);
  acb_clear(p1);
  acb_clear(p2);
  acb_clear(p3);
  acb_clear(p4);
}


/*
def g0f_mp(e,ymax):
    g0=zeros(ymax+1,'object')
    g0[0]=G0_00_c_mp(e)
    g0[1]=G0_11_c_mp(e)
    y=1
    while (y<ymax):
       g0[y+1]= mpf(4)*y/(mpf(2)*y+mpf(1))*((e+mpf(4))**2/mpf(8)-mpf(1))*g0[y]-(mpf(2)*y-mpf(1))/(mpf(2)*y+mpf(1))*g0[y-1]
       y=y+1
    return g0

def g1f_mp(e,ymax,g0):
    g1=zeros(ymax+1,'object')
    g1[0]=((e+mpf(4))*g0[0]-mpf(1))/mpf(4)
    y=1
    while y<ymax+1:
        g1[y]=((e+mpf(4))*g0[y]-mpf(2)*g1[y-1])/mpf(2)
        y=y+1
    return g1

def gsf_mp(e,ymax):
    g=zeros([ymax+1,ymax+1],'object')
    g0=g0f_mp(e,ymax)
    g1=g1f_mp(e,ymax,g0)
    g[0,:]=g0[:]
    g[1,:]=g1[:]
    G=zeros([ymax+1,ymax+1],'complex')
    for y in range(ymax+1):
        G[y,y]=g0[y]
    for y in range(ymax):
        G[y+1,y]=g1[y]
    for s in range(1,ymax):
        g[s+1,0]=(e+mpf(4))*g[s,0]-mpf(2)*g[s-1,1]-g[s-1,0]
        G[s+1,0]=g[s+1,0]
        for y in range(1,ymax-s):
            g[s+1,y]=-g[s+1,y-1]-g[s-1,y]-g[s-1,y+1]+(e+mpf(4))*g[s,y]
            G[y+s+1,y]=g[s+1,y]
    return G
*/
