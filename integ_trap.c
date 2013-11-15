/* integ_trap.c */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "function.h"
#include "deriv2.h"

inline double integ_trap (double *param, int dimension, int functiontype, double *errorinteg, int conv, double extr_a, double extr_b) {

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Variables Definition And Number Of Intervals Input
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	double funz_extr_a; // Immagine Estremo A
	double funz_extr_b; // Immagine Estremo B
	double integ; // Result
	int i; // For Loop Variable
	long int n; // Number Of Intervals
	double base; // dx Of Every Interval

// Input Number Of Intervals
	fprintf (stdout, "Input The Number Of Intervals : ");
	scanf ("%li",&n);

// Array Of Points
	double X[n]; // Array dx [base] Of Every Rectangle
	double Y[n]; // Array f(x) [height] Of Every Rectangle

	base = (extr_b - extr_a)/n;

	funz_extr_a = function (param,dimension,functiontype,extr_a);
	funz_extr_b = function (param,dimension,functiontype,extr_b);






//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Integral Calculation
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// First Point Definition

	if (extr_b > extr_a) { X[0] = extr_a; }

	if (extr_b < extr_a) { X[0] = extr_b; }

	Y[0] = function (param,dimension,functiontype,X[0]);

	integ = base*(((funz_extr_b - funz_extr_a)/2) + Y[0]);

// Successive Points
	for (i=1; i<n; i++) {

		X[i] = X[i-1] + base;
		Y[i] = function (param,dimension,functiontype,X[i]);

		integ += base * Y[i];

		fprintf (stdout, " [*] %i : Integ = %lf\n", i, integ);

	}









//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Error Calculation
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	if ( conv >= 8) {

		int diff;
		diff = (int) (abs(extr_b - extr_a))*1000;

		double x[diff]; // Discretized Points Array
		double dd[diff]; // Second Derivate Images Array
		double M; // Maximum

		if ( extr_a > extr_b ) { x[0] = extr_a; }
		if ( extr_b > extr_a ) { x[0] = extr_b; }

		dd[0] = deriv2 (param,dimension,functiontype,X[0]);

		M = dd[0];

		for (i=1; i <=diff; i++) {

			x[i] = x[i-1] + 0.001;
			dd[i] = deriv2 (param,dimension,functiontype,x[i]);

			if ( dd[i] > M ) { M = dd[i]; }

		}

		*errorinteg = ((pow((extr_b - extr_a),3))*M)/(12*n*n);

	}
	else { *errorinteg = 0; }


// Return Integ
	return integ;

}
