/* convergence.c */

// Return 1 ---> Same Sign Extrema
// Return 2 ---> Different Sign Extrema | Not Continuous Function 
// Return 3 ---> Different Sign Extrema | Continuous Funcion | Not Derivable Function
// Return 4 ---> Different Sign Extrema | Continuous Funcion | Derivable Function | Not Monotone Function
// Return 5 ---> Different Sign Extrema | Continuous Funcion | Derivable Function | Monotone Function | Not Continuous Derivate
// Return 6 ---> Different Sign Extrema | Continuous Funcion | Derivable Function | Monotone Function | Continuous Derivate | Not Monotone Derivate
// Return 7 ---> Different Sign Extrema | Continuous Funcion | Derivable Function | Monotone Function | Continuous Derivate | Monotone Derivate | Not Continuous Second Derivate
// Return 8 ---> Different Sign Extrema | Continuous Funcion | Derivable Function | Monotone Function | Continuous Derivate | Monotone Derivate | Continuous Second Derivate | Not Continuous Fourth Derivate
// Return 9 ---> Different Sign Extrema | Continuous Funcion | Derivable Function | Monotone Function | Continuous Derivate | Monotone Derivate | Continuous Second Derivate | Continuous Fourth Derivate

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h> // Sleep
#include <math.h>
#include "function.h"
#include "deriv1.h"
#include "deriv2.h"
#include "deriv4.h"

inline int convergence (double *param, int dimension, int functiontype, double extr_a, double extr_b) {




//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Variables Definition
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////


double funz_extr_a; // F(extr_a)
double funz_extr_b; // F(extr_b)
int i; // For Loop Variables
double h=0.00000001; // Infinitesimal Quantity
double DIFF; // Difference Between Min And Max
int diff; // Integer Part Of DIFF
double k; // Temporany Values For The Maximum

system("clear");






//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Images Of The Extremous Points Discord
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	fprintf (stdout, "[*] Discord Images Of The Extremous Points");

	funz_extr_a = function (param, dimension, functiontype, extr_a); // F(extr_a)
	funz_extr_b = function (param, dimension, functiontype, extr_b); // F(extrb)

	if ( (funz_extr_a*funz_extr_b) > 0. ) {
		
		fprintf (stdout, " \n");
		fprintf (stderr, "error: The Images Of The Extremous Points Should Be Discord !!!\n");
		
		sleep(3);
		
		return 1;
		
	}
		
	if ( (funz_extr_a*funz_extr_b) < 0. ) { 
	
		fprintf (stdout, "   OK \n"); 
		
	}





//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Interval's Points Calculation
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	DIFF = 1000*(abs(extr_b - extr_a));
	diff = (int) DIFF;
	
	double punti[diff]; // Interval's Points Array
	punti[0] = extr_a + 0.001; // First Interval Point
	k = 1000*(extr_b - 0.001); // Last Interval Point
	
	double neighborhood_dx[diff]; // Right Neighborhood Destro Di X(i)
	neighborhood_dx[0] = punti[0] + h; // First + h For Right Limit

	double neighborhood_sx[diff] ; // Left Neighborhood Di X(i)
	neighborhood_sx[0] = punti[0] - h; // First - h For Left Limit

	for (i=1; i<k; i++) {
		punti[i] = punti[i-1] + 0.001; // Point Of The Interval
		neighborhood_dx[i] = punti[i] + h; // Point + h For Right Limit
		neighborhood_sx[i] = punti[i] - h; // Point - h For Left Limit
	}






//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Continuous Funcion
// lim_dx_f(p) = lim_sx_f(p) = f(p)
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	fprintf (stdout, "[*] Function Continuous? ");

	double lim_dx[diff]; // Right Limit Array
	double lim_sx[diff]; // Left Limit Array
	double Funz[diff]; // Images Array

	for (i=1; i<k; i++) {

		lim_dx[i] = function (param,dimension,functiontype,neighborhood_dx[i]); // Right Limit In X(i)
		lim_sx[i] = function (param,dimension,functiontype,neighborhood_sx[i]); // Left Limit In X(i)
		Funz[i] = function (param,dimension,functiontype,punti[i]); // Image Of X(i)

		if ( abs(lim_dx[i] - lim_sx[i]) > (h*10000)  || abs(lim_dx[i] - Funz[i]) > h*10000 ) {
			fprintf (stdout, " \n");
			fprintf (stderr, "error: Function Not Continuous In The Interval !!!\n");
			sleep(3);
			return 2;
		}

	}
	
	fprintf (stdout, "   OK \n");






//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Derivable Function
// * f(x) Continuous
// * f(x) Derivable In Every Point Of (a;b) ---> D+f(c)==D-f(c) For Every c Belonging To (a;b)
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	fprintf (stdout, "[*] Derivable? ");

	double Der_dx[diff]; // Right First Derivate Array
	double Der_sx[diff]; // Left First Derivate Array

	for (i=1; i<k; i++) {

		Der_dx[i] = deriv1 (param, dimension, functiontype, neighborhood_dx[i]); // Right First Derivate In X(i)
		Der_sx[i] = deriv1 (param, dimension, functiontype, neighborhood_sx[i]); // Left First Derivate In X(i)

		if ( abs(Der_dx[i] - Der_sx[i]) > (h*1000) ) {
			fprintf (stdout, " \n");
			fprintf (stderr, "error: Function Not Derivable In The Interval !!!\n");
			sleep(3);
			return 3;
		}

	}
	
	fprintf (stdout, "   OK \n");






//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Monotone Function [Df(x) Constant Sign]
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	fprintf (stdout, "[*] Function Monotone? ");

	double Der[diff]; // First Derivative Array
	Der[0] = deriv1 (param,dimension,functiontype,punti[0]); // First Derivate For The FIrst Point

	for (i=1; i<k; i++) {

		Der[i] = deriv1 (param,dimension,functiontype,punti[i]); // First Derivate For Every Point

		if ( (Der[i]*Der[0]) < 0. ) {
			fprintf (stdout, " \n");
			fprintf (stderr, "error: Function Not Monotone In The Interval !!!\n");
			sleep(3);
			return 4;
		}

	}

	fprintf (stdout, "   OK \n");
	
	



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// First Derivate Continuous
// lim_dx_Df(p) = lim_sx_Df(p) = Df(p)
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	fprintf (stdout, "[*] First Derivate Continuous? ");

	double lim_dx_D[diff]; // Right Limit First Derivative Array
	double lim_sx_D[diff]; // Left Limit Second Derivative Array

	for (i=1; i<k; i++) {

		lim_dx_D[i] = deriv1 (param,dimension,functiontype,neighborhood_dx[i]); // Right Limit First Derivative In X(i)
		lim_sx_D[i] = deriv1 (param,dimension,functiontype,neighborhood_sx[i]); // Left Limit First Derivative In X(i)

		if ( abs(lim_dx_D[i] - lim_sx_D[i]) > h*1000 || abs(lim_dx_D[i] - Der[i]) > h*1000	) {
			fprintf (stdout, " \n");
			fprintf (stderr, "error: First Derivate Not Continuous In The Interval !!!\n");
			sleep(3);
			return 5;
		}

	}
	
	fprintf (stdout, "   OK \n");
	





//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// First Derivate Monotone [DDf(x) < 0 V DDf(x) > 0 for every X]
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	fprintf (stdout, "[*] First Derivate Monotone? ");

	int diffder=diff-2; // Second Derivate's Coefficient's Array's Length
	double DerDer[diffder]; // Second Derivate Array
	DerDer[0] = deriv2 (param,dimension,functiontype,Der[0]); // First Point Second Derivate

	for (i=1; i<k; i++) {

		DerDer[i] = deriv2 (param,dimension,functiontype,Der[i]); // Second Derivate Calculation For Every Point

		if ( (DerDer[i]*DerDer[0]) < 0. ) {
			fprintf (stdout, " \n");
			fprintf (stderr, "error: Second Derivate's Sign Not Continuous In The Interval !!!\n");
			sleep(3);
			return 6;
		}

	}

	fprintf (stdout, "   OK \n");





//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Continuous Second Derivate
// lim_dx_DDf(p) = lim_sx_DDf(p) = DDf(p)
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	if ( functiontype == 1 && dimension < 2 ) { // First Degree Polynomial

		return 7;

	}

	fprintf (stdout, "[*] Second Derivate Continuous? ");

	double lim_dx_DD[diff]; // Right Limit Second Derivative Array
	double lim_sx_DD[diff]; // Left Limit Second Derivative Array

	for (i=1; i<k; i++) {

		lim_dx_DD[i] = deriv2 (param,dimension,functiontype,neighborhood_dx[i]); // Right Limit Second Derivative In X(i)
		lim_sx_DD[i] = deriv2 (param,dimension,functiontype,neighborhood_sx[i]); // Left Limit Second Derivative In X(i)

		if ( abs(lim_dx_DD[i] - lim_sx_DD[i]) > h*1000 || abs(lim_dx_DD[i] - DerDer[i]) > h*1000	) {
			fprintf (stdout, " \n");
			fprintf (stderr, "error: Second Derivate Not Continuous In The Interval !!!\n");
			sleep(3);
			return 7;
		}

	}
	
	fprintf (stdout, "   OK \n");
	
	
	
	
	

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Continuous Fourth Derivate
// lim_dx_DDDDf(p) = lim_sx_DDDDf(p) = DDDDf(p)
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	if ( functiontype == 1 && dimension < 4 ) { return 8; }

	fprintf (stdout, "[*] Fourth Continuous Derivate? ");

	double lim_dx_D_q[diff]; // Right Limit Fourth Derivative Array
	double lim_sx_D_q[diff]; // Left Limit Fourth Derivative Array
	double Der_q[diff]; // Fourth Derivate Array

	for (i=1; i<k; i++) {

		lim_dx_D_q[i] = deriv4 (param,dimension,functiontype,neighborhood_dx[i]); // Right Limit Fourth Derivative In X(i)
		lim_sx_D_q[i] = deriv4 (param,dimension,functiontype,neighborhood_sx[i]); // Left Limit Fourth Derivative In X(i)
		Der_q[i] = deriv4 (param,dimension,functiontype,neighborhood_sx[i]); // Fourth Derivate In X(i)

		if ( abs(lim_dx_D_q[i] - lim_sx_D_q[i]) > h*1000 || abs(lim_dx_D_q[i] - Der_q[i]) > h*1000	) {
			fprintf (stdout, " \n");
			fprintf (stderr, "error: Fourth Derivate Not Continuous In The Interval !!!\n");
			sleep(3);
			return 8;
		}

	}
	
	fprintf (stdout, "   OK \n");

	return 9;

}
