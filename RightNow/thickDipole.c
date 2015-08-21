/*  Implementing Thick Dipole, Equations 34-42 in SixTrack Physics Manual (Revised version)
Author: Ramya Bhaskar 8/21/2015
    - No errors or warnings generated.
    - Compile with command: gcc -o thickDipole thickDipole.c

      - Current program conflicting with python benchmark program
*/

#include <stdio.h>
#include <string.h>
#include <math.h>



void thickDipole(float alpha, float B, float B0, float Chi, float delta, float hx, float hy, float k0, float L, float px0, float py0, float sigma0, float x0, float y0){


	float Gx = Chi* ( k0 *hx/ (1+delta) ); // Equations 33
	float Gy = Chi* ( k0 *hy/ (1+delta) ); // Equations 33

	float Cx = cos( sqrt(Gx) *L ); // Equations 34
	float Cy = cos( sqrt(Gy) *L ); // Equations 34

	float Sx = sin( sqrt(Gx) *L ); // Equations 34
	float Sy = sin( sqrt(Gy) *L ); // Equations 34

	float x = (Cx*x0) + (Sx*px0)/(sqrt(Gx)*(1+delta)) + (delta/ hx)* (1- Cx) ; // Equations 35

	float px = (-sqrt(Gx)* (1+ delta)* Sx *x) + (Cx*px0) + (delta*sqrt(1+delta)*Sx) ; // Equations 36

	float y  = (Cy*y) + (Sy*py0)/(sqrt(Gy)*(1+delta)) + (delta/ hy)* (1- Cy); // Equations 37

	float py = (-sqrt(Gy)* (1+ delta)* Sy *y) + (Cy*py0) + (delta*sqrt(1+delta)*Sy) ; // Equations 38

	// using new, updated values of x, px, y, py in calculating sigma below

	float sigma3 = (-B0/B)*( hx*Sx*x/sqrt(Gx) + (1-Cx)/hx + hy*Sy*y/sqrt(Gy) + (1-Cy)*py/sqrt(hy) +  
		delta*(2*L - Sx/sqrt(Gx) -Sy/sqrt(Gy) ) ); // Equations 39

	float sigma2 = (-B0/(4*B))*( Gx*( L - Cx*Sx/sqrt(Gx))*pow(x-delta/hx, 2) + 
		(L + Cx*Sx/sqrt(Gx))*(px*px)/pow(1+delta,2) - 
		(x - delta/hx)*2*Sx*Sx*px/(1+delta) ); // Equations 40

	float sigma1 = Gy*( (L - Cy*Sy/sqrt(Gy))*pow(y - delta/hy, 2) +
		(L + Cy*Sy/sqrt(Gy))*py*py/pow(1 + delta, 2) - 
		(y-delta/hy)*2*Sy*Sy*py/(1 + delta) ) ; // Equations 41

	float sigma = sigma0 + L*(1 - B0/B) + sigma1 + sigma2 + sigma3; // Equations 42

	printf("(%f, %f, %f, %f, %f, %f, %f )", Sx, Sy, x, px, y, py, sigma); // print final values



} // end function thickDipole



int main()
{
	// Variable Initializations 
    /*---------------------------*/
	float alpha; 
	float B; 
	float B0; 
	float Chi;
	float delta;
	float hx;
	float hy;
	float k0;
	float L;
	float px0;
	float py0;
	float sigma0;
	float x0;
	float y0;


    // Function Calls & Outputs
    /*---------------------------*/
    thickDipole(alpha, B, B0, Chi, delta, hx, hy, k0, L, px0, py0, sigma0, x0, y0);

	return 0;
} // end function main



