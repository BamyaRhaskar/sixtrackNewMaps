/*  Implementing RF multipole, version 1...progress so far...
    1 Error generated so far

    I just wanted to know if this interpretation makes any sense...

    since dpx and dpy are already incorprated in the functions ctauler and ztaylor
    would the only additions be just multipltying the kn and ks  vectors by the correct sine and cosine terms..?

    first match python program output
    then manipulate current functions, with cos() and sin()
    to match equations 159-161.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "complex.h"


float factorial(int n)
{ // couldn't find an already defined factorial function
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
} // end factorial


float * ctaylor(float x, float y, float kn[], float ks[], int polySize, float L, float v_n, float k_RF, float complex zz, float phi_n){
  float dpx = kn[polySize - 1];          
  float dpy = ks[polySize - 1];  

  for (int i = (polySize-2); i >= 0 ; i--){ 
    dpx = (1/factorial(i))*(kn[i]*L*cos(v_n - k_RF*zz) + (dpx*x - dpy*y)/((float)(i+1))); 
    dpy = (1/factorial(i))*(ks[i]*L*cos(phi_n - k_RF*zz) + (dpx*y + dpy*x)/((float)(i+1))); 

  }
  float realdXdY [2] = {dpx, dpy};
  printf("(%f, %f ) ", realdXdY[0], realdXdY[1]);

  return realdXdY; // warning, OK: let memory be freed

} // end ctaylor


// Hesistant about this until I know that the dpx and dpy make sense...
// 
float * p_tctaylor(float x, float y, float kn[], float ks[], int polySize, float L, float v_n, float k_RF, float complex zz, float phi_n, float v_RF, float q, float p_s, float c, float V_RF){
  float dpx = kn[polySize - 1];          
  float dpy = ks[polySize - 1];  

  for (int i = (polySize-2); i >= 0 ; i--){ 
    dpx = kn[i]*L*sin(v_n - k_RF*zz) + (dpx*x - dpy*y)/((float)(i+1)); 
    dpy = ks[i]*L*sin(phi_n - k_RF*zz) + (dpx*y + dpy*x)/((float)(i+1)); 

  }

  float firstTerm = (q*V_RF/(p_s*c))*sin(v_RF -k_RF*zz);
  dpy = firstTerm - k_RF*dpy;
  dpx = firstTerm - k_RF*dpx;

  float realdXdY [2] = {dpx, dpy};
  printf("(%f, %f ) ", realdXdY[0], realdXdY[1]);

  return realdXdY; // warning, OK: let memory be freed

} // end ctaylor


float * ztaylor(float x, float y, float kn[], float ks[], int polySize, float L, float v_n, float k_RF, float complex zz, float phi_n){
  float complex z  = x + (1.0*I)*y; 
  float complex res = 0;

  for (int i = 0; i < polySize; i++){
    
    res += (1/factorial(i))*((kn[i]*L*cos(v_n - k_RF*zz) + ((1.0*I)*ks[i]*L*cos(phi_n - k_RF*zz)))*cpow(z , i)/factorial(i));

  }
  float complexReal [2] = {creal(res), cimag(res)};
  printf("(%f, %f )\n", complexReal[0], complexReal[1]);
  
  return complexReal; // warning, OK: let memory be freed
  // return creal(res);

} // end ztaylor


 
int main()
{
  // float K_Nn [5] = {1,3,3,4,1};
  float K_Nn [5] = {4,3,2,1,0};
  float L = 1;
  float v_n = 1;
  float k_RF = 1;
  float v_RF = 1;
  float complex z;
  // float K_Sn [5] = {4,3,3,2,-4};
  float K_Sn [5] = {4,3,2,1,0};
  float phi_n =1;
  float x =1;
  float y =1;
  int n =1;
  float q =1;
  float p_s =1;
  float c =1; 
  float V_RF =1; 
  float complex sumTotal = 0;

  z = z*I*1.0;

  ctaylor(x, y, K_Nn, K_Sn, n, L, v_n, k_RF, z, phi_n);
  ztaylor(x, y, K_Nn, K_Sn, n, L, v_n, k_RF, z, phi_n);
  p_tctaylor(x, y, K_Nn, K_Sn, n, L, v_n, k_RF, z, phi_n, v_RF, q, p_s, c, v_RF);
    


  return 0;  


}