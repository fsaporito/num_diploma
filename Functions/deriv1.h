/* deriv1.h */

#include <stdio.h>
#include <math.h>

#define  e 2.7182818284

// *param ---------> array with the coefficient of the function
// dimension ------> coefficient number (param dimension)
// functiontype ---> function type
// x --------------> indipendent variable

inline double deriv1 (double *param, int dimension, int functiontype, double x);
