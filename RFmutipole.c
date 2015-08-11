/*  Implementing RF multipole, version 2

    -Referencing Equations 166 - 168 from the revised Physics Manual
      Minimized prior script of three seperate functions 
      into one function.
    -No erros or warnings generated during compilation.
    -Avoiding use of factorial function.
    -Avoiding use of complex data type, to ease porting to opencl.
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

  double dpx = 0;          
  double dpy = 0; 
  double dpt = 0;
  float zreal = 0;
  float zimag = 0;
  float Quanitity =  0;

  for (int n = polySize; n >= 0 ; n--){ 

    Quanitity = kn[n-1] * L * cos(v_n - k_RF*z); // real-valued portion of each Eqn, 166-168
    zreal = pow( dpx*x - dpy*y, n); // real-valued portion of z
    zimag = pow( dpx*y + dpy*x, n); // complex-valued portion of z

    dpx = -((Quanitity +  L*ks[n]*cos(phi_n - k_RF*z))*(zreal)  + dpx) /n; // Eqn 166

    dpy = ((Quanitity +  L*ks[n]*cos(phi_n - k_RF*z))*(zimag) + dpy) / n; // Eqn 167

    dpt = ((Quanitity +  L*ks[n]*sin(phi_n - k_RF*z))*(zreal) + dpt) / n; // Eqn 168

  }
  dpt = ((q*V_RF)/(ps*c))*sin(vrf - k_RF*z) - (k_RF * dpt) ; // Eqn 168 continued 

  double deltapx = (dpx);
  double deltapy = (dpy);
  double deltapt = (dpt);

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