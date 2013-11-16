/* deriv4.c */

#include <stdio.h>
#include <math.h>

#define  e = 2.7182818284

inline double deriv4 (double *param, int dimension, int functiontype, double x) {

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Variables Definition
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	int i; // For Loop Variables
	double fourth_derivate = 0; // Result


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

			int len3 = ( dimension - 3 ); // Third Derivative Coefficient Array's Lenght
			double DDD[len3]; // Third Derivative Array

			int len4 = ( dimension - 4 ); // Fourth Derivative Coefficient Array's Lenght
			double DDDD[len4]; // Fourth Derivative Array

			// D(a*x^n)=a*n*x^(n-1)
			for (i=0; i<=len1; i++) { D[i] = param[i+1]*(i+1); }

			// DD(a*x^n)=a*n*x^(n-1)
			for (i=0; i<=len2; i++) { DD[i] = D[i+1]*(i+1); }

			// DDD(a*x^n)=a*n*(n-1)*x^(n-2)
			for (i=0; i<=len2; i++) { DDD[i] = DD[i+1]*(i+1); }

			// DDDD(a*x^n)=a*n*(n-1)*(n-2)*x^(n-3)
			for (i=0; i<=len2; i++) { DDDD[i] = DDD[i+1]*(i+1); }

			// Fourth Derivative Calculation
			for (i=0; i<=len2; i++) { fourth_derivate += DDDD[i]*(pow(x,i)); }

			break;

		}

		case 2: { // a*e^x + b*x^n =====> a*e^x + b*n*x^(n-1) =====> a*e^x + b*n*(n-1)*x^(n-2)
				  // =====> a*e^x + b*n*(n-1)*(n-2)*x^(n-3) =====> a*e^x + b*n*(n-1)*(n-2)*(n-3)*x^(n-4)

			double a = param[0];
			double b = param[1];
			double n = param[2];

			fourth_derivate = a*(pow(e,x)) + b*n*(n-1)*(n-2)*(n-3)*(pow(x,(n-4)));

			break;

		}

		case 3: { // A*sin(m*x+t) + B*cos(n*x+p) =====> A*cos(m*x+t)*m - B*sin(n*x+p)*n  =====> - A*m*m*sin(m*x+t) - B*n*n*cos(n*x+t)
				  // =====> - A*m*m*m*cos(m*x+t) + B*n*n*n*sin(n*x+t) =====> A*m*m*m*m*sin(m*x+t) + B*n*n*n*n*cos(n*x+t)

			double A = param[0];
			double m = param[1];
			double t = param[2];
			double B = param[3];
			double n = param[4];
			double p = param[5];

			fourth_derivate = A*m*m*m*m*sin(m*x+t) + B*n*n*n*n*cos(n*x+t);

			break;

		}

	}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Return
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	return fourth_derivate;

}



