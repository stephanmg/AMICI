
#include <include/symbolic_functions.h>
#include <include/amici.h>
#include <include/amici_model.h>
#include <string.h>
#include <include/tdata.h>
#include "model_neuron_o2_w.h"

int dydp_model_neuron_o2(realtype t, int it, N_Vector x, TempData *tdata) {
int status = 0;
Model *model = (Model*) tdata->model;
UserData *udata = (UserData*) tdata->udata;
realtype *x_tmp = N_VGetArrayPointer(x);
int ip;
status = w_model_neuron_o2(t,x,NULL,tdata);
for(ip = 0; ip<udata->nplist; ip++) {
switch (udata->plist[ip]) {
}
}
return(status);

}


