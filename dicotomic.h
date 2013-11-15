/* dicotomic.h */

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <math.h>
#include "function.h"

// *param ---------> array with the coefficient of the function
// dimension ------> coefficient number (param dimension)
// functiontype ---> function type
// precision ------> precision reuired
// error ----------> error done while computing the root
// inter ----------> number of executed iterations
// extr_a  --------> first extreme point
// extr_b ---------> second exreme point

inline double dicotomic (double *param, int dimension, int functiontype, double precision, double *error, long int *inter, double extr_a, double extr_b);
