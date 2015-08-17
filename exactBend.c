/*  Implementing Exact Bend, Equations 44-49 in SixTrack Physics Manual (Revised version)
	- Drawing from definitions in lines 32 and 33 in Physics Manual as well.
	- Instructions were to derive eq.45, knowing that theta is h*L.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "complex.h"

/*
	Lines 32 & 33 from Physics Manual
		- Defined Quanitites
*/

float Gx(float q, float q0, float hx, float delta ){

	return ( (q/q0) * pow(hx, 2) / (1 + delta) );

} // end function Gx

float Gy(float q, float q0, float hy, float delta){

	return ( (q/q0) * pow(hy, 2) / (1 + delta) );

} // end function Gy

float Cxy(float G, float L){

	return ( cos( sqrt(G) * L ) ) ;

} // end function Cxy

float Sxy(float G, float L){

	return ( sin( sqrt(G) * L ) ) ;

} // end function Sxy


/*
	Lines 44 - 49 from Physics Manual
		- Thick Dipole Equations
*/


float alpha( float s, float delta, float theta, float py){

	float alpha = arcsin( xMomenta(s, delta, theta) / sqrt((1 + delta*delta) - (py*py) ) );

	return alpha;

} // end function alpha

float zMomenta( float s , float delta, float theta){

	float pz = sqrt( ((1 + delta)*(1 + delta)) - pow(xMomenta(s delta, theta), 2) - (py*py) );

	return pz;

} // end function zMomenta

float xMomenta ( float px0, float s, float delta, float b1, float rho, float x){

	float theta = h*s; 

	float px = px0*cos(theta) + (zMomenta(0, delta, theta) - b1 * (rho + x))sin(theta);

	return px; 

} // end function xMomenta

float x ( float L, float b1, float rho, float delta){

	float theta = h*L;

	float x = (rho/b1)*((1/rho)*zMomenta(L, delta, theta) -  xmomentaPrime(px0, L, delta, b1, rho, x, theta) - b1); 

	return x; 

} // end function x

float xmomentaPrime(float px0, float L, float delta, float b1, float rho, float x, float theta){

	float pxPrime = -px0*sin(theta)*L  - b1 * (rho + x))cos(theta)*L;

	return pxPrime;

} // end function xmomentaPrime

float y ( float y0, float delta, float theta, float rho, float b1, float py, float L){

	float theta = h*L; 

	float y = y0 + ((py*L)/(b1*rho)) + (py/L)*(alpha(0, delta, theta, py) - alpha(L, delta, theta, py));

	return y;

} // end function y

float ct ( float ct0, float delta, float theta, float rho, float b1, float py, float L){

	float theta = b1*L; 

	float ct = ct0 + ((1 + delta)*L)/(b1*rho) + ((1+delta)/b1)*(alpha(0, delta, theta, py) - alpha(L, delta, theta, py));

	return ct;


} // end function ct


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
