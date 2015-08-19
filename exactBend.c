/*  Implementing Exact Bend, Equations 44-49 in SixTrack Physics Manual (Revised version)
	- Drawing from definitions in lines 32 and 33 in Physics Manual as well.
	- Instructions were to derive eq.45, knowing that theta is h*L.
	- No errors or warnings generated.
	- Compile with command: gcc -o exactBend exactBend.c
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "complex.h"

/*
	Lines 44 - 49 from Physics Manual
		- Thick Dipole Equations
*/


float Px(float b1, float delta, float h, float px0, float py, float rho, float s, float x){

	float theta = h*s; 
	float Pz_at0  = sqrt( (1 + delta)*(1 + delta) - (px0*px0) - (py*py) ); // <- Px at 0, is simply px0  

	float Px = px0*cos(theta) + (Pz_at0 - (b1 * (rho + x)))*sin(theta);

	return Px; 

} // end function Px


float Pz(float b1, float delta, float h, float px0, float py, float rho, float s, float x){

	float theta = h*s;
	float Pz = sqrt( (1 + delta)*(1 + delta) - pow(Px(b1, delta, h, px0, py, rho, s, x), 2) - (py*py) );

	return Pz;

} // end function Pz


float alpha(float b1, float delta, float h, float px0, float py, float rho, float s, float x){

	float alpha = asin( Px(b1, delta, h, px0, py, rho, s, x) / sqrt((1 + delta*delta) - (py*py) ) );

	return alpha;

} // end function alpha

float PxPrime(float b1, float delta, float h, float L, float px0, float py, float rho, float x){

	float theta = h*L; 
	float zMomenta_0  = sqrt( (1 + delta)*(1 + delta) - (px0*px0) - (py*py) );

	float PxPrime = -px0*sin(theta)*L + (zMomenta_0 - (b1 * (rho + x)))*cos(theta)*L;

	return PxPrime;

} // end function PxPrime


float xCoordinate(float b1, float delta, float h, float L, float px0, float py, float rho, float x){

	float theta = h*L;
	float xCoordinate = (rho/b1) * ( ((1/rho) * Pz(b1, delta, h, px0, py, rho, L, x)) -  PxPrime(b1, delta, h, L, px0, py, rho, x) - b1); 

	return xCoordinate; 

} // end function xCoordinate


float yCoordinate(float b1, float delta, float h, float L, float px0, float py, float rho, float x, float y){

	float yCoordinate = y + ( (py*L)/(b1*rho) ) + (py/L)*(alpha(b1, delta, h, px0, py, rho, 0, x) - alpha(b1, delta, h, px0, py, rho, L, x));

	return yCoordinate;

} // end function yCoordinate

float ct(float b1, float ct0, float delta, float h, float L, float px0, float py, float rho, float x){

	float ct = ct0 + ((1 + delta)*L/(b1*rho)) + ((1+delta)/b1)*(alpha(b1, delta, h, px0, py, rho, 0, x) - alpha(b1, delta, h, px0, py, rho, L, x));

	return ct;


} // end function ct


int main(){
	float ct0 = 1;
	float delta  = 0; 
	float h = 1;
	float L = 1;
	float px0 = 0;
	float py = 0;
	float rho = 1;
	float s = 0;
	float x = 0;
	float y = 0; 

	float q0 = 1; 
	float P0 = 1; 
	float By = 1;
	float b1 = (q0 / P0) * By; 
	
	float value;

	value = Px(b1, delta, h, px0, py, rho, s, x);
	printf("Output Value for Px function: %f \n", value);

	value = Pz(b1, delta, h, px0, py, rho, s, x);
	printf("Output Value for Py function: %f \n", value);

	value = alpha(b1, delta, h, px0, py, rho, s, x);
	printf("Output Value for alpha function: %f \n", value);

	value = xCoordinate(b1, delta, h, L, px0, py, rho, x);
	printf("Output Value for xCoordinate function: %f \n", value);

	value = yCoordinate(b1, delta, h, L, px0, py, rho, x, y);
	printf("Output Value for yCoordinate function: %f \n", value);


	value = ct(b1, ct0, delta, h, L, px0, py, rho, x);
	printf("Output Value for ct function: %f \n", value);


	return 0;
}
