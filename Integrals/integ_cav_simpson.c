/* integ_cav_simpson.c */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../Functions/function.h"
#include "../Functions/deriv4.h"

inline double integ_cav_simpson (double *param, int dimension, int functiontype, double *errorinteg, int conv, double extr_a, double extr_b) {

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Variables Definition And Number Of Intervals Input
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	double integ; // Result
	int i; // For Loop Variable
	long int n; // Number Of Intervals
	double base; // dx Of Every Interval
	double odd_sum; // Summation Of Values With Odd Index
	double even_sum; // Summation Of Values With Even Index


// Input Number Of Intervals
	fprintf (stdout, "Input The Number Of Intervals : ");
	scanf ("%li",&n);

// Array Of Points
	double X[2*n]; // Array dx [base] Of Every Rectangle
	double Y[2*n]; // Array f(x) [height] Of Every Rectangle

	base = abs((extr_b - extr_a))/(2*n);





//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Integral Calculation
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// First Point Definition

	if (extr_b > extr_a) { X[0] = extr_a; }

	if (extr_b < extr_a) { X[0] = extr_b; }

	Y[0] = function (param,dimension,functiontype,X[0]);

// Points And Images Calculation
	for (i=1; i<=(2*n); i++) { X[i] = X[i-1] + base; Y[i] = X[i]*X[i]*X[i]; }

// Points'Images Calculation

	odd_sum = 0;

	for (i=1; i<=(2*n-1); i+=2) { odd_sum += Y[i]; }

	even_sum = 0;

	for (i=2; i<=(2*n-2); i+=2) { even_sum += Y[i]; }


	integ = (2*base/6)*(Y[0] + Y[2*n] + 2*odd_sum + 4*even_sum);





//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Error Calculation
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	if ( conv == 9 ) {

		int diff;
		diff =(int) (abs(extr_b - extr_a))*1000;

		double x[diff]; // Discretized Points Array
		double d_q[diff]; // Fourth Derivate Image'Points Array
		double M; // Maximum

		if ( extr_a > extr_b ) { x[0] = extr_a; }
		if ( extr_b > extr_a ) { x[0] = extr_b; }

		d_q[0] = deriv4 (param,dimension,functiontype,x[0]);

		M = d_q[0];

		for (i=1; i <=diff; i++) {

			x[i] = x[i-1] + 0.001;
			d_q[i] = deriv4 (param,dimension,functiontype,x[i]);

			if ( d_q[i] > M ) { M = d_q[i]; }

		}

		*errorinteg = (pow((extr_b - extr_a),5)*M)/(2880*(pow(n,4)));

	}
	else { *errorinteg = 0; }


// Return Integ
	return integ;

}
