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
    dpx = kn[i]*L*cos(v_n - k_RF*zz) + (dpx*x - dpy*y)/((float)(i+1)); 
    dpy = ks[i]*L*cos(phi_n - k_RF*zz) + (dpx*y + dpy*x)/((float)(i+1)); 

  }
  float realdXdY [2] = {dpx, dpy};
  printf("(%f, %f ) ", realdXdY[0], realdXdY[1]);

  return realdXdY; // warning, OK: let memory be freed

} // end ctaylor


float * ztaylor(float x, float y, float kn[], float ks[], int polySize, float L, float v_n, float k_RF, float complex zz, float phi_n){
  float complex z  = x + (1.0*I)*y; 
  float complex res = 0;

  for (int i = 0; i < polySize; i++){
    
    res += (kn[i]*L*cos(v_n - k_RF*zz) + ((1.0*I)*ks[i]*L*cos(phi_n - k_RF*zz)))*cpow(z , i)/factorial(i);

  }
  float complexReal [2] = {creal(res), cimag(res)};
  printf("(%f, %f )\n", complexReal[0], complexReal[1]);
  
  // return complexReal[0]; // warning, OK: let memory be freed
  return creal(res);

} // end ztaylor


 
int main()
{
  float K_Nn [1] = {0}; 
  float L;
  float v_n;
  float k_RF;
  float complex z;
  float K_Sn [1]  = {0};
  float phi_n;
  float x;
  float y;
  int n;
  float complex sumTotal = 0;

  z = z*I*1.0;

  for (int i = 0; i <= n; i++){

    float fact = factorial(i);

    float sum =  ctaylor(x, y, K_Nn, K_Sn, n, L, v_n, k_RF, z, phi_n);
    // float complex sum = ztaylor(x, y, K_Nn, K_Sn, n, L, v_n, k_RF, z, phi_n)

    sum = sum * fact;

    sumTotal += sum;


  }



  return 0;  


}