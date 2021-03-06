/*  Implementing RF Multipole, Equations 166-168 in SixTrack Physics Manual (Revised version)
Author: Ramya Bhaskar 8/21/2015
    - Minimized prior script of three seperate functions 
      into one function.
    - Avoiding use of factorial function.
    - Avoiding use of complex data type, to ease porting to opencl.
    - No errors or warnings generated.
    - Compile with command: gcc -o RFmultipole RFmultipole.c

      - Current program conflicting with python benchmark program
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "complex.h"


float factorial(int n)
{ // couldn't find an already defined factorial function
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
} // end factorial


void taylor(float x, float y, float z, float kn[], float ks[], int polySize, float L, float k_RF, float v_n, float phi_n, float q, float V_RF, float ps, float c){
  // Variable Initializations 
  /*---------------------------*/
  double dpx = 0;   // X Momenta         
  double dpy = 0;   // Y Momenta
  double dpt = 0;   // Delta Time (change in time)
  float zreal = 0;  // Real-valued portion of (x+iy)^n
  float zimag = 0;  // Imaginary-valued portion of (x+iy)^n
  float Quanitity =  0; // Initializing summation quantity

  for (int n = polySize; n > 0 ; n--){ 

    Quanitity = kn[n-1] * L * cos(v_n - k_RF*z); // real-valued portion of each Eqn, 166-168
    zreal = pow( dpx*x - dpy*y, n); // Real-valued portion of (x+iy)^n
    zimag = pow( dpx*y + dpy*x, n); // Imaginary-valued portion of (x+iy)^n

    /* Here, the division by n! is not explicit in the code. Note how the quantity 
       dpx, dpy, and dpt are all recursivly defined within this for loop. Then see that
       because they are recursivelt being defined, the factor of n that is being divided out 
       each time from each term is being cumalitively multiplied by 1 less than itself. 
       
       More clearly: the recusursion allows for 1/n! to be computed because with each loop,
       the quantity of concern is divided multiplied by: (1/1)...(1/(n-1))*(1/n).
    */

    dpx = -((Quanitity +  L*ks[n]*cos(phi_n - k_RF*z))*(zreal)  + dpx) /n; // Eqn 166
    dpy = ((Quanitity +  L*ks[n]*cos(phi_n - k_RF*z))*(zimag) + dpy) / n; // Eqn 167
    dpt = ((Quanitity +  L*ks[n]*sin(phi_n - k_RF*z))*(zreal) + dpt) / n; // Eqn 168

  }
  dpt = ((q*V_RF)/(ps*c))*sin(0 - k_RF*z) - (k_RF * dpt) ; // Eqn 168 continued 

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
  float K_Nn[3] = {3,2,1};
  float K_Sn[3] = {5,3,2};
  float polynomialMax = 3;
  float L = 1; 
  float k_RF = 0;
  float v_n = 1; 
  float phi_n = 0;
  float q = 1;
  float V_RF = 0;
  float ps = 1;
  float c = 299792458; // light speed
  float vrf = 1;

  taylor(x, y, z, K_Nn, K_Sn, polynomialMax, L, k_RF, v_n, phi_n, q, V_RF, ps, c);


  return 0;  


}