
#include <include/symbolic_functions.h>
#include <include/amici.h>
#include <include/amici_model.h>
#include <string.h>
#include <include/udata.h>
#include "model_jakstat_adjoint_o2_w.h"

int Jv_model_jakstat_adjoint_o2(N_Vector v, N_Vector Jv, realtype t, N_Vector x, N_Vector xdot, void *user_data, N_Vector tmp) {
int status = 0;
TempData *tdata = (TempData*) user_data;
Model *model = (Model*) tdata->model;
UserData *udata = (UserData*) tdata->udata;
realtype *x_tmp = N_VGetArrayPointer(x);
realtype *xdot_tmp = N_VGetArrayPointer(xdot);
realtype *v_tmp = N_VGetArrayPointer(v);
realtype *Jv_tmp = N_VGetArrayPointer(Jv);
memset(Jv_tmp,0,sizeof(realtype)*162);
status = w_model_jakstat_adjoint_o2(t,x,NULL,tdata);
  Jv_tmp[0] = udata->k[1]*udata->p[3]*udata->w[2]*v_tmp[8]-udata->k[0]*udata->p[0]*v_tmp[0]*udata->w[0]*udata->w[2];
  Jv_tmp[1] = udata->p[0]*v_tmp[0]*udata->w[0]-udata->p[1]*v_tmp[1]*udata->dwdx[0]*2.0;
  Jv_tmp[2] = -udata->p[2]*v_tmp[2]+udata->p[1]*v_tmp[1]*udata->dwdx[0];
  Jv_tmp[3] = udata->k[0]*udata->p[2]*v_tmp[2]*udata->w[3]-udata->k[1]*udata->p[3]*v_tmp[3]*udata->w[3];
  Jv_tmp[4] = -udata->p[3]*v_tmp[4]+udata->p[3]*v_tmp[3]*udata->dwdx[1];
  Jv_tmp[5] = udata->p[3]*v_tmp[4]-udata->p[3]*v_tmp[5];
  Jv_tmp[6] = udata->p[3]*v_tmp[5]-udata->p[3]*v_tmp[6];
  Jv_tmp[7] = udata->p[3]*v_tmp[6]-udata->p[3]*v_tmp[7];
  Jv_tmp[8] = udata->p[3]*v_tmp[7]-udata->p[3]*v_tmp[8];
  Jv_tmp[9] = -v_tmp[0]*udata->w[0]-udata->p[0]*udata->w[0]*v_tmp[9]+udata->k[1]*udata->p[3]*udata->w[2]*v_tmp[17];
  Jv_tmp[10] = v_tmp[0]*udata->w[0]+udata->p[0]*udata->w[0]*v_tmp[9]-udata->p[1]*v_tmp[1]*x_tmp[10]*4.0-udata->p[1]*x_tmp[1]*v_tmp[10]*4.0;
  Jv_tmp[11] = -udata->p[2]*v_tmp[11]+udata->p[1]*v_tmp[1]*x_tmp[10]*2.0+udata->p[1]*x_tmp[1]*v_tmp[10]*2.0;
  Jv_tmp[12] = -udata->p[3]*v_tmp[12]+udata->k[0]*udata->p[2]*udata->w[3]*v_tmp[11];
  Jv_tmp[13] = udata->p[3]*v_tmp[12]*2.0-udata->p[3]*v_tmp[13];
  Jv_tmp[14] = udata->p[3]*v_tmp[13]-udata->p[3]*v_tmp[14];
  Jv_tmp[15] = udata->p[3]*v_tmp[14]-udata->p[3]*v_tmp[15];
  Jv_tmp[16] = udata->p[3]*v_tmp[15]-udata->p[3]*v_tmp[16];
  Jv_tmp[17] = udata->p[3]*v_tmp[16]-udata->p[3]*v_tmp[17];
  Jv_tmp[18] = -udata->p[0]*udata->w[0]*v_tmp[18]+udata->k[1]*udata->p[3]*udata->w[2]*v_tmp[26];
  Jv_tmp[19] = -v_tmp[1]*(udata->dwdx[0]*2.0+udata->p[1]*x_tmp[19]*4.0)+udata->p[0]*udata->w[0]*v_tmp[18]-udata->p[1]*x_tmp[1]*v_tmp[19]*4.0;
  Jv_tmp[20] = -udata->p[2]*v_tmp[20]+v_tmp[1]*(udata->dwdx[0]+udata->p[1]*x_tmp[19]*2.0)+udata->p[1]*x_tmp[1]*v_tmp[19]*2.0;
  Jv_tmp[21] = -udata->p[3]*v_tmp[21]+udata->k[0]*udata->p[2]*udata->w[3]*v_tmp[20];
  Jv_tmp[22] = udata->p[3]*v_tmp[21]*2.0-udata->p[3]*v_tmp[22];
  Jv_tmp[23] = udata->p[3]*v_tmp[22]-udata->p[3]*v_tmp[23];
  Jv_tmp[24] = udata->p[3]*v_tmp[23]-udata->p[3]*v_tmp[24];
  Jv_tmp[25] = udata->p[3]*v_tmp[24]-udata->p[3]*v_tmp[25];
  Jv_tmp[26] = udata->p[3]*v_tmp[25]-udata->p[3]*v_tmp[26];
  Jv_tmp[27] = -udata->p[0]*udata->w[0]*v_tmp[27]+udata->k[1]*udata->p[3]*udata->w[2]*v_tmp[35];
  Jv_tmp[28] = udata->p[0]*udata->w[0]*v_tmp[27]-udata->p[1]*v_tmp[1]*x_tmp[28]*4.0-udata->p[1]*x_tmp[1]*v_tmp[28]*4.0;
  Jv_tmp[29] = -v_tmp[2]-udata->p[2]*v_tmp[29]+udata->p[1]*v_tmp[1]*x_tmp[28]*2.0+udata->p[1]*x_tmp[1]*v_tmp[28]*2.0;
  Jv_tmp[30] = -udata->p[3]*v_tmp[30]+udata->k[0]*v_tmp[2]*udata->w[3]+udata->k[0]*udata->p[2]*udata->w[3]*v_tmp[29];
  Jv_tmp[31] = udata->p[3]*v_tmp[30]*2.0-udata->p[3]*v_tmp[31];
  Jv_tmp[32] = udata->p[3]*v_tmp[31]-udata->p[3]*v_tmp[32];
  Jv_tmp[33] = udata->p[3]*v_tmp[32]-udata->p[3]*v_tmp[33];
  Jv_tmp[34] = udata->p[3]*v_tmp[33]-udata->p[3]*v_tmp[34];
  Jv_tmp[35] = udata->p[3]*v_tmp[34]-udata->p[3]*v_tmp[35];
  Jv_tmp[36] = udata->k[1]*udata->w[2]*v_tmp[8]-udata->p[0]*udata->w[0]*v_tmp[36]+udata->k[1]*udata->p[3]*udata->w[2]*v_tmp[44];
  Jv_tmp[37] = udata->p[0]*udata->w[0]*v_tmp[36]-udata->p[1]*v_tmp[1]*x_tmp[37]*4.0-udata->p[1]*x_tmp[1]*v_tmp[37]*4.0;
  Jv_tmp[38] = -udata->p[2]*v_tmp[38]+udata->p[1]*v_tmp[1]*x_tmp[37]*2.0+udata->p[1]*x_tmp[1]*v_tmp[37]*2.0;
  Jv_tmp[39] = -v_tmp[3]-udata->p[3]*v_tmp[39]+udata->k[0]*udata->p[2]*udata->w[3]*v_tmp[38];
  Jv_tmp[40] = -v_tmp[4]+udata->p[3]*v_tmp[39]*2.0-udata->p[3]*v_tmp[40]+v_tmp[3]*udata->dwdx[1];
  Jv_tmp[41] = v_tmp[4]-v_tmp[5]+udata->p[3]*v_tmp[40]-udata->p[3]*v_tmp[41];
  Jv_tmp[42] = v_tmp[5]-v_tmp[6]+udata->p[3]*v_tmp[41]-udata->p[3]*v_tmp[42];
  Jv_tmp[43] = v_tmp[6]-v_tmp[7]+udata->p[3]*v_tmp[42]-udata->p[3]*v_tmp[43];
  Jv_tmp[44] = v_tmp[7]-v_tmp[8]+udata->p[3]*v_tmp[43]-udata->p[3]*v_tmp[44];
  Jv_tmp[45] = -udata->p[0]*udata->w[0]*v_tmp[45]+udata->k[1]*udata->p[3]*udata->w[2]*v_tmp[53];
  Jv_tmp[46] = udata->p[0]*udata->w[0]*v_tmp[45]-udata->p[1]*v_tmp[1]*x_tmp[46]*4.0-udata->p[1]*x_tmp[1]*v_tmp[46]*4.0;
  Jv_tmp[47] = -udata->p[2]*v_tmp[47]+udata->p[1]*v_tmp[1]*x_tmp[46]*2.0+udata->p[1]*x_tmp[1]*v_tmp[46]*2.0;
  Jv_tmp[48] = -udata->p[3]*v_tmp[48]+udata->k[0]*udata->p[2]*udata->w[3]*v_tmp[47];
  Jv_tmp[49] = udata->p[3]*v_tmp[48]*2.0-udata->p[3]*v_tmp[49];
  Jv_tmp[50] = udata->p[3]*v_tmp[49]-udata->p[3]*v_tmp[50];
  Jv_tmp[51] = udata->p[3]*v_tmp[50]-udata->p[3]*v_tmp[51];
  Jv_tmp[52] = udata->p[3]*v_tmp[51]-udata->p[3]*v_tmp[52];
  Jv_tmp[53] = udata->p[3]*v_tmp[52]-udata->p[3]*v_tmp[53];
  Jv_tmp[54] = -udata->p[0]*v_tmp[0]*udata->w[5]-udata->p[0]*udata->w[0]*v_tmp[54]+udata->k[1]*udata->p[3]*udata->w[2]*v_tmp[62];
  Jv_tmp[55] = udata->p[0]*v_tmp[0]*udata->w[5]+udata->p[0]*udata->w[0]*v_tmp[54]-udata->p[1]*v_tmp[1]*x_tmp[55]*4.0-udata->p[1]*x_tmp[1]*v_tmp[55]*4.0;
  Jv_tmp[56] = -udata->p[2]*v_tmp[56]+udata->p[1]*v_tmp[1]*x_tmp[55]*2.0+udata->p[1]*x_tmp[1]*v_tmp[55]*2.0;
  Jv_tmp[57] = -udata->p[3]*v_tmp[57]+udata->k[0]*udata->p[2]*udata->w[3]*v_tmp[56];
  Jv_tmp[58] = udata->p[3]*v_tmp[57]*2.0-udata->p[3]*v_tmp[58];
  Jv_tmp[59] = udata->p[3]*v_tmp[58]-udata->p[3]*v_tmp[59];
  Jv_tmp[60] = udata->p[3]*v_tmp[59]-udata->p[3]*v_tmp[60];
  Jv_tmp[61] = udata->p[3]*v_tmp[60]-udata->p[3]*v_tmp[61];
  Jv_tmp[62] = udata->p[3]*v_tmp[61]-udata->p[3]*v_tmp[62];
  Jv_tmp[63] = -udata->p[0]*v_tmp[0]*udata->w[6]-udata->p[0]*udata->w[0]*v_tmp[63]+udata->k[1]*udata->p[3]*udata->w[2]*v_tmp[71];
  Jv_tmp[64] = udata->p[0]*v_tmp[0]*udata->w[6]+udata->p[0]*udata->w[0]*v_tmp[63]-udata->p[1]*v_tmp[1]*x_tmp[64]*4.0-udata->p[1]*x_tmp[1]*v_tmp[64]*4.0;
  Jv_tmp[65] = -udata->p[2]*v_tmp[65]+udata->p[1]*v_tmp[1]*x_tmp[64]*2.0+udata->p[1]*x_tmp[1]*v_tmp[64]*2.0;
  Jv_tmp[66] = -udata->p[3]*v_tmp[66]+udata->k[0]*udata->p[2]*udata->w[3]*v_tmp[65];
  Jv_tmp[67] = udata->p[3]*v_tmp[66]*2.0-udata->p[3]*v_tmp[67];
  Jv_tmp[68] = udata->p[3]*v_tmp[67]-udata->p[3]*v_tmp[68];
  Jv_tmp[69] = udata->p[3]*v_tmp[68]-udata->p[3]*v_tmp[69];
  Jv_tmp[70] = udata->p[3]*v_tmp[69]-udata->p[3]*v_tmp[70];
  Jv_tmp[71] = udata->p[3]*v_tmp[70]-udata->p[3]*v_tmp[71];
  Jv_tmp[72] = -udata->p[0]*v_tmp[0]*udata->w[7]-udata->p[0]*udata->w[0]*v_tmp[72]+udata->k[1]*udata->p[3]*udata->w[2]*v_tmp[80];
  Jv_tmp[73] = udata->p[0]*v_tmp[0]*udata->w[7]+udata->p[0]*udata->w[0]*v_tmp[72]-udata->p[1]*v_tmp[1]*x_tmp[73]*4.0-udata->p[1]*x_tmp[1]*v_tmp[73]*4.0;
  Jv_tmp[74] = -udata->p[2]*v_tmp[74]+udata->p[1]*v_tmp[1]*x_tmp[73]*2.0+udata->p[1]*x_tmp[1]*v_tmp[73]*2.0;
  Jv_tmp[75] = -udata->p[3]*v_tmp[75]+udata->k[0]*udata->p[2]*udata->w[3]*v_tmp[74];
  Jv_tmp[76] = udata->p[3]*v_tmp[75]*2.0-udata->p[3]*v_tmp[76];
  Jv_tmp[77] = udata->p[3]*v_tmp[76]-udata->p[3]*v_tmp[77];
  Jv_tmp[78] = udata->p[3]*v_tmp[77]-udata->p[3]*v_tmp[78];
  Jv_tmp[79] = udata->p[3]*v_tmp[78]-udata->p[3]*v_tmp[79];
  Jv_tmp[80] = udata->p[3]*v_tmp[79]-udata->p[3]*v_tmp[80];
  Jv_tmp[81] = -udata->p[0]*v_tmp[0]*udata->w[8]-udata->p[0]*udata->w[0]*v_tmp[81]+udata->k[1]*udata->p[3]*udata->w[2]*v_tmp[89];
  Jv_tmp[82] = udata->p[0]*v_tmp[0]*udata->w[8]+udata->p[0]*udata->w[0]*v_tmp[81]-udata->p[1]*v_tmp[1]*x_tmp[82]*4.0-udata->p[1]*x_tmp[1]*v_tmp[82]*4.0;
  Jv_tmp[83] = -udata->p[2]*v_tmp[83]+udata->p[1]*v_tmp[1]*x_tmp[82]*2.0+udata->p[1]*x_tmp[1]*v_tmp[82]*2.0;
  Jv_tmp[84] = -udata->p[3]*v_tmp[84]+udata->k[0]*udata->p[2]*udata->w[3]*v_tmp[83];
  Jv_tmp[85] = udata->p[3]*v_tmp[84]*2.0-udata->p[3]*v_tmp[85];
  Jv_tmp[86] = udata->p[3]*v_tmp[85]-udata->p[3]*v_tmp[86];
  Jv_tmp[87] = udata->p[3]*v_tmp[86]-udata->p[3]*v_tmp[87];
  Jv_tmp[88] = udata->p[3]*v_tmp[87]-udata->p[3]*v_tmp[88];
  Jv_tmp[89] = udata->p[3]*v_tmp[88]-udata->p[3]*v_tmp[89];
  Jv_tmp[90] = -udata->p[0]*v_tmp[0]*udata->w[9]-udata->p[0]*udata->w[0]*v_tmp[90]+udata->k[1]*udata->p[3]*udata->w[2]*v_tmp[98];
  Jv_tmp[91] = udata->p[0]*v_tmp[0]*udata->w[9]+udata->p[0]*udata->w[0]*v_tmp[90]-udata->p[1]*v_tmp[1]*x_tmp[91]*4.0-udata->p[1]*x_tmp[1]*v_tmp[91]*4.0;
  Jv_tmp[92] = -udata->p[2]*v_tmp[92]+udata->p[1]*v_tmp[1]*x_tmp[91]*2.0+udata->p[1]*x_tmp[1]*v_tmp[91]*2.0;
  Jv_tmp[93] = -udata->p[3]*v_tmp[93]+udata->k[0]*udata->p[2]*udata->w[3]*v_tmp[92];
  Jv_tmp[94] = udata->p[3]*v_tmp[93]*2.0-udata->p[3]*v_tmp[94];
  Jv_tmp[95] = udata->p[3]*v_tmp[94]-udata->p[3]*v_tmp[95];
  Jv_tmp[96] = udata->p[3]*v_tmp[95]-udata->p[3]*v_tmp[96];
  Jv_tmp[97] = udata->p[3]*v_tmp[96]-udata->p[3]*v_tmp[97];
  Jv_tmp[98] = udata->p[3]*v_tmp[97]-udata->p[3]*v_tmp[98];
  Jv_tmp[99] = -udata->p[0]*udata->w[0]*v_tmp[99]+udata->k[1]*udata->p[3]*udata->w[2]*v_tmp[107];
  Jv_tmp[100] = udata->p[0]*udata->w[0]*v_tmp[99]-udata->p[1]*v_tmp[1]*x_tmp[100]*4.0-udata->p[1]*x_tmp[1]*v_tmp[100]*4.0;
  Jv_tmp[101] = -udata->p[2]*v_tmp[101]+udata->p[1]*v_tmp[1]*x_tmp[100]*2.0+udata->p[1]*x_tmp[1]*v_tmp[100]*2.0;
  Jv_tmp[102] = -udata->p[3]*v_tmp[102]+udata->k[0]*udata->p[2]*udata->w[3]*v_tmp[101];
  Jv_tmp[103] = udata->p[3]*v_tmp[102]*2.0-udata->p[3]*v_tmp[103];
  Jv_tmp[104] = udata->p[3]*v_tmp[103]-udata->p[3]*v_tmp[104];
  Jv_tmp[105] = udata->p[3]*v_tmp[104]-udata->p[3]*v_tmp[105];
  Jv_tmp[106] = udata->p[3]*v_tmp[105]-udata->p[3]*v_tmp[106];
  Jv_tmp[107] = udata->p[3]*v_tmp[106]-udata->p[3]*v_tmp[107];
  Jv_tmp[108] = -udata->p[0]*udata->w[0]*v_tmp[108]+udata->k[1]*udata->p[3]*udata->w[2]*v_tmp[116];
  Jv_tmp[109] = udata->p[0]*udata->w[0]*v_tmp[108]-udata->p[1]*v_tmp[1]*x_tmp[109]*4.0-udata->p[1]*x_tmp[1]*v_tmp[109]*4.0;
  Jv_tmp[110] = -udata->p[2]*v_tmp[110]+udata->p[1]*v_tmp[1]*x_tmp[109]*2.0+udata->p[1]*x_tmp[1]*v_tmp[109]*2.0;
  Jv_tmp[111] = -udata->p[3]*v_tmp[111]+udata->k[0]*udata->p[2]*udata->w[3]*v_tmp[110];
  Jv_tmp[112] = udata->p[3]*v_tmp[111]*2.0-udata->p[3]*v_tmp[112];
  Jv_tmp[113] = udata->p[3]*v_tmp[112]-udata->p[3]*v_tmp[113];
  Jv_tmp[114] = udata->p[3]*v_tmp[113]-udata->p[3]*v_tmp[114];
  Jv_tmp[115] = udata->p[3]*v_tmp[114]-udata->p[3]*v_tmp[115];
  Jv_tmp[116] = udata->p[3]*v_tmp[115]-udata->p[3]*v_tmp[116];
  Jv_tmp[117] = -udata->p[0]*udata->w[0]*v_tmp[117]+udata->k[1]*udata->p[3]*udata->w[2]*v_tmp[125];
  Jv_tmp[118] = udata->p[0]*udata->w[0]*v_tmp[117]-udata->p[1]*v_tmp[1]*x_tmp[118]*4.0-udata->p[1]*x_tmp[1]*v_tmp[118]*4.0;
  Jv_tmp[119] = -udata->p[2]*v_tmp[119]+udata->p[1]*v_tmp[1]*x_tmp[118]*2.0+udata->p[1]*x_tmp[1]*v_tmp[118]*2.0;
  Jv_tmp[120] = -udata->p[3]*v_tmp[120]+udata->k[0]*udata->p[2]*udata->w[3]*v_tmp[119];
  Jv_tmp[121] = udata->p[3]*v_tmp[120]*2.0-udata->p[3]*v_tmp[121];
  Jv_tmp[122] = udata->p[3]*v_tmp[121]-udata->p[3]*v_tmp[122];
  Jv_tmp[123] = udata->p[3]*v_tmp[122]-udata->p[3]*v_tmp[123];
  Jv_tmp[124] = udata->p[3]*v_tmp[123]-udata->p[3]*v_tmp[124];
  Jv_tmp[125] = udata->p[3]*v_tmp[124]-udata->p[3]*v_tmp[125];
  Jv_tmp[126] = -udata->p[0]*udata->w[0]*v_tmp[126]+udata->k[1]*udata->p[3]*udata->w[2]*v_tmp[134];
  Jv_tmp[127] = udata->p[0]*udata->w[0]*v_tmp[126]-udata->p[1]*v_tmp[1]*x_tmp[127]*4.0-udata->p[1]*x_tmp[1]*v_tmp[127]*4.0;
  Jv_tmp[128] = -udata->p[2]*v_tmp[128]+udata->p[1]*v_tmp[1]*x_tmp[127]*2.0+udata->p[1]*x_tmp[1]*v_tmp[127]*2.0;
  Jv_tmp[129] = -udata->p[3]*v_tmp[129]+udata->k[0]*udata->p[2]*udata->w[3]*v_tmp[128];
  Jv_tmp[130] = udata->p[3]*v_tmp[129]*2.0-udata->p[3]*v_tmp[130];
  Jv_tmp[131] = udata->p[3]*v_tmp[130]-udata->p[3]*v_tmp[131];
  Jv_tmp[132] = udata->p[3]*v_tmp[131]-udata->p[3]*v_tmp[132];
  Jv_tmp[133] = udata->p[3]*v_tmp[132]-udata->p[3]*v_tmp[133];
  Jv_tmp[134] = udata->p[3]*v_tmp[133]-udata->p[3]*v_tmp[134];
  Jv_tmp[135] = -udata->p[0]*udata->w[0]*v_tmp[135]+udata->k[1]*udata->p[3]*udata->w[2]*v_tmp[143];
  Jv_tmp[136] = udata->p[0]*udata->w[0]*v_tmp[135]-udata->p[1]*v_tmp[1]*x_tmp[136]*4.0-udata->p[1]*x_tmp[1]*v_tmp[136]*4.0;
  Jv_tmp[137] = -udata->p[2]*v_tmp[137]+udata->p[1]*v_tmp[1]*x_tmp[136]*2.0+udata->p[1]*x_tmp[1]*v_tmp[136]*2.0;
  Jv_tmp[138] = -udata->p[3]*v_tmp[138]+udata->k[0]*udata->p[2]*udata->w[3]*v_tmp[137];
  Jv_tmp[139] = udata->p[3]*v_tmp[138]*2.0-udata->p[3]*v_tmp[139];
  Jv_tmp[140] = udata->p[3]*v_tmp[139]-udata->p[3]*v_tmp[140];
  Jv_tmp[141] = udata->p[3]*v_tmp[140]-udata->p[3]*v_tmp[141];
  Jv_tmp[142] = udata->p[3]*v_tmp[141]-udata->p[3]*v_tmp[142];
  Jv_tmp[143] = udata->p[3]*v_tmp[142]-udata->p[3]*v_tmp[143];
  Jv_tmp[144] = -udata->p[0]*udata->w[0]*v_tmp[144]+udata->k[1]*udata->p[3]*udata->w[2]*v_tmp[152];
  Jv_tmp[145] = udata->p[0]*udata->w[0]*v_tmp[144]-udata->p[1]*v_tmp[1]*x_tmp[145]*4.0-udata->p[1]*x_tmp[1]*v_tmp[145]*4.0;
  Jv_tmp[146] = -udata->p[2]*v_tmp[146]+udata->p[1]*v_tmp[1]*x_tmp[145]*2.0+udata->p[1]*x_tmp[1]*v_tmp[145]*2.0;
  Jv_tmp[147] = -udata->p[3]*v_tmp[147]+udata->k[0]*udata->p[2]*udata->w[3]*v_tmp[146];
  Jv_tmp[148] = udata->p[3]*v_tmp[147]*2.0-udata->p[3]*v_tmp[148];
  Jv_tmp[149] = udata->p[3]*v_tmp[148]-udata->p[3]*v_tmp[149];
  Jv_tmp[150] = udata->p[3]*v_tmp[149]-udata->p[3]*v_tmp[150];
  Jv_tmp[151] = udata->p[3]*v_tmp[150]-udata->p[3]*v_tmp[151];
  Jv_tmp[152] = udata->p[3]*v_tmp[151]-udata->p[3]*v_tmp[152];
  Jv_tmp[153] = -udata->p[0]*udata->w[0]*v_tmp[153]+udata->k[1]*udata->p[3]*udata->w[2]*v_tmp[161];
  Jv_tmp[154] = udata->p[0]*udata->w[0]*v_tmp[153]-udata->p[1]*v_tmp[1]*x_tmp[154]*4.0-udata->p[1]*x_tmp[1]*v_tmp[154]*4.0;
  Jv_tmp[155] = -udata->p[2]*v_tmp[155]+udata->p[1]*v_tmp[1]*x_tmp[154]*2.0+udata->p[1]*x_tmp[1]*v_tmp[154]*2.0;
  Jv_tmp[156] = -udata->p[3]*v_tmp[156]+udata->k[0]*udata->p[2]*udata->w[3]*v_tmp[155];
  Jv_tmp[157] = udata->p[3]*v_tmp[156]*2.0-udata->p[3]*v_tmp[157];
  Jv_tmp[158] = udata->p[3]*v_tmp[157]-udata->p[3]*v_tmp[158];
  Jv_tmp[159] = udata->p[3]*v_tmp[158]-udata->p[3]*v_tmp[159];
  Jv_tmp[160] = udata->p[3]*v_tmp[159]-udata->p[3]*v_tmp[160];
  Jv_tmp[161] = udata->p[3]*v_tmp[160]-udata->p[3]*v_tmp[161];
return(status);

}


