/* menu_root.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

inline int menu_root(int mode, int conv) {

	// Variables
	int choice; // Menu ---> Choice
	int dico = 1; // Menu ---> Dicotomic
	int cords = 2; // Menu ---> Cords
	int newt = 3; // Menu ---> Newton
	int exit = 4; // Menu ---> Exit

	
	do {
	
		// Clear Screen
		system("clear");

		// Menu
	
		fprintf (stdout, "Select The Method To Use : \n\n");

		fprintf (stdout, "1) Dicotomic\n");

		fprintf (stdout, "2) Cords");
		if ( mode != 3 ) { fprintf (stdout, "  [ Recursive ]"); }
		if ( conv < 5 ) { fprintf (stdout, "  [ NO !!! First Derivate Not Continuous ]"); }
		fprintf (stdout, " \n");

		fprintf (stdout, "3) Newton  [ Recursive ]");
		if ( conv < 7 ) { fprintf (stdout, "  [ NO !!! First Derivative Not Monotone ]"); }
		fprintf (stdout, " \n");

		fprintf (stdout, "4) Exit\n\n");

		fprintf (stdout, "Choice : ");
		scanf ("%i",&choice);

	} while (choice != dico && choice != cords && choice != newt && choice != exit);	
	
	return choice;


		
}

