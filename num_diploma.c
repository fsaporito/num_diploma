/*  num_diploma.c   */

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // pow | sin | cos
#include <unistd.h> // Sleep
#include <sys/types.h>

#include "./Functions/function.h" // Function Value
#include "./Functions/deriv1.h" // Deriv 1 Value
#include "./Functions/deriv2.h" // Deriv 2 Value
#include "./Functions/deriv4.h" // Deriv 4 Value

#include "./Functions/convergence.h" // Convergence Function

#include "./Menus/menu_function.h" // Menu Function Type
#include "./Menus/menu_root.h" // Menu root Algorithm
#include "./Menus/menu_integ.h" // Menu Integral Algorithm

#include "./Roots/dicotomic.h" // Dicotomic Method For Root Finding
#include "./Roots/cords.h" //Cords Method For Root Finding
#include "./Roots/newton.h" // Newton Method For Root Finding

#include "./Integrals/integ_rect.h" // Rectangles Method To Calculate Definite Integrals
#include "./Integrals/integ_trap.h" // Trapezis Method To Calculate Definite Integrals
#include "./Integrals/integ_cav_simpson.h" // Cavalieri Simpson Method To Calculate Definite Integrals


#define MAX_PAR 100

int main(int argc, char *argv[]) {



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Variables Definitions
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////



	double extr_a; // FIrst Extreme
	double extr_b; // Second Extreme
	double funz_extr_a; // F(extr_a)
	double funz_extr_b; // F(extr_b)

	int choice; // Choice Variable
	int functiontype; // Function Type [Polynomial | Exponential | Trigonometric]

	int dimension; // Coefficients Number
	double param[MAX_PAR]; // Coefficients Array
	int conv = 0; // Convergence Value
	int mode; // Recursivity Enambled Or Not

	double precision; // Required Precision In The Calculation
	double error; // Root Error Generated During Calculation

	double errorinteg; // Integral Error Generated During Calculation
	long int inter; // Number Of Iterations Required

	double root; // Root Of The Function
	double integ; // Definite Integral Of The Function




//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Function Type Choice
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////


	choice = menu_function ();
	functiontype = choice;

	switch (choice) {

		case 1 : { // Polynomial

			int i; // For Loops Variable

			do {

				system("clear");
				fprintf (stdout, "[*] Polynomial :\n");
				fprintf (stdout, "Input The Polynomial's Degree : ");
				scanf ("%i", &dimension);
				if (dimension<=0) { fprintf (stderr, "error: Degree Has To Be More Than Zero !!!\n\n"); sleep(3);}

			} while ( dimension <= 0 );

			fprintf (stdout, " \n");
			fprintf (stdout, "Input The Coefficients, Beginning From The Constant Term : \n");

			for (i=0; i<=dimension; i++) {

				fprintf (stdout, "Coefficient[%i] = ", i);
				scanf ("%lf", &param[i]);
				fprintf (stdout, "\n");

			}

			break;

		}

		case 2 : { // a*e^x + b*x^n

			dimension = 3;

			system ("clear");

			fprintf (stdout, "[*] a*e^x + b*x^n :\n");

			fprintf (stdout, "a = ");
			scanf ("%lf", &param[0]);
			fprintf (stdout, "\n");

			fprintf (stdout, "b = ");
			scanf ("%lf", &param[1]);
			fprintf (stdout, "\n");

			fprintf (stdout, "n =  ");
			scanf ("%lf", &param[2]);
			fprintf (stdout, "\n");

			break;

		}

		case 3 : {  // A*sin(lx+t) + B*cos(mx+p)

			dimension = 6;

			system ("clear");

			fprintf (stdout, "[*] A*sin(lx+t) + B*cos(mx+p) :\n");

			fprintf (stdout, "A = ");
			scanf ("%lf", &param[0]);
			fprintf (stdout, "\n");

			fprintf (stdout, "l = ");
			scanf ("%lf", &param[1]);
			fprintf (stdout, "\n");

			fprintf (stdout, "t = ");
			scanf ("%lf", &param[2]);
			fprintf (stdout, "\n");

			fprintf (stdout, "B = ");
			scanf ("%lf", &param[3]);
			fprintf (stdout, "\n");

			fprintf (stdout, "m = ");
			scanf ("%lf", &param[4]);
			fprintf (stdout, "\n");

			fprintf (stdout, "p = ");
			scanf ("%lf", &param[5]);
			fprintf (stdout, "\n");

			break;

		}

		case 4 : { exit (0); }


	}








//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Input Of Extrema And Convergence Check
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////


	while (conv < 2) {

		system("clear");

		fprintf (stdout, " \n");
		fprintf (stdout, "Input The First Extremous : ");
		scanf ("%lf", &extr_a);

		funz_extr_a = function (param, dimension, functiontype, extr_a);

		if ( funz_extr_a == 0 ) {

			fprintf (stdout, "The Value Is Already The Root !!!\n");

			root = extr_a;

			sleep(3);

			system("clear");

			fprintf (stdout, "Function's Root : %lf\n", root);

			return 0;

		}

		system("clear");

		fprintf (stdout, " \n");
		fprintf (stdout, "Input The Second Extremous : ");
		scanf ("%lf", &extr_b);

		funz_extr_b = function (param, dimension, functiontype, extr_b);

		if ( funz_extr_b == 0 ) {

			fprintf (stdout, "The Value Is Already The Root !!!\n");

			root = extr_b;

			sleep(3);

			system("clear");

			fprintf (stdout, "Function's Root : %lf\n", root);

			return 0;
		}


		conv = convergence (param, dimension, functiontype, extr_a, extr_b);

		// Check Recurrence Possibility
		if (conv == 7 ) {

			double der_der_extr_a = deriv2 (param, dimension, functiontype, extr_a);

			if ( funz_extr_a*der_der_extr_a > 0 ) {

				mode = 1;

			}

			if ( funz_extr_a*der_der_extr_a < 0 ) {

				mode = 2;

			}

		} else {

			mode = 3;

		}

		fprintf (stderr, "Conv = %i", conv);

	}






//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Precision
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////


	do {

		system ("clear");

		fprintf (stdout, "Input The Precision Value (>0) : ");
		scanf ("%lf", &precision);

		if (precision <= 0) {

			fprintf (stderr, "error: Precision <= 0 !!!\n\n");

			sleep(3);

		}

	} while (precision <= 0);






//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Root Finding
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////


	choice = menu_root (mode,conv);

	switch (choice) {

		case 1 : { // Dicotomic

			root = dicotomic (param, dimension, functiontype, precision, &error, &inter, extr_a, extr_b);

			system ("clear");

			fprintf (stdout, "Function's Root [interaction = %li ] : %lf", inter, root);

			if ( error == 0 ) { fprintf (stdout, " ± %lf\n", error); }
			else { fprintf (stdout, "\n"); }

			sleep(3);

			break;

		}


		case 2 : { // Cords

			root = cords (param, dimension, functiontype, precision, &error, &inter, extr_a, extr_b, mode);

			system ("clear");

			fprintf (stdout, "Function's Root [interaction = %li ] : %lf", inter, root);

			if ( error == 0. ) { fprintf (stdout, " ± %lf\n", error); }
			else { fprintf (stdout, "\n"); }

			sleep(3);

			break;

		}


		case 3 : { // Newton

			root = newton (param, dimension, functiontype, precision, &error, &inter, extr_a, extr_b, mode);

			system ("clear");

			fprintf (stdout, "Function's Root [interaction = %li ] : %lf", inter, root);

			if ( error == 0. ) { fprintf (stdout, " ± %lf\n", error); }
			else { fprintf (stdout, "\n"); }

			sleep(3);

			break;

		}


		case 4 : { break; }  // Exit

	}






//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Numerical Integrations
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////


	system ("clear");

	choice = menu_integ (root,error,inter);

	switch (choice) {

		case 1 : { // Rectangles

			double integ_first; // First Integral
			double integ_second; // Second Integral

			integ_rect (param, dimension, functiontype, &integ_first, &integ_second, &errorinteg, conv, extr_a, extr_b);

			system ("clear");

			fprintf (stdout, "Function's Root [interaction = %li ] : %lf", inter, root);

			if ( error == 0. ) { fprintf (stdout, " ± %lf\n", error); }
			else { fprintf (stdout, "\n"); }

			fprintf (stdout, "First Integral [ %lf , %lf ] = %lf", extr_a, extr_b, integ_first);

			if ( errorinteg == 0. ) { fprintf (stdout, " ± %lf\n", errorinteg); }
			else { fprintf (stdout, "\n"); }

			fprintf (stdout, "Second Integral [ %lf , %lf ] = %lf", extr_a, extr_b, integ_second);

			if ( errorinteg == 0. ) { fprintf (stdout, " ± %lf\n", errorinteg); }
			else { fprintf (stdout, "\n"); }

			sleep(3);

			break;

		}


		case 2 : { // Trapezi | Bezout

			integ = integ_trap (param, dimension, functiontype, &errorinteg , conv, extr_a, extr_b);

			system ("clear");

			fprintf (stdout, "Function's Root [interaction = %li ] : %lf", inter, root);

			if ( error == 0. ) { fprintf (stdout, " ± %lf\n", error); }
			else { fprintf (stdout, "\n"); }

			fprintf (stdout, "Integral [ %lf , %lf ] = %lf", extr_a, extr_b, integ);

			if ( errorinteg == 0. ) { fprintf (stdout, " ± %lf\n", errorinteg); }
			else { fprintf (stdout, "\n"); }

			sleep(3);

			break;

		}


		case 3 : { // Cavalieri Simpson

			integ = integ_cav_simpson (param, dimension, functiontype, &errorinteg, conv, extr_a, extr_b);

			system("clear");

			fprintf (stdout, "Function's Root [interaction = %li ] : %lf", inter, root);

			if ( error == 0. ) { fprintf (stdout, " ± %lf\n", error); }
			else { fprintf (stdout, "\n"); }

			fprintf (stdout, "Integral [ %lf , %lf ] = %lf", extr_a, extr_b, integ);

			if ( errorinteg == 0. ) { fprintf (stdout, " ± %lf\n", errorinteg); }
			else { fprintf (stdout, "\n"); }

			sleep(3);

			break;

		}


		case 4 : {  // Exit

			system("clear");

			fprintf (stdout, "Function's Root [interaction = %li ] : %lf",inter, root);

			if ( error == 0. ) { fprintf (stdout, " ± %lf\n", error); }
			else { fprintf (stdout, "\n"); }

			sleep(3);

			break;

		}

	}


	return 0;

}
