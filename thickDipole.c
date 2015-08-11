/*  Implementing Thick Dipole, Equations 44-49 in SixTrack Physics Manual (Revised version)

	- I am not sure if this in fact is supposed to be exact bend, but I should have 
	  clarified...I am using the explicit definitions in the Physics Manual. 

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


float alpha( float s, float delta, float theta){

	float alpha = arcsin( xMomenta() / sqrt((1 + delta*delta) - pow(yMomenta(), 2) ));

	return alpha;

} // end function alpha

float zMomenta( float s , float delta, float theta){

	float pz = sqrt( (1 + delta)*(1 + delta) - pow(xMomenta(), 2) - pow(yMomenta(), 2) );

	return pz;

} // end function zMomenta

float xMomenta ( float s, float delta, float theta){

	float px = px*cos(theta) + (zMomenta() - b1 * (rho + x))sin(theta)

	return px; 

} // end function xMomenta

// float x ( float s, float delta, float theta){


// } // end function x

// float y ( float s, float delta, float theta){


// } // end function y

// float ct ( float s, float delta, float theta){

	


// } // end function ct


int main(){

	float theta; 
	float b1; 
	float rho; 
	float delta;
	float q;
	float q0;
	float hx;
	float hy;
	float h; 
	float L; 
	float By; 
	float Bx;

	theta = h * L; 
	b1 = (q0 / P0) * By; 

	return 0;
}
