
#include <include/symbolic_functions.h>
#include <sundials/sundials_types.h> //realtype definition
#include <cmath> 

void JSparse_model_nested_events(realtype *J, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h, const realtype *w, const realtype *dwdx) {
  J[0] = -p[4]+h[1]*p[3];
}

