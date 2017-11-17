
#include <include/symbolic_functions.h>
#include <sundials/sundials_types.h> //realtype definition
#include <cmath> 

void x0_model_steadystate(realtype *x0, const realtype t, const realtype *p, const realtype *k) {
  x0[0] = k[0];
  x0[1] = k[1];
  x0[2] = k[2];
}

