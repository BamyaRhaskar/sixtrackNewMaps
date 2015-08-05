/*  Implementing Exact Bend, Equations 44-49 in SixTrack Physics Manual (Revised version)
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "complex.h"

float alpha( float s, float delta, float theta){

	float alpha = arcsin( xMomenta(s, delta) / sqrt((1 + delta*delta) - pow(yMomenta(x, delta),2) ));

} // end of function alpha

float zMomenta( float s , float delta, float theta){

	float pz = sqrt( (1 + delta)*(1 + delta) - pow(xMomenta(s, delta), 2) - pow(yMomenta(s, delta), 2) );

} // end of function zMomenta

float xMomenta ( float s, float delta, float theta){

	float px = px*cos(theta) + (zMomenta(0, delta, theta))

} // end of function xMomenta

float yMomenta ( float s, float delta, float theta){


} // end of function yMomenta


int main(){

	return 0;
}
