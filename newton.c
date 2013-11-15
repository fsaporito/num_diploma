/* newton.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <math.h>
#include "function.h"
#include "deriv1.h"

inline double newton (double *param, int dimension, int functiontype, double precision, double *error, long int *inter, double extr_a, double extr_b, int mode) {

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Variables Definition & Input Number Of Iterations
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	int interations; // Number Of Interations
	int i; // For Loop Variables
	double root; // Result

	system("clear");
	fprintf (stdout, "Input The Requested Number Of Iterations : ");
	scanf ("%i", &interations);

	double X[interations]; // X-values Array
	double funz[interations]; // Images Array
	double der[interations]; // Derivate Arrays



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	system("clear");
	fprintf (stdout, "Calculating ...\n");


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Root Calculating
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	switch (mode) {

		case 1: { // f(a)*DDf(x) > 0

			X[0]=extr_b; // Seed Definition

			funz[0] = function (param,dimension,functiontype,X[0]); // Seed's Image
			der[0] = deriv1 (param,dimension,functiontype,X[0]); // Seed's Derivative

			for (i=1; i<=interations; i++) {
				fprintf (stdout, "%i / %i", i, interations);
				funz[i] = function (param,dimension,functiontype,X[i]); // Image Of The Succession's Point
				der[i] = deriv1 (param,dimension,functiontype,X[i]);  // Derivate Of The Succession's Point
				X[i]=X[0]-(funz[i-1]/der[i-1]);  // Calculation Of The Next Point
			}

			root = X[interations];

			break;

		}

		case 2: { // f(a)*DDf(x) > 0

			X[0]=extr_a; // Seed Definition

			funz[0] = function (param,dimension,functiontype,X[0]); // Seed's Image
			der[0] = deriv1 (param,dimension,functiontype,X[0]); // Seed's Derivative

			for (i=1; i<=interations; i++) {
				fprintf (stdout, "%i / %i", i, interations);
				funz[i] = function (param,dimension,functiontype,X[i]);  // Image Of The Succession's Point
				der[i] = deriv1 (param,dimension,functiontype,X[i]);  // Derivate Of The Succession's Point
				X[i]=X[0] - (funz[i-1]/der[i-1]);  // Calculation Of The Next Point
			}

			root = X[interations];

			break;

		}

	}

	return root;

}
