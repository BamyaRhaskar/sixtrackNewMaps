/*  Implementing Exact Bend, Equations 44-49 in SixTrack Physics Manual (Revised version)
	- Drawing from definitions in lines 32 and 33 in Physics Manual as well.
	- Instructions were to derive eq.45, knowing that theta is h*L.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "complex.h"

/*
	Lines 44 - 49 from Physics Manual
		- Thick Dipole Equations
*/


float xMomenta (float b1, float delta, float h, float px0, float py, float rho, float s, float x){

	float theta = h*s; 
	float zMomenta_0  = sqrt( (1 + delta*delta) - pow(px0, 2) - (py*py) ); // <- xMomenta at 0, is simply px0  

	float px = px0*cos(theta) + (zMomenta_0 - b1 * (rho + x))*sin(theta);

	return px; 

} // end function xMomenta


float zMomenta( float b1, float delta, float h, float px0, float py, float rho, float s, float x){

	float theta = h*s;
	float pz = sqrt( (1 + delta*delta) - pow(xMomenta(b1, delta, h, px0, py, rho, s, x), 2) - (py*py) );

	return pz;

} // end function zMomenta


float alpha(float b1, float delta, float h, float px0, float py, float rho, float s, float x){

	float alpha = asin( xMomenta(b1, delta, h, px0, py, rho, s, x) / sqrt((1 + delta*delta) - (py*py) ) );

	return alpha;

} // end function alpha

// float x (float b1, float delta, float h, float L,  float px0, float rho, float x){

// 	float theta = h*L;
// 	float x = (rho/b1)*((1/rho)*zMomenta(L, delta, theta) -  xmomentaPrime(px0, L, delta, b1, rho, x, theta) - b1); 

// 	return x; 

// } // end function x

// float xmomentaPrime( float b1, float delta, float h, float L, float px0, float rho, float x){

// 	float theta = h*L; 
// 	float pxPrime = -px0*sin(theta)*L  - b1 * (rho + x))*cos(theta)*L;

// 	return pxPrime;

// } // end function xmomentaPrime

// float y ( float b1, float delta, float h, float L, float rho, float py, float y0){

// 	float theta = h*L; 
// 	float y = y0 + ((py*L)/(b1*rho)) + (py/L)*(alpha(0, delta, theta, py) - alpha(L, delta, theta, py));

// 	return y;

// } // end function y

// float ct ( float b1, float ct0, float delta, float h, float L, float rho, float py){

// 	float theta = h*L; 
// 	float ct = ct0 + ((1 + delta)*L)/(b1*rho) + ((1+delta)/b1)*(alpha(0, delta, theta, py) - alpha(L, delta, theta, py));

// 	return ct;


// } // end function ct


int main(){

	float theta = 0; 
	float rho = 0; 
	float delta = 0;
	float q = 0;
	float q0 = 0;
	float P0 = 0;
	float hx = 0;
	float hy = 0;
	float h = 0; 
	float L = 1; 
	float By = 0; 
	float Bx = 0;

	float b1 = (q0 / P0) * By; 


	return 0;
}
