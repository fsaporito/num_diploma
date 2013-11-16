/* deriv1.c */

#include <stdio.h>
#include <math.h>

#define  e = 2.7182818284

inline double deriv1 (double *param, int dimension, int functiontype, double x) {


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Variables Definition
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	int i; // For Loop Variables
	double first_derivate = 0; // Result


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Image Calculation
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	switch (functiontype) {

		case 1: { // Polynomial

			int len = ( dimension - 1 ); // First Derivative Coefficient Array's Lenght
			double D[len]; // First Derivative Array

			// D(a*x^n)=a*n*x^(n-1)
			for (i=0; i<=len; i++) {

                D[i] = param[i+1]*(i+1);

			}

			// First Derivate Calculation
			for (i=0; i<=len; i++) {

                first_derivate += D[i]*(pow(x,i));

            }


			break;

		}

		case 2: { // a*e^x + b*x^n  =====> a*e^x + b*n*x^(n-1)

			double a = param[0];
			double b = param[1];
			double n = param[2];

			first_derivate = (a*(pow (e, x)) + b*n*(pow ( x, (n-1) ) );

			break;

		}

		case 3: { // A*sin(mx+t) + B*cos(nx+p) =====> A*m*cos(mx+t) - B*n*sin(nx+p)

			double A = param[0];
			double m = param[1];
			double t = param[2];
			double B = param[3];
			double n = param[4];
			double p = param[5];

			first_derivate = A*m*(cos(n*x+p)) - B*n*(sin(m*x+t));

			break;

		}

	}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Return
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	return first_derivate;

}
