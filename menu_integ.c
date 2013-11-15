/* menu_integ.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

inline int menu_integ (double root, double error, long int inter) {

	
	// Variabiles
	int choice; // Menu ---> Choice
	int rect = 1; // Menu ---> Rectangles
	int trap = 2; // Menu ---> Trapezis
	int simps = 3; // Menu ---> Cavalieri Simpson (Parabola)
	int exit = 4; // Menu ---> Exit
	
	
	do {
	
		// Clear Screen
		system("clear");

		// Print Zero ± Error
		fprintf (stdout, "Function's Root [interaction = %li ] : %lf", inter, root);
		if ( error == 0. ) { fprintf (stdout, " ± %lf\n", error); }
		else { fprintf (stdout, "\n"); }

		// Menu

		fprintf (stdout, "Select The Method To Use : \n\n");

		fprintf (stdout, "1) Method Of Rectangles\n"); // F Continuous

		fprintf (stdout, "2) Method Of Trapezis\n");

		fprintf (stdout, "3) Cavalieri-Simpson's Method (Parabola)\n");

		fprintf (stdout, "4) Exit\n\n");

		fprintf (stdout, "Choice : ");
		scanf ("%i", &choice);

	} while (choice != rect && choice != trap && choice != simps && choice != exit);
	
	return choice;

}
