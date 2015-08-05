/*  Implementing RF multipole, version 1...convert from python...
    4 warniings generated in total
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "complex.h"

int factorial(int n)
{ //couldn't find an already defined factorial function
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
} //end factorial


double * ctaylor(double x, double y, double kn[], double ks[]){
  int polySize = sizeof(kn)/sizeof(kn[0]);//generates warning,
  double dpy = kn[polySize - 1];          //but its fine, really.
  double dpx = ks[polySize - 1];          

  for (int i = 0; i < polySize; i++){

    dpx = kn[i] + (dpx*x - dpy*y)/((float)(i+1)); 
    dpy = ks[i] + (dpx*x + dpy*y)/((float)(i+1)); 
  
  }
  double dscrtXandY [2] = {dpx, dpy};

  return dscrtXandY; //1 warning: fine for now...let memory be freed...
} //end ctaylor


double * ztaylor(double x, double y, double kn[], double ks[]){
  int polySize = sizeof(kn)/sizeof(kn[0]);//generates same warning
  double complex z  = x + (1.0*I)*y;      //as line 16, but stil ok.
  double complex res = 0;

  for (int i = 0; i < polySize; i++){

    res += pow((kn[i] + (1.0*I)*ks[i])*z, (i+1))/factorial(i+1);

  }
  double complexReal [2] = {creal(res), cimag(res)};

  return complexReal; //1 warning: fine for now...let memory be freed...

} //end ztaylor




double hornersMethod(double polynomial[], int n, int x)
// {

// for i in range(1,len(kn)+1):
//   print ctaylor(x,y,kn[:i],ks[:i]),
//   print ztaylor(x,y,kn[:i],ks[:i])

 
}
 
int main()
{
  double kn [2] = {2, 4};
  int polySize = sizeof(kn)/sizeof(kn[0]);
  printf("Array length is hopefully 2: %d", polySize);
  printf("\n");

  return 0;  


}