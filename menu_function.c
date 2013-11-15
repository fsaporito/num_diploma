/* menu_function.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

inline int menu_function (void) {

	// Variables
	int choice; // Menu ---> Choice
	int poly = 1; // Menu ---> Polynomial
	int exp = 2; // Menu ---> Exponential
	int sincos = 3; // Menu ---> Trigonometric
	int exit = 4; // Menu ---> Exit

	do {
	
		// Clear Screen
		system("clear");

		// Menu

		fprintf (stdout, "Select The Type Of FUnction : \n\n");

		fprintf (stdout, "1) Polynomial \n");

		fprintf (stdout, "2) a*e^x + b*x^n \n");

		fprintf (stdout, "3) A*sin(lx+t) + B*cos(mx+p) \n");

		fprintf (stdout, "4) Exit \n\n");

		fprintf (stdout, "Choice : ");
		scanf ("%i", &choice_function);

	} while (choice != poly && choice != exp && choice != sincos && choice != exit);

	return choice;

}

