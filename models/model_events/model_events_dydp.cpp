
#include <include/symbolic_functions.h>
#include <include/amici_defines.h> //realtype definition
typedef amici::realtype realtype;
#include <cmath> 

void dydp_model_events(double *dydp, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h, const int ip) {
switch (ip) {
  case 3: {
  dydp[0] = x[0]+x[1]+x[2];

  } break;

}
}
