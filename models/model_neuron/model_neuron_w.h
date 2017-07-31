#ifndef _am_model_neuron_w_h
#define _am_model_neuron_w_h

#include <sundials/sundials_types.h>
#include <sundials/sundials_nvector.h>
#include <sundials/sundials_sparse.h>
#include <sundials/sundials_direct.h>

class UserData;
class ReturnData;
class TempData;
class ExpData;

int w_model_neuron(realtype t, N_Vector x, N_Vector dx, void *user_data);


#endif /* _am_model_neuron_w_h */