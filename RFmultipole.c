/*  Implementing RF multipole, version 1...progress so far...
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

  printf("%d, %d", dscrtXandY[0], dscrtXandY[1]);
  printf("\n");

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

  printf("%d, %d", complexReal[0], complexReal[1]);
  printf("\n");

  return complexReal; //1 warning: fine for now...let memory be freed...

} //end ztaylor


double hornersMethod(double polynomial[], int n, int x)
{
  // what will be in here...
}
 
int main()
{
  double x = 2;
  double y = 0;
  double kn [5] = {1,3,3,4,1};
  double kx [5] = {4,3,3,2,-4};
  // double realTaylor [2];
  // double complex complexTaylor [2];

  ctaylor(x, y, kn, kx);
  ztaylor(x, y, kn, kx);

  for(int i = 1; i < 6; i++){
    double knn [i];
    double kxx [i];

    for (int j =0; j < i; j++){
      knn[j] = kn[j];
      kxx[j] = kx[j];

    }
    ctaylor(x, y, knn, kxx);
    ztaylor(x, y, knn, kxx);

    // printf("%d, %d", realTaylor[0], realTaylor[1]);
    // printf("\n");
    // printf("%d, %d", complexTaylor[0], complexTaylor[1]);
    // printf("\n");

  }

  return 0;  


}