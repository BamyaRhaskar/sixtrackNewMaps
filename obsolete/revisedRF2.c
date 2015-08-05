/*  Implementing RF multipole, version 3

    Referencing Equations 166 - 168 from the revised Physics Manual
      Attempting to minimize prior three script of three seperate functions 
      into 1 single function...did not edit/reinterpret the equations at all, when 
      implementing them within this program. 

    No Errors generated so far...values kind of seem to look like they are 
    reasonable, but still need to test against a benchmark program. 

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "complex.h"


float factorial(int n)
{ // couldn't find an already defined factorial function
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
} // end factorial


void taylor(float x, float y, float z, float kn[], float ks[], int polySize, float L, float k_RF, float v_n, float phi_n, float q, float V_RF, float ps, float c, float vrf){
  float complex dpx = 0;          
  float complex dpy = 0; 
  float complex dpt = 0;
  float complex complex_powered = 0;
  float realQuanitity =  0;

  for (int n = polySize; n >= 0 ; n--){ 

    realQuanitity = kn[n-1] * L * cos(v_n - k_RF*z); // real-valued portion of each Eqn, 166-168
    complex_powered = cpow((x + I*y), n); // complex-valued portion of each Eqn, 166-168

    dpx = -(1/factorial(n))*(realQuanitity +  I*L*ks[n]*cos(phi_n - k_RF*z))*(complex_powered)+ dpx; // Eqn 166
    dpy = (1/factorial(n))*(realQuanitity +  I*L*ks[n]*cos(phi_n - k_RF*z))*(complex_powered)+ dpy; // Eqn 167
    dpt = (1/factorial(n))*(realQuanitity +  I*L*ks[n]*sin(phi_n - k_RF*z))*(complex_powered)+ dpt; // Eqn 168

  }
  dpt = ((q*V_RF)/(ps*c))*sin(vrf - k_RF*z) - (k_RF * dpt) ; // Eqn 168 continued 

  float deltapx = creal(dpx);
  float deltapy = cimag(dpy);
  float deltapt = creal(dpt);

  printf("(%f, %f, %f ) ", deltapx, deltapy, deltapt);

} // end taylor

 
int main()
{
  float x = 1; 
  float y = 1;
  float z = 1;
  float K_Nn[5] = {4,3,2,1,0};
  float K_Sn[5] = {4,3,2,1,0};
  float polynomialMax = 5;
  float L = 1; 
  float k_RF = 1;
  float v_n = 1; 
  float phi_n = 1;
  float q = 1;
  float V_RF = 1;
  float ps = 1;
  float c = 1;
  float vrf = 1;

  taylor(x, y, z, K_Nn, K_Sn, polynomialMax, L, k_RF, v_n, phi_n, q, V_RF, ps, c, vrf);


  return 0;  


}