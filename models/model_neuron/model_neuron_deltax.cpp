
#include <include/symbolic_functions.h>
#include <string.h>
#include <include/udata.h>
#include <include/tdata.h>
#include "model_neuron_w.h"

int deltax_model_neuron(realtype t, int ie, N_Vector x, N_Vector xdot, N_Vector xdot_old, void *user_data, TempData *tdata) {
int status = 0;
UserData *udata = (UserData*) user_data;
realtype *x_tmp = N_VGetArrayPointer(x);
realtype *xdot_tmp = N_VGetArrayPointer(xdot);
realtype *xdot_old_tmp = N_VGetArrayPointer(xdot_old);
memset(tdata->deltax,0,sizeof(realtype)*2);
status = w_model_neuron(t,x,NULL,user_data);
              switch(ie) { 
              case 0: {
  tdata->deltax[0] = -udata->p[2]-x_tmp[0];
  tdata->deltax[1] = udata->p[3];

              } break;

              } 
return(status);

}

