/* dicotomic.c */

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <math.h>

#include "../Functions/function.h"

inline double dicotomic (double *param, int dimension, int functiontype, double precision, double *error, long int *inter, double extr_a, double extr_b) {

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Variables Definition
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	double funz_extr_a; // F(extr_a)
	double funz_extr_b; // F(extr_b)
	double m; // Medium Point Beetwen extr_a And extr_b
	double funz_m; // F(m)


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Root Calculation
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	system("clear");
	fprintf (stdout, "[*] Calculating ...\n");

	funz_extr_a = function (param, dimension, functiontype, extr_a); // F(a)
	funz_extr_b = function (param, dimension, functiontype, extr_b); // F(b)

	do {

		inter++;

		m = (extr_a + extr_b)/2; // X-value Of Medium Point
		funz_m = function (param,dimension,functiontype,m); // F(m)

		if( funz_m == 0. ) { *error=0.; break; }

		if( funz_extr_a*funz_m < 0. ) { extr_b = m; funz_extr_b = funz_m; }
		if( funz_extr_b*funz_m < 0. ) { extr_a = m; funz_extr_a = funz_m; }

		*error = abs( (extr_b-extr_a)/2 );

	} while ( *error > precision );

	return m;

}
