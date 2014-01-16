/* convergence.h */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> // sleep
#include <math.h>
#include "function.h"
#include "deriv1.h"
#include "deriv2.h"
#include "deriv4.h"

// *param ---------> array with the coefficient of the function
// dimension ------> coefficient number (param dimension)
// functiontype ---> function type
// extr_a  --------> first extreme point
// extr_b ---------> second exreme point



inline int convergence (double *param, int dimension, int functiontype, double extr_a, double extr_b);
