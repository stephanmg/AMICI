
#include <include/symbolic_functions.h>
#include <sundials/sundials_types.h> //realtype definition
#include <cmath> 

void y_model_jakstat_adjoint(double *y, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h) {
  y[0] = p[11]+(p[13]*(x[1]+x[2]*2.0))/p[4];
  y[1] = p[10]+(p[12]*(x[0]+x[1]+x[2]*2.0))/p[4];
  y[2] = amici::am_spline_pos(t,5,0.0,p[5],5.0,p[6],1.0E1,p[7],2.0E1,p[8],6.0E1,p[9],0.0,0.0);
}

