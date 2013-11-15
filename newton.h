/* newton.h */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <math.h>
#include "function.h"
#include "deriv1.h"

// *param ---------> array with the coefficient of the function
// dimension ------> coefficient number (param dimension)
// functiontype ---> function type
// precision ------> precision required
// error ----------> error done while computing the root
// inter ----------> number of executed iterations
// extr_a  --------> first extreme point
// extr_b ---------> second exreme point
// mode -----------> Product Between The Function And It' Second Derivate In extr_a

inline double newton (double *param, int dimension, int functiontype, double precision, double *error, long int *inter, double extr_a, double extr_b, int mode);
