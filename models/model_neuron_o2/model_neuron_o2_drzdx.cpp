
#include <include/symbolic_functions.h>
#include <sundials/sundials_types.h> //realtype definition
#include <cmath> 

void drzdx_model_neuron_o2(double *drzdx, const int ie, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h) {
  drzdx[0+0*5] = 1.0;
  drzdx[1+2*5] = 1.0;
  drzdx[2+4*5] = 1.0;
  drzdx[3+6*5] = 1.0;
  drzdx[4+8*5] = 1.0;
}

