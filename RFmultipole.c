/*  Implementing RF multipole, version 1...progress so far...
    2 warniings generated in total with gcc on Mac OSX

    Inputs given: n; R; KNn; L; vn; kRF; KSn; L; phin; x; y; psc
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


float * ctaylor(float x, float y, float kn[], float ks[], int polySize){
  float dpx = kn[polySize - 1];          
  float dpy = ks[polySize - 1];  

  for (int i = (polySize-2); i >= 0 ; i--){ 
    dpx = kn[i] + (dpx*x - dpy*y)/((float)(i+1)); 
    dpy = ks[i] + (dpx*y + dpy*x)/((float)(i+1)); 

  }
  float realdXdY [2] = {dpx, dpy};
  printf("(%f, %f ) ", realdXdY[0], realdXdY[1]);

  return realdXdY; // warning, OK: let memory be freed

} // end ctaylor


float * ztaylor(float x, float y, float kn[], float ks[], int polySize){
  float complex z  = x + (1.0*I)*y; 
  float complex res = 0;

  for (int i = 0; i < polySize; i++){

    printf("%f ", kn[i]);
    printf("%f ", ks[i]);
    printf("%d ", i);
    res += (kn[i] + ((1.0*I)*ks[i]))*cpow(z , i)/factorial(i);

  }
  float complexReal [2] = {creal(res), cimag(res)};
  printf("(%f, %f )\n", complexReal[0], complexReal[1]);
  
  return complexReal; // warning, OK: let memory be freed

} // end ztaylor


 
int main()
{
  float x = 2;
  float y = 0;
  float kn [5] = {1,3,3,4,1};
  float kx [5] = {4,3,3,2,-4};
  int polySize = 5;

  ctaylor(x, y, kn, kx, polySize);
  ztaylor(x, y, kn, kx, polySize);

  for(int i = 1; i < (polySize+1); i++){
    float knn [i];
    float kxx [i];

    for (int j =0; j < i; j++){
      knn[j] = kn[j];
      kxx[j] = kx[j];


    }    
    ctaylor(x, y, kn, kx, i);
    ztaylor(x, y, knn, kxx, i);


  }



  return 0;  


}