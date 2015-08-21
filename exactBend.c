/*  Implementing Exact Bend, Equations 44-49 in SixTrack Physics Manual (Revised version)
Author: Ramya Bhaskar 8/21/2015
	- Instructions were to derive eq.45, knowing that theta is h*L.
	- No errors or warnings generated.
	- Compile with command: gcc -o exactBend exactBend.c
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "complex.h"

/*
	Lines 44 - 49 from Physics Manual implemented below
		(Under Thick Dipole Section in Physics Manual)

	In the following six functions, we have implemented:
		-X Momenta at a later time del-t,
		-Z Momenta at a later time del-t,
		-Alpha at a later time del-t,
		-X Acceleration at a later time del-t,
		-X Position at a later time del-t,
		-Y Position at a later time del-t,
		-ct at a later time del-t.

	Throughout these functions, 's' and 'L' are units of length. 
	'L' and 's' are used interchangelbly as both discretized 
	units of length and generic variable terms for length-hence 
	the derivatives written out in L for PxPrime.

*/

void exactBend(float b1, float ct0, float delta, float h, float L, float px0, float py, float rho, float x, float y){

	/* Within this function, the math is not explicit. 
	   First we set the Bending Angle theta.
	*/
	float theta = h*L; // Bending Angle

	/* Then, from Equation 45, then jumping down to 47, 
	   we see that value of Z Momenta at Length 0 must 
	   be recomputed to get value at variable lenth 's'.

	   However, this implies that X Momenta must be 
	   computed with a set input length for bending 
	   angle of s = 0. With s = 0 as input, Equation 47
	   is reduced to: Px = px0*cos(theta), -> Px = px0. 
	*/
	float Pz_at0  = sqrt( (1 + delta)*(1 + delta) - (px0*px0) - (py*py) );  // Z Momenta at set length s = 0 
	float Px = px0*cos(theta) + (Pz_at0 - (b1 * (rho + x)))*sin(theta); 
	// ^^^ Final X Momenta at later time del-t
	// end function Px (X Momenta, Equation 47)

	/* 
	RESETTING: px0 to newly calculated Px, from the above ^^^
	
	px0 = Px; <- did not implement in the end. left this here for records purposes. 
	*/

	
	float Pz = sqrt( (1 + delta)*(1 + delta) - (Px*Px) - (py*py) ); 
	// ^^^ Final Z Momenta at later time del-t
	// end function Pz (Z Momenta, Equation 45)


	float alpha = asin( Px / sqrt((1 + delta*delta) - (py*py) ) );
	// ^^^ Final alpha at later time del-t
	// end function alpha (Alpha, Euqation 44)

	/* 
	   Commented below calculation out, since original value of Pz_at0 changes now that px0 = Px
	*/
	// float Pz_at0  = sqrt( (1 + delta)*(1 + delta) - (px0*px0) - (py*py) ); // Z Momenta at set length s = 0 
	
	float PxPrime = -px0*sin(theta)*L + (Pz_at0 - (b1 * (rho + x)))*cos(theta)*L;
	// ^^^ Final PxPrime at later time del-t
	// end function PxPrime (X Acceleration, not explicit in Manual)


	float xCoordinate = (rho/b1) * ((1/rho)*Pz -  PxPrime - b1);  
																						//(b1, h, L, px0, py, rho, x) 
	// ^^^ Final X Position at later time del-t
	// end function xCoordinate (X Position, Equation 46)


	float alpha_at0 = asin( px0 / sqrt((1 + delta*delta) - (py*py) ) ); // when 0 is passed into alpha, only px0 remains from Px
	float yCoordinate = y + ( (py*L)/(b1*rho) ) + (py/L)*(alpha_at0 - alpha); // alpha is implicitly understood to be at s/L
	// ^^^ Final Y Position at later time del-t
	// end function yCoordinate (Y Position, Equation 48)


	float ct = ct0 + ((1 + delta)*L/(b1*rho)) + ((1+delta)/b1)*(alpha_at0 - alpha);
	// ^^^ Final ct at later time del-t
	// end function ct (Equation 49)

	 printf("(Theta: %f,\nPz at 0: %f ,\nPx: %f,\nPz: %f,\nalpha: %f,\nPxPrime: %f,\nxCoordinate: %f,\nyCoordinate: %f,\nct: %f ) ", theta, Pz_at0, Px, Pz, alpha, PxPrime, xCoordinate, yCoordinate, ct);


} // end function ct (Equation 49)


int main(){
	// Variable Initializations 
	/*---------------------------*/
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
	/*---------------------------*/
	float q0 = 1; 
	float P0 = 1; 
	float By = 1;
	float b1 = (q0 / P0) * By; 
	/*---------------------------*/
	float value;
	/*---------------------------*/

	// Function Calls & Outputs
	/*---------------------------*/
	exactBend( b1,  ct0,  delta,  h,  L,  px0,  py,  rho,  x,  y);


	return 0;
}





