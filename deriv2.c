/* deriv2.c */

#include <stdio.h>
#include <math.h>

#define  e = 2.7182818284

inline double deriv2 (double *param, int dimension, int functiontype, double x) {

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Variables Definition
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	int i; // For Loop Variables
	double second_derivate = 0; // Result


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Image Calculation
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	switch (functiontype) {

		case 1: { // Polynomial

			int len1 = ( dimension - 1 ); // First Derivative Coefficient Array's Lenght
			double D[len1]; // First Derivative Array

			int len2 = ( dimension - 2 ); // Second Derivative Coefficient Array's Lenght
			double DD[len2]; // Second Derivative Array

			// D(a*x^n)=a*n*x^(n-1)
			for (i=0; i<=len1; i++) { D[i] = param[i+1]*(i+1); }

			// DD(a*x^n)=a*n*x^(n-1)
			for (i=0; i<=len2; i++) { DD[i] = D[i+1]*(i+1); }

			// Second Derivative Calculation
			for (i=0; i<=len2; i++) { second_derivate += DD[i]*(pow(x,i)); }

			break;

		}

		case 2: { // a*e^x + b*x^n =====> a*e^x + b*n*x^(n-1) =====> a*e^x + b*n*(n-1)*x^(n-2)

			double a = param[0];
			double b = param[1];
			double n = param[2];

			second_derivate = a*(pow(e,x)) + b*n*(n-1)*(pow(x,(n-2)));

			break;

		}

		case 3: { // A*sin(m*x+t) + B*cos(n*x+p) =====> A*cos(m*x+t)*m - B*sin(n*x+p)*n  =====> - A*m*m*sin(m*x+t) - B*n*n*cos(n*x+t)

			double A = param[0];
			double m = param[1];
			double t = param[2];
			double B = param[3];
			double n = param[4];
			double p = param[5];

			second_derivate = - A*m*m*sin(m*x+t) - B*n*n*cos(n*x+t);

			break;

		}

	}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Return
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	return second_derivate;

}

