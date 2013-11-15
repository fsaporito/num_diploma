/* integ_rect.c */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "function.h"

inline void integ_rect(double *param, int dimension, int functiontype, double *integ_first,double *integ_second, double *errorinteg, int conv, double extr_a, double extr_b) {

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Variables Definition And Number Of Intervals Input
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	int i; // For Loop Variable
	long int n; // Number Of Intervals
	double base; // dx Of Every Interval

// Input Number Of Intervals
	fprintf (stdout, "Input The Number Of Intervals : ");
	scanf ("%li", &n);

// Array Of Points
	double X[n]; // Array dx [base] Of Every Rectangle
	double Y[n]; // Array f(x) [height] Of Every Rectangle

	base = (extr_b - extr_a)/n;





//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Integral Calculation
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// First Point Definition

	if (extr_b > extr_a) { X[0] = extr_a; }

	if (extr_b < extr_a) { X[0] = extr_b; }

	Y[0] = function (param, dimension, functiontype,X[0]);

	*integ_first = base*(Y[0]);
	*integ_second = 0;

// I
	for (i=1; i<=n; i++) {

		X[i] = X[i-1] + base;
		Y[i] = function (param, dimension, functiontype, X[i]);

		if ( i != n) { *integ_first += base*Y[i]; }

		*integ_second += base*Y[i];

		fprintf (stdout, " [*] %i : integ_first = %lf\n", i, *integ_first);
		fprintf (stdout, "          integ_second = %lf\n", *integ_second);

	}



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Error Calculation
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	if ( conv >= 5) {

		int diff;
		diff = (int) (abs(extr_b - extr_a))*10000;

		double x[diff]; // Discretized Points Array
		double y[diff]; // Images Array
		double M; // Maximum

		if ( extr_a > extr_b ) { x[0] = extr_a; }
		if ( extr_b > extr_a ) { x[0] = extr_b; }

		y[0] = function (param, dimension, functiontype, x[0]);

		M = y[0];

		for (i=1; i <=diff; i++) {

			x[i] = x[i-1] + 0.0001;
			y[i] = function (param, dimension, functiontype, x[i]);

			if ( y[i] > M ) { M = y[i]; }

		}

		*errorinteg = ((pow((extr_b - extr_a),2))*M)/(2*n);

	}
	else { *errorinteg = (integ_second - integ_first)/2; }
}
