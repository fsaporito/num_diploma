/* cords.c */

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <math.h>

#include "../Functions/function.h"

inline double cords (double *param, int dimension, int functiontype, double precision, double *error, long int *inter, double extr_a, double extr_b, int mode) {

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Variables Definition
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	double funz_extr_a; // F(a)
	double funz_extr_b; // F(b)
	int i; // For Loop Variables
	double X_intersec; // Intersection  Between The Function And The X Axis
	double Y_intersec; // Image Of The Intersection
	double root; // Result



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	system ("clear");
	fprintf (stdout, "Calculating ...\n");

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Non Recursive Calculation Of The Root
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	if ( mode == 3) { // Non Constant Concavity
		do {

			funz_extr_a = function (param,dimension,functiontype,extr_a); // F(extr_a)
			funz_extr_b = function (param,dimension,functiontype,extr_b); // F(extr_b)

			// Intersection Between The Line Between The Two Points And The X Axis
			X_intersec=((extr_a*(funz_extr_b - funz_extr_a) - extr_b*(extr_b - funz_extr_a))/(funz_extr_b - funz_extr_a));
			Y_intersec = function (param,dimension,functiontype,X_intersec); // Image Of The Intersection

			if ( (funz_extr_a*Y_intersec) > 0 ) { extr_a = X_intersec; } // Substitution Of extr_a With THe New Point
			if ( (funz_extr_b*Y_intersec) > 0 ) { extr_b = X_intersec; } // Substitution Of extr_b With THe New Point

		} while ( abs(Y_intersec) > precision );

		root = X_intersec;

	}


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Recursive Calculation Of The Root
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	if ( mode != 3) {

		int interations; // Number Of Interations

		system("clear");
		fprintf (stdout, "Inserisci Il Numero Di Interazioni Richiesto : ");
		scanf ("%i",&interations);

		double X[interations]; // X-values Array
		double funz[interations]; // Images Array

		// f(a)*DDf(x) > 0
		if ( mode == 1. ) {

			X[0]=extr_b; // Seed Definition

			funz[0] = function (param,dimension,functiontype,X[0]); // Seed's Image
			funz_extr_a = function (param,dimension,functiontype,extr_a);  // F(extr_a)

			for (i=1; i<=interations; i++) {
				fprintf (stdout, "%i / %i", i, interations);
				funz[i ]= function (param,dimension,functiontype,X[i]);  // Image Of The Succession's Point
				X[i]=X[i-1]-(extr_a-X[i-1])*funz[i-1]/(funz_extr_a - funz[i]);   // Calculation Of The Next Point
			}

			root = X[interations];

		}

		// f(a)*DDf(x) < 0
		if ( mode == 2. ) {

			X[0]=extr_a; // Seed Definition

			funz[0] = function (param,dimension,functiontype,X[0]); // Seed Image
			funz_extr_b = function (param,dimension,functiontype,extr_b); // F(extr_b)

			for (i=1; i<=interations; i++) {
				fprintf (stdout, "%i / %i", i, interations);
				funz[i] = function (param,dimension,functiontype,X[i]);  // Image Of The Succession's Point
				X[i]=X[i-1]-(extr_b-X[i-1])*funz[i-1]/(funz_extr_b - funz[i]);   // Calculation Of The Next Point
			}

			root = X[interations];;

		}

	}

	return root;

}
