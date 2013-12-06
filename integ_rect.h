/* integ_rect.h */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "function.h"

// *param ---------> array with the coefficient of the function
// dimension ------> coefficient number (param dimension)
// functiontype ---> function type
// errorinteg ----------> error done while computing the integral 
// extr_a  --------> first extreme point
// extr_b ---------> second exreme point

inline void integ_rect (double *param, int dimension, int functiontype, double *integ_first,double *integ_second, double *errorinteg, int conv, double extr_a, double extr_b);
