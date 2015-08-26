/*  Implementing RF Multipole, Equations 166-168 in SixTrack Physics Manual (Revised version)
Author: Ramya Bhaskar 8/26/2015
    - Minimized prior script of three seperate functions 
      into one function.
    - Avoiding use of factorial function.
    - Avoiding use of complex data type, to ease porting to opencl.
    - No errors or warnings generated.
    - Compile with command: gcc -o RFmultipole RFmultipole.c

      - Current program conflicting with python benchmark program
      - Current program being edited while referencing benchmark file
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

void taylor(float x, float y, float z, float kn[], float ks[], int polySize){
  // Variable Initializations 
  /*---------------------------*/

  float dpx;
  float dpy;
  float dpt = 0;   // Delta Time (change in time)
  float zreal = 0;  // Real-valued portion of (x+iy)^n
  float zimag = 0;  // Imaginary-valued portion of (x+iy)^n

  for (int n = polySize; n > 0 ; n--){ 

    dpx = kn[n];   // X Momenta         
    dpy = ks[n];   // Y Momenta

    zreal = pow(( dpx*x - dpy*y),n) /n; // Real-valued portion of (x+iy)^n
    zimag = pow(( dpx*y + dpy*x),n) /n; // Imaginary-valued portion of (x+iy)^n

    dpx =  zreal + dpx;
    dpy =  zimag + dpy;
    dpt =  zreal + dpt;
  }

  printf("(%f, %f, %f ) ", dpx, dpy, dpt); // Print final values

} // end taylor

 
int main()
{
    // Variable Initializations 
    /*---------------------------*/
    float x = 1; 
    float y = 1;
    float z = 1;

    int polynomialMax = 4;
    float K_Nn[4] = {0, 1, 2, 3};
    float K_Sn[4] = {0, 1, 2, 3};
    
    // Function Calls & Outputs
    /*---------------------------*/
    taylor(x, y, z, K_Nn, K_Sn, polynomialMax);


    return 0;  


} // end function main




