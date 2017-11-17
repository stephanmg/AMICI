
#include <include/symbolic_functions.h>
#include <sundials/sundials_types.h> //realtype definition
#include <cmath> 

void deltasx_model_neuron(double *deltasx, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h, const realtype *w, const int ip, const int ie, const realtype *xdot, const realtype *xdot_old, const realtype *sx, const realtype *stau) {
switch (ip) {
  case 0: {
              switch(ie) { 
              case 0: {
  deltasx[0] = -sx[0]-stau[ip]*(xdot[0]-xdot_old[0])-stau[ip]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2);
  deltasx[1] = -stau[ip]*(xdot[1]-xdot_old[1]);

              } break;

              } 

  } break;

  case 1: {
              switch(ie) { 
              case 0: {
  deltasx[0] = -sx[0]-stau[ip]*(xdot[0]-xdot_old[0])-stau[ip]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2);
  deltasx[1] = -stau[ip]*(xdot[1]-xdot_old[1]);

              } break;

              } 

  } break;

  case 2: {
              switch(ie) { 
              case 0: {
  deltasx[0] = -sx[0]-stau[ip]*(xdot[0]-xdot_old[0])-stau[ip]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2)-1.0;
  deltasx[1] = -stau[ip]*(xdot[1]-xdot_old[1]);

              } break;

              } 

  } break;

  case 3: {
              switch(ie) { 
              case 0: {
  deltasx[0] = -sx[0]-stau[ip]*(xdot[0]-xdot_old[0])-stau[ip]*(k[1]+x[0]*5.0-x[1]+(x[0]*x[0])*(1.0/2.5E1)+1.4E2);
  deltasx[1] = -stau[ip]*(xdot[1]-xdot_old[1])+1.0;

              } break;

              } 

  } break;

}
}

