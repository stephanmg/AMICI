
#include <include/symbolic_functions.h>
#include <include/amici.h>
#include <include/amici_model.h>
#include <string.h>
#include <include/udata.h>
#include "model_jakstat_adjoint_o2_dwdx.h"
#include "model_jakstat_adjoint_o2_w.h"

int JSparse_model_jakstat_adjoint_o2(realtype t, N_Vector x, N_Vector xdot, SlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3) {
int status = 0;
TempData *tdata = (TempData*) user_data;
Model *model = (Model*) tdata->model;
UserData *udata = (UserData*) tdata->udata;
realtype *x_tmp = N_VGetArrayPointer(x);
realtype *xdot_tmp = N_VGetArrayPointer(xdot);
int inz;
SparseSetMatToZero(J);
J->indexvals[0] = 0;
J->indexvals[1] = 1;
J->indexvals[2] = 9;
J->indexvals[3] = 10;
J->indexvals[4] = 54;
J->indexvals[5] = 55;
J->indexvals[6] = 63;
J->indexvals[7] = 64;
J->indexvals[8] = 72;
J->indexvals[9] = 73;
J->indexvals[10] = 81;
J->indexvals[11] = 82;
J->indexvals[12] = 90;
J->indexvals[13] = 91;
J->indexvals[14] = 1;
J->indexvals[15] = 2;
J->indexvals[16] = 10;
J->indexvals[17] = 11;
J->indexvals[18] = 19;
J->indexvals[19] = 20;
J->indexvals[20] = 28;
J->indexvals[21] = 29;
J->indexvals[22] = 37;
J->indexvals[23] = 38;
J->indexvals[24] = 46;
J->indexvals[25] = 47;
J->indexvals[26] = 55;
J->indexvals[27] = 56;
J->indexvals[28] = 64;
J->indexvals[29] = 65;
J->indexvals[30] = 73;
J->indexvals[31] = 74;
J->indexvals[32] = 82;
J->indexvals[33] = 83;
J->indexvals[34] = 91;
J->indexvals[35] = 92;
J->indexvals[36] = 100;
J->indexvals[37] = 101;
J->indexvals[38] = 109;
J->indexvals[39] = 110;
J->indexvals[40] = 118;
J->indexvals[41] = 119;
J->indexvals[42] = 127;
J->indexvals[43] = 128;
J->indexvals[44] = 136;
J->indexvals[45] = 137;
J->indexvals[46] = 145;
J->indexvals[47] = 146;
J->indexvals[48] = 154;
J->indexvals[49] = 155;
J->indexvals[50] = 2;
J->indexvals[51] = 3;
J->indexvals[52] = 29;
J->indexvals[53] = 30;
J->indexvals[54] = 3;
J->indexvals[55] = 4;
J->indexvals[56] = 39;
J->indexvals[57] = 40;
J->indexvals[58] = 4;
J->indexvals[59] = 5;
J->indexvals[60] = 40;
J->indexvals[61] = 41;
J->indexvals[62] = 5;
J->indexvals[63] = 6;
J->indexvals[64] = 41;
J->indexvals[65] = 42;
J->indexvals[66] = 6;
J->indexvals[67] = 7;
J->indexvals[68] = 42;
J->indexvals[69] = 43;
J->indexvals[70] = 7;
J->indexvals[71] = 8;
J->indexvals[72] = 43;
J->indexvals[73] = 44;
J->indexvals[74] = 0;
J->indexvals[75] = 8;
J->indexvals[76] = 36;
J->indexvals[77] = 44;
J->indexvals[78] = 9;
J->indexvals[79] = 10;
J->indexvals[80] = 10;
J->indexvals[81] = 11;
J->indexvals[82] = 11;
J->indexvals[83] = 12;
J->indexvals[84] = 12;
J->indexvals[85] = 13;
J->indexvals[86] = 13;
J->indexvals[87] = 14;
J->indexvals[88] = 14;
J->indexvals[89] = 15;
J->indexvals[90] = 15;
J->indexvals[91] = 16;
J->indexvals[92] = 16;
J->indexvals[93] = 17;
J->indexvals[94] = 9;
J->indexvals[95] = 17;
J->indexvals[96] = 18;
J->indexvals[97] = 19;
J->indexvals[98] = 19;
J->indexvals[99] = 20;
J->indexvals[100] = 20;
J->indexvals[101] = 21;
J->indexvals[102] = 21;
J->indexvals[103] = 22;
J->indexvals[104] = 22;
J->indexvals[105] = 23;
J->indexvals[106] = 23;
J->indexvals[107] = 24;
J->indexvals[108] = 24;
J->indexvals[109] = 25;
J->indexvals[110] = 25;
J->indexvals[111] = 26;
J->indexvals[112] = 18;
J->indexvals[113] = 26;
J->indexvals[114] = 27;
J->indexvals[115] = 28;
J->indexvals[116] = 28;
J->indexvals[117] = 29;
J->indexvals[118] = 29;
J->indexvals[119] = 30;
J->indexvals[120] = 30;
J->indexvals[121] = 31;
J->indexvals[122] = 31;
J->indexvals[123] = 32;
J->indexvals[124] = 32;
J->indexvals[125] = 33;
J->indexvals[126] = 33;
J->indexvals[127] = 34;
J->indexvals[128] = 34;
J->indexvals[129] = 35;
J->indexvals[130] = 27;
J->indexvals[131] = 35;
J->indexvals[132] = 36;
J->indexvals[133] = 37;
J->indexvals[134] = 37;
J->indexvals[135] = 38;
J->indexvals[136] = 38;
J->indexvals[137] = 39;
J->indexvals[138] = 39;
J->indexvals[139] = 40;
J->indexvals[140] = 40;
J->indexvals[141] = 41;
J->indexvals[142] = 41;
J->indexvals[143] = 42;
J->indexvals[144] = 42;
J->indexvals[145] = 43;
J->indexvals[146] = 43;
J->indexvals[147] = 44;
J->indexvals[148] = 36;
J->indexvals[149] = 44;
J->indexvals[150] = 45;
J->indexvals[151] = 46;
J->indexvals[152] = 46;
J->indexvals[153] = 47;
J->indexvals[154] = 47;
J->indexvals[155] = 48;
J->indexvals[156] = 48;
J->indexvals[157] = 49;
J->indexvals[158] = 49;
J->indexvals[159] = 50;
J->indexvals[160] = 50;
J->indexvals[161] = 51;
J->indexvals[162] = 51;
J->indexvals[163] = 52;
J->indexvals[164] = 52;
J->indexvals[165] = 53;
J->indexvals[166] = 45;
J->indexvals[167] = 53;
J->indexvals[168] = 54;
J->indexvals[169] = 55;
J->indexvals[170] = 55;
J->indexvals[171] = 56;
J->indexvals[172] = 56;
J->indexvals[173] = 57;
J->indexvals[174] = 57;
J->indexvals[175] = 58;
J->indexvals[176] = 58;
J->indexvals[177] = 59;
J->indexvals[178] = 59;
J->indexvals[179] = 60;
J->indexvals[180] = 60;
J->indexvals[181] = 61;
J->indexvals[182] = 61;
J->indexvals[183] = 62;
J->indexvals[184] = 54;
J->indexvals[185] = 62;
J->indexvals[186] = 63;
J->indexvals[187] = 64;
J->indexvals[188] = 64;
J->indexvals[189] = 65;
J->indexvals[190] = 65;
J->indexvals[191] = 66;
J->indexvals[192] = 66;
J->indexvals[193] = 67;
J->indexvals[194] = 67;
J->indexvals[195] = 68;
J->indexvals[196] = 68;
J->indexvals[197] = 69;
J->indexvals[198] = 69;
J->indexvals[199] = 70;
J->indexvals[200] = 70;
J->indexvals[201] = 71;
J->indexvals[202] = 63;
J->indexvals[203] = 71;
J->indexvals[204] = 72;
J->indexvals[205] = 73;
J->indexvals[206] = 73;
J->indexvals[207] = 74;
J->indexvals[208] = 74;
J->indexvals[209] = 75;
J->indexvals[210] = 75;
J->indexvals[211] = 76;
J->indexvals[212] = 76;
J->indexvals[213] = 77;
J->indexvals[214] = 77;
J->indexvals[215] = 78;
J->indexvals[216] = 78;
J->indexvals[217] = 79;
J->indexvals[218] = 79;
J->indexvals[219] = 80;
J->indexvals[220] = 72;
J->indexvals[221] = 80;
J->indexvals[222] = 81;
J->indexvals[223] = 82;
J->indexvals[224] = 82;
J->indexvals[225] = 83;
J->indexvals[226] = 83;
J->indexvals[227] = 84;
J->indexvals[228] = 84;
J->indexvals[229] = 85;
J->indexvals[230] = 85;
J->indexvals[231] = 86;
J->indexvals[232] = 86;
J->indexvals[233] = 87;
J->indexvals[234] = 87;
J->indexvals[235] = 88;
J->indexvals[236] = 88;
J->indexvals[237] = 89;
J->indexvals[238] = 81;
J->indexvals[239] = 89;
J->indexvals[240] = 90;
J->indexvals[241] = 91;
J->indexvals[242] = 91;
J->indexvals[243] = 92;
J->indexvals[244] = 92;
J->indexvals[245] = 93;
J->indexvals[246] = 93;
J->indexvals[247] = 94;
J->indexvals[248] = 94;
J->indexvals[249] = 95;
J->indexvals[250] = 95;
J->indexvals[251] = 96;
J->indexvals[252] = 96;
J->indexvals[253] = 97;
J->indexvals[254] = 97;
J->indexvals[255] = 98;
J->indexvals[256] = 90;
J->indexvals[257] = 98;
J->indexvals[258] = 99;
J->indexvals[259] = 100;
J->indexvals[260] = 100;
J->indexvals[261] = 101;
J->indexvals[262] = 101;
J->indexvals[263] = 102;
J->indexvals[264] = 102;
J->indexvals[265] = 103;
J->indexvals[266] = 103;
J->indexvals[267] = 104;
J->indexvals[268] = 104;
J->indexvals[269] = 105;
J->indexvals[270] = 105;
J->indexvals[271] = 106;
J->indexvals[272] = 106;
J->indexvals[273] = 107;
J->indexvals[274] = 99;
J->indexvals[275] = 107;
J->indexvals[276] = 108;
J->indexvals[277] = 109;
J->indexvals[278] = 109;
J->indexvals[279] = 110;
J->indexvals[280] = 110;
J->indexvals[281] = 111;
J->indexvals[282] = 111;
J->indexvals[283] = 112;
J->indexvals[284] = 112;
J->indexvals[285] = 113;
J->indexvals[286] = 113;
J->indexvals[287] = 114;
J->indexvals[288] = 114;
J->indexvals[289] = 115;
J->indexvals[290] = 115;
J->indexvals[291] = 116;
J->indexvals[292] = 108;
J->indexvals[293] = 116;
J->indexvals[294] = 117;
J->indexvals[295] = 118;
J->indexvals[296] = 118;
J->indexvals[297] = 119;
J->indexvals[298] = 119;
J->indexvals[299] = 120;
J->indexvals[300] = 120;
J->indexvals[301] = 121;
J->indexvals[302] = 121;
J->indexvals[303] = 122;
J->indexvals[304] = 122;
J->indexvals[305] = 123;
J->indexvals[306] = 123;
J->indexvals[307] = 124;
J->indexvals[308] = 124;
J->indexvals[309] = 125;
J->indexvals[310] = 117;
J->indexvals[311] = 125;
J->indexvals[312] = 126;
J->indexvals[313] = 127;
J->indexvals[314] = 127;
J->indexvals[315] = 128;
J->indexvals[316] = 128;
J->indexvals[317] = 129;
J->indexvals[318] = 129;
J->indexvals[319] = 130;
J->indexvals[320] = 130;
J->indexvals[321] = 131;
J->indexvals[322] = 131;
J->indexvals[323] = 132;
J->indexvals[324] = 132;
J->indexvals[325] = 133;
J->indexvals[326] = 133;
J->indexvals[327] = 134;
J->indexvals[328] = 126;
J->indexvals[329] = 134;
J->indexvals[330] = 135;
J->indexvals[331] = 136;
J->indexvals[332] = 136;
J->indexvals[333] = 137;
J->indexvals[334] = 137;
J->indexvals[335] = 138;
J->indexvals[336] = 138;
J->indexvals[337] = 139;
J->indexvals[338] = 139;
J->indexvals[339] = 140;
J->indexvals[340] = 140;
J->indexvals[341] = 141;
J->indexvals[342] = 141;
J->indexvals[343] = 142;
J->indexvals[344] = 142;
J->indexvals[345] = 143;
J->indexvals[346] = 135;
J->indexvals[347] = 143;
J->indexvals[348] = 144;
J->indexvals[349] = 145;
J->indexvals[350] = 145;
J->indexvals[351] = 146;
J->indexvals[352] = 146;
J->indexvals[353] = 147;
J->indexvals[354] = 147;
J->indexvals[355] = 148;
J->indexvals[356] = 148;
J->indexvals[357] = 149;
J->indexvals[358] = 149;
J->indexvals[359] = 150;
J->indexvals[360] = 150;
J->indexvals[361] = 151;
J->indexvals[362] = 151;
J->indexvals[363] = 152;
J->indexvals[364] = 144;
J->indexvals[365] = 152;
J->indexvals[366] = 153;
J->indexvals[367] = 154;
J->indexvals[368] = 154;
J->indexvals[369] = 155;
J->indexvals[370] = 155;
J->indexvals[371] = 156;
J->indexvals[372] = 156;
J->indexvals[373] = 157;
J->indexvals[374] = 157;
J->indexvals[375] = 158;
J->indexvals[376] = 158;
J->indexvals[377] = 159;
J->indexvals[378] = 159;
J->indexvals[379] = 160;
J->indexvals[380] = 160;
J->indexvals[381] = 161;
J->indexvals[382] = 153;
J->indexvals[383] = 161;
J->indexptrs[0] = 0;
J->indexptrs[1] = 14;
J->indexptrs[2] = 50;
J->indexptrs[3] = 54;
J->indexptrs[4] = 58;
J->indexptrs[5] = 62;
J->indexptrs[6] = 66;
J->indexptrs[7] = 70;
J->indexptrs[8] = 74;
J->indexptrs[9] = 78;
J->indexptrs[10] = 80;
J->indexptrs[11] = 82;
J->indexptrs[12] = 84;
J->indexptrs[13] = 86;
J->indexptrs[14] = 88;
J->indexptrs[15] = 90;
J->indexptrs[16] = 92;
J->indexptrs[17] = 94;
J->indexptrs[18] = 96;
J->indexptrs[19] = 98;
J->indexptrs[20] = 100;
J->indexptrs[21] = 102;
J->indexptrs[22] = 104;
J->indexptrs[23] = 106;
J->indexptrs[24] = 108;
J->indexptrs[25] = 110;
J->indexptrs[26] = 112;
J->indexptrs[27] = 114;
J->indexptrs[28] = 116;
J->indexptrs[29] = 118;
J->indexptrs[30] = 120;
J->indexptrs[31] = 122;
J->indexptrs[32] = 124;
J->indexptrs[33] = 126;
J->indexptrs[34] = 128;
J->indexptrs[35] = 130;
J->indexptrs[36] = 132;
J->indexptrs[37] = 134;
J->indexptrs[38] = 136;
J->indexptrs[39] = 138;
J->indexptrs[40] = 140;
J->indexptrs[41] = 142;
J->indexptrs[42] = 144;
J->indexptrs[43] = 146;
J->indexptrs[44] = 148;
J->indexptrs[45] = 150;
J->indexptrs[46] = 152;
J->indexptrs[47] = 154;
J->indexptrs[48] = 156;
J->indexptrs[49] = 158;
J->indexptrs[50] = 160;
J->indexptrs[51] = 162;
J->indexptrs[52] = 164;
J->indexptrs[53] = 166;
J->indexptrs[54] = 168;
J->indexptrs[55] = 170;
J->indexptrs[56] = 172;
J->indexptrs[57] = 174;
J->indexptrs[58] = 176;
J->indexptrs[59] = 178;
J->indexptrs[60] = 180;
J->indexptrs[61] = 182;
J->indexptrs[62] = 184;
J->indexptrs[63] = 186;
J->indexptrs[64] = 188;
J->indexptrs[65] = 190;
J->indexptrs[66] = 192;
J->indexptrs[67] = 194;
J->indexptrs[68] = 196;
J->indexptrs[69] = 198;
J->indexptrs[70] = 200;
J->indexptrs[71] = 202;
J->indexptrs[72] = 204;
J->indexptrs[73] = 206;
J->indexptrs[74] = 208;
J->indexptrs[75] = 210;
J->indexptrs[76] = 212;
J->indexptrs[77] = 214;
J->indexptrs[78] = 216;
J->indexptrs[79] = 218;
J->indexptrs[80] = 220;
J->indexptrs[81] = 222;
J->indexptrs[82] = 224;
J->indexptrs[83] = 226;
J->indexptrs[84] = 228;
J->indexptrs[85] = 230;
J->indexptrs[86] = 232;
J->indexptrs[87] = 234;
J->indexptrs[88] = 236;
J->indexptrs[89] = 238;
J->indexptrs[90] = 240;
J->indexptrs[91] = 242;
J->indexptrs[92] = 244;
J->indexptrs[93] = 246;
J->indexptrs[94] = 248;
J->indexptrs[95] = 250;
J->indexptrs[96] = 252;
J->indexptrs[97] = 254;
J->indexptrs[98] = 256;
J->indexptrs[99] = 258;
J->indexptrs[100] = 260;
J->indexptrs[101] = 262;
J->indexptrs[102] = 264;
J->indexptrs[103] = 266;
J->indexptrs[104] = 268;
J->indexptrs[105] = 270;
J->indexptrs[106] = 272;
J->indexptrs[107] = 274;
J->indexptrs[108] = 276;
J->indexptrs[109] = 278;
J->indexptrs[110] = 280;
J->indexptrs[111] = 282;
J->indexptrs[112] = 284;
J->indexptrs[113] = 286;
J->indexptrs[114] = 288;
J->indexptrs[115] = 290;
J->indexptrs[116] = 292;
J->indexptrs[117] = 294;
J->indexptrs[118] = 296;
J->indexptrs[119] = 298;
J->indexptrs[120] = 300;
J->indexptrs[121] = 302;
J->indexptrs[122] = 304;
J->indexptrs[123] = 306;
J->indexptrs[124] = 308;
J->indexptrs[125] = 310;
J->indexptrs[126] = 312;
J->indexptrs[127] = 314;
J->indexptrs[128] = 316;
J->indexptrs[129] = 318;
J->indexptrs[130] = 320;
J->indexptrs[131] = 322;
J->indexptrs[132] = 324;
J->indexptrs[133] = 326;
J->indexptrs[134] = 328;
J->indexptrs[135] = 330;
J->indexptrs[136] = 332;
J->indexptrs[137] = 334;
J->indexptrs[138] = 336;
J->indexptrs[139] = 338;
J->indexptrs[140] = 340;
J->indexptrs[141] = 342;
J->indexptrs[142] = 344;
J->indexptrs[143] = 346;
J->indexptrs[144] = 348;
J->indexptrs[145] = 350;
J->indexptrs[146] = 352;
J->indexptrs[147] = 354;
J->indexptrs[148] = 356;
J->indexptrs[149] = 358;
J->indexptrs[150] = 360;
J->indexptrs[151] = 362;
J->indexptrs[152] = 364;
J->indexptrs[153] = 366;
J->indexptrs[154] = 368;
J->indexptrs[155] = 370;
J->indexptrs[156] = 372;
J->indexptrs[157] = 374;
J->indexptrs[158] = 376;
J->indexptrs[159] = 378;
J->indexptrs[160] = 380;
J->indexptrs[161] = 382;
J->indexptrs[162] = 384;
status = w_model_jakstat_adjoint_o2(t,x,NULL,tdata);
status = dwdx_model_jakstat_adjoint_o2(t,x,NULL,user_data);
  J->data[0] = -udata->k[0]*udata->p[0]*udata->w[0]*udata->w[2];
  J->data[1] = udata->p[0]*udata->w[0];
  J->data[2] = -udata->w[0];
  J->data[3] = udata->w[0];
  J->data[4] = -udata->p[0]*udata->w[5];
  J->data[5] = udata->p[0]*udata->w[5];
  J->data[6] = -udata->p[0]*udata->w[6];
  J->data[7] = udata->p[0]*udata->w[6];
  J->data[8] = -udata->p[0]*udata->w[7];
  J->data[9] = udata->p[0]*udata->w[7];
  J->data[10] = -udata->p[0]*udata->w[8];
  J->data[11] = udata->p[0]*udata->w[8];
  J->data[12] = -udata->p[0]*udata->w[9];
  J->data[13] = udata->p[0]*udata->w[9];
  J->data[14] = udata->p[1]*udata->dwdx[0]*-2.0;
  J->data[15] = udata->p[1]*udata->dwdx[0];
  J->data[16] = udata->p[1]*x_tmp[10]*-4.0;
  J->data[17] = udata->p[1]*x_tmp[10]*2.0;
  J->data[18] = udata->dwdx[0]*-2.0-udata->p[1]*x_tmp[19]*4.0;
  J->data[19] = udata->dwdx[0]+udata->p[1]*x_tmp[19]*2.0;
  J->data[20] = udata->p[1]*x_tmp[28]*-4.0;
  J->data[21] = udata->p[1]*x_tmp[28]*2.0;
  J->data[22] = udata->p[1]*x_tmp[37]*-4.0;
  J->data[23] = udata->p[1]*x_tmp[37]*2.0;
  J->data[24] = udata->p[1]*x_tmp[46]*-4.0;
  J->data[25] = udata->p[1]*x_tmp[46]*2.0;
  J->data[26] = udata->p[1]*x_tmp[55]*-4.0;
  J->data[27] = udata->p[1]*x_tmp[55]*2.0;
  J->data[28] = udata->p[1]*x_tmp[64]*-4.0;
  J->data[29] = udata->p[1]*x_tmp[64]*2.0;
  J->data[30] = udata->p[1]*x_tmp[73]*-4.0;
  J->data[31] = udata->p[1]*x_tmp[73]*2.0;
  J->data[32] = udata->p[1]*x_tmp[82]*-4.0;
  J->data[33] = udata->p[1]*x_tmp[82]*2.0;
  J->data[34] = udata->p[1]*x_tmp[91]*-4.0;
  J->data[35] = udata->p[1]*x_tmp[91]*2.0;
  J->data[36] = udata->p[1]*x_tmp[100]*-4.0;
  J->data[37] = udata->p[1]*x_tmp[100]*2.0;
  J->data[38] = udata->p[1]*x_tmp[109]*-4.0;
  J->data[39] = udata->p[1]*x_tmp[109]*2.0;
  J->data[40] = udata->p[1]*x_tmp[118]*-4.0;
  J->data[41] = udata->p[1]*x_tmp[118]*2.0;
  J->data[42] = udata->p[1]*x_tmp[127]*-4.0;
  J->data[43] = udata->p[1]*x_tmp[127]*2.0;
  J->data[44] = udata->p[1]*x_tmp[136]*-4.0;
  J->data[45] = udata->p[1]*x_tmp[136]*2.0;
  J->data[46] = udata->p[1]*x_tmp[145]*-4.0;
  J->data[47] = udata->p[1]*x_tmp[145]*2.0;
  J->data[48] = udata->p[1]*x_tmp[154]*-4.0;
  J->data[49] = udata->p[1]*x_tmp[154]*2.0;
  J->data[50] = -udata->p[2];
  J->data[51] = udata->k[0]*udata->p[2]*udata->w[3];
  J->data[52] = -1.0;
  J->data[53] = udata->k[0]*udata->w[3];
  J->data[54] = -udata->k[1]*udata->p[3]*udata->w[3];
  J->data[55] = udata->p[3]*udata->dwdx[1];
  J->data[56] = -1.0;
  J->data[57] = udata->dwdx[1];
  J->data[58] = -udata->p[3];
  J->data[59] = udata->p[3];
  J->data[60] = -1.0;
  J->data[61] = 1.0;
  J->data[62] = -udata->p[3];
  J->data[63] = udata->p[3];
  J->data[64] = -1.0;
  J->data[65] = 1.0;
  J->data[66] = -udata->p[3];
  J->data[67] = udata->p[3];
  J->data[68] = -1.0;
  J->data[69] = 1.0;
  J->data[70] = -udata->p[3];
  J->data[71] = udata->p[3];
  J->data[72] = -1.0;
  J->data[73] = 1.0;
  J->data[74] = udata->k[1]*udata->p[3]*udata->w[2];
  J->data[75] = -udata->p[3];
  J->data[76] = udata->k[1]*udata->w[2];
  J->data[77] = -1.0;
  J->data[78] = -udata->p[0]*udata->w[0];
  J->data[79] = udata->p[0]*udata->w[0];
  J->data[80] = udata->p[1]*x_tmp[1]*-4.0;
  J->data[81] = udata->p[1]*x_tmp[1]*2.0;
  J->data[82] = -udata->p[2];
  J->data[83] = udata->k[0]*udata->p[2]*udata->w[3];
  J->data[84] = -udata->p[3];
  J->data[85] = udata->p[3]*2.0;
  J->data[86] = -udata->p[3];
  J->data[87] = udata->p[3];
  J->data[88] = -udata->p[3];
  J->data[89] = udata->p[3];
  J->data[90] = -udata->p[3];
  J->data[91] = udata->p[3];
  J->data[92] = -udata->p[3];
  J->data[93] = udata->p[3];
  J->data[94] = udata->k[1]*udata->p[3]*udata->w[2];
  J->data[95] = -udata->p[3];
  J->data[96] = -udata->p[0]*udata->w[0];
  J->data[97] = udata->p[0]*udata->w[0];
  J->data[98] = udata->p[1]*x_tmp[1]*-4.0;
  J->data[99] = udata->p[1]*x_tmp[1]*2.0;
  J->data[100] = -udata->p[2];
  J->data[101] = udata->k[0]*udata->p[2]*udata->w[3];
  J->data[102] = -udata->p[3];
  J->data[103] = udata->p[3]*2.0;
  J->data[104] = -udata->p[3];
  J->data[105] = udata->p[3];
  J->data[106] = -udata->p[3];
  J->data[107] = udata->p[3];
  J->data[108] = -udata->p[3];
  J->data[109] = udata->p[3];
  J->data[110] = -udata->p[3];
  J->data[111] = udata->p[3];
  J->data[112] = udata->k[1]*udata->p[3]*udata->w[2];
  J->data[113] = -udata->p[3];
  J->data[114] = -udata->p[0]*udata->w[0];
  J->data[115] = udata->p[0]*udata->w[0];
  J->data[116] = udata->p[1]*x_tmp[1]*-4.0;
  J->data[117] = udata->p[1]*x_tmp[1]*2.0;
  J->data[118] = -udata->p[2];
  J->data[119] = udata->k[0]*udata->p[2]*udata->w[3];
  J->data[120] = -udata->p[3];
  J->data[121] = udata->p[3]*2.0;
  J->data[122] = -udata->p[3];
  J->data[123] = udata->p[3];
  J->data[124] = -udata->p[3];
  J->data[125] = udata->p[3];
  J->data[126] = -udata->p[3];
  J->data[127] = udata->p[3];
  J->data[128] = -udata->p[3];
  J->data[129] = udata->p[3];
  J->data[130] = udata->k[1]*udata->p[3]*udata->w[2];
  J->data[131] = -udata->p[3];
  J->data[132] = -udata->p[0]*udata->w[0];
  J->data[133] = udata->p[0]*udata->w[0];
  J->data[134] = udata->p[1]*x_tmp[1]*-4.0;
  J->data[135] = udata->p[1]*x_tmp[1]*2.0;
  J->data[136] = -udata->p[2];
  J->data[137] = udata->k[0]*udata->p[2]*udata->w[3];
  J->data[138] = -udata->p[3];
  J->data[139] = udata->p[3]*2.0;
  J->data[140] = -udata->p[3];
  J->data[141] = udata->p[3];
  J->data[142] = -udata->p[3];
  J->data[143] = udata->p[3];
  J->data[144] = -udata->p[3];
  J->data[145] = udata->p[3];
  J->data[146] = -udata->p[3];
  J->data[147] = udata->p[3];
  J->data[148] = udata->k[1]*udata->p[3]*udata->w[2];
  J->data[149] = -udata->p[3];
  J->data[150] = -udata->p[0]*udata->w[0];
  J->data[151] = udata->p[0]*udata->w[0];
  J->data[152] = udata->p[1]*x_tmp[1]*-4.0;
  J->data[153] = udata->p[1]*x_tmp[1]*2.0;
  J->data[154] = -udata->p[2];
  J->data[155] = udata->k[0]*udata->p[2]*udata->w[3];
  J->data[156] = -udata->p[3];
  J->data[157] = udata->p[3]*2.0;
  J->data[158] = -udata->p[3];
  J->data[159] = udata->p[3];
  J->data[160] = -udata->p[3];
  J->data[161] = udata->p[3];
  J->data[162] = -udata->p[3];
  J->data[163] = udata->p[3];
  J->data[164] = -udata->p[3];
  J->data[165] = udata->p[3];
  J->data[166] = udata->k[1]*udata->p[3]*udata->w[2];
  J->data[167] = -udata->p[3];
  J->data[168] = -udata->p[0]*udata->w[0];
  J->data[169] = udata->p[0]*udata->w[0];
  J->data[170] = udata->p[1]*x_tmp[1]*-4.0;
  J->data[171] = udata->p[1]*x_tmp[1]*2.0;
  J->data[172] = -udata->p[2];
  J->data[173] = udata->k[0]*udata->p[2]*udata->w[3];
  J->data[174] = -udata->p[3];
  J->data[175] = udata->p[3]*2.0;
  J->data[176] = -udata->p[3];
  J->data[177] = udata->p[3];
  J->data[178] = -udata->p[3];
  J->data[179] = udata->p[3];
  J->data[180] = -udata->p[3];
  J->data[181] = udata->p[3];
  J->data[182] = -udata->p[3];
  J->data[183] = udata->p[3];
  J->data[184] = udata->k[1]*udata->p[3]*udata->w[2];
  J->data[185] = -udata->p[3];
  J->data[186] = -udata->p[0]*udata->w[0];
  J->data[187] = udata->p[0]*udata->w[0];
  J->data[188] = udata->p[1]*x_tmp[1]*-4.0;
  J->data[189] = udata->p[1]*x_tmp[1]*2.0;
  J->data[190] = -udata->p[2];
  J->data[191] = udata->k[0]*udata->p[2]*udata->w[3];
  J->data[192] = -udata->p[3];
  J->data[193] = udata->p[3]*2.0;
  J->data[194] = -udata->p[3];
  J->data[195] = udata->p[3];
  J->data[196] = -udata->p[3];
  J->data[197] = udata->p[3];
  J->data[198] = -udata->p[3];
  J->data[199] = udata->p[3];
  J->data[200] = -udata->p[3];
  J->data[201] = udata->p[3];
  J->data[202] = udata->k[1]*udata->p[3]*udata->w[2];
  J->data[203] = -udata->p[3];
  J->data[204] = -udata->p[0]*udata->w[0];
  J->data[205] = udata->p[0]*udata->w[0];
  J->data[206] = udata->p[1]*x_tmp[1]*-4.0;
  J->data[207] = udata->p[1]*x_tmp[1]*2.0;
  J->data[208] = -udata->p[2];
  J->data[209] = udata->k[0]*udata->p[2]*udata->w[3];
  J->data[210] = -udata->p[3];
  J->data[211] = udata->p[3]*2.0;
  J->data[212] = -udata->p[3];
  J->data[213] = udata->p[3];
  J->data[214] = -udata->p[3];
  J->data[215] = udata->p[3];
  J->data[216] = -udata->p[3];
  J->data[217] = udata->p[3];
  J->data[218] = -udata->p[3];
  J->data[219] = udata->p[3];
  J->data[220] = udata->k[1]*udata->p[3]*udata->w[2];
  J->data[221] = -udata->p[3];
  J->data[222] = -udata->p[0]*udata->w[0];
  J->data[223] = udata->p[0]*udata->w[0];
  J->data[224] = udata->p[1]*x_tmp[1]*-4.0;
  J->data[225] = udata->p[1]*x_tmp[1]*2.0;
  J->data[226] = -udata->p[2];
  J->data[227] = udata->k[0]*udata->p[2]*udata->w[3];
  J->data[228] = -udata->p[3];
  J->data[229] = udata->p[3]*2.0;
  J->data[230] = -udata->p[3];
  J->data[231] = udata->p[3];
  J->data[232] = -udata->p[3];
  J->data[233] = udata->p[3];
  J->data[234] = -udata->p[3];
  J->data[235] = udata->p[3];
  J->data[236] = -udata->p[3];
  J->data[237] = udata->p[3];
  J->data[238] = udata->k[1]*udata->p[3]*udata->w[2];
  J->data[239] = -udata->p[3];
  J->data[240] = -udata->p[0]*udata->w[0];
  J->data[241] = udata->p[0]*udata->w[0];
  J->data[242] = udata->p[1]*x_tmp[1]*-4.0;
  J->data[243] = udata->p[1]*x_tmp[1]*2.0;
  J->data[244] = -udata->p[2];
  J->data[245] = udata->k[0]*udata->p[2]*udata->w[3];
  J->data[246] = -udata->p[3];
  J->data[247] = udata->p[3]*2.0;
  J->data[248] = -udata->p[3];
  J->data[249] = udata->p[3];
  J->data[250] = -udata->p[3];
  J->data[251] = udata->p[3];
  J->data[252] = -udata->p[3];
  J->data[253] = udata->p[3];
  J->data[254] = -udata->p[3];
  J->data[255] = udata->p[3];
  J->data[256] = udata->k[1]*udata->p[3]*udata->w[2];
  J->data[257] = -udata->p[3];
  J->data[258] = -udata->p[0]*udata->w[0];
  J->data[259] = udata->p[0]*udata->w[0];
  J->data[260] = udata->p[1]*x_tmp[1]*-4.0;
  J->data[261] = udata->p[1]*x_tmp[1]*2.0;
  J->data[262] = -udata->p[2];
  J->data[263] = udata->k[0]*udata->p[2]*udata->w[3];
  J->data[264] = -udata->p[3];
  J->data[265] = udata->p[3]*2.0;
  J->data[266] = -udata->p[3];
  J->data[267] = udata->p[3];
  J->data[268] = -udata->p[3];
  J->data[269] = udata->p[3];
  J->data[270] = -udata->p[3];
  J->data[271] = udata->p[3];
  J->data[272] = -udata->p[3];
  J->data[273] = udata->p[3];
  J->data[274] = udata->k[1]*udata->p[3]*udata->w[2];
  J->data[275] = -udata->p[3];
  J->data[276] = -udata->p[0]*udata->w[0];
  J->data[277] = udata->p[0]*udata->w[0];
  J->data[278] = udata->p[1]*x_tmp[1]*-4.0;
  J->data[279] = udata->p[1]*x_tmp[1]*2.0;
  J->data[280] = -udata->p[2];
  J->data[281] = udata->k[0]*udata->p[2]*udata->w[3];
  J->data[282] = -udata->p[3];
  J->data[283] = udata->p[3]*2.0;
  J->data[284] = -udata->p[3];
  J->data[285] = udata->p[3];
  J->data[286] = -udata->p[3];
  J->data[287] = udata->p[3];
  J->data[288] = -udata->p[3];
  J->data[289] = udata->p[3];
  J->data[290] = -udata->p[3];
  J->data[291] = udata->p[3];
  J->data[292] = udata->k[1]*udata->p[3]*udata->w[2];
  J->data[293] = -udata->p[3];
  J->data[294] = -udata->p[0]*udata->w[0];
  J->data[295] = udata->p[0]*udata->w[0];
  J->data[296] = udata->p[1]*x_tmp[1]*-4.0;
  J->data[297] = udata->p[1]*x_tmp[1]*2.0;
  J->data[298] = -udata->p[2];
  J->data[299] = udata->k[0]*udata->p[2]*udata->w[3];
  J->data[300] = -udata->p[3];
  J->data[301] = udata->p[3]*2.0;
  J->data[302] = -udata->p[3];
  J->data[303] = udata->p[3];
  J->data[304] = -udata->p[3];
  J->data[305] = udata->p[3];
  J->data[306] = -udata->p[3];
  J->data[307] = udata->p[3];
  J->data[308] = -udata->p[3];
  J->data[309] = udata->p[3];
  J->data[310] = udata->k[1]*udata->p[3]*udata->w[2];
  J->data[311] = -udata->p[3];
  J->data[312] = -udata->p[0]*udata->w[0];
  J->data[313] = udata->p[0]*udata->w[0];
  J->data[314] = udata->p[1]*x_tmp[1]*-4.0;
  J->data[315] = udata->p[1]*x_tmp[1]*2.0;
  J->data[316] = -udata->p[2];
  J->data[317] = udata->k[0]*udata->p[2]*udata->w[3];
  J->data[318] = -udata->p[3];
  J->data[319] = udata->p[3]*2.0;
  J->data[320] = -udata->p[3];
  J->data[321] = udata->p[3];
  J->data[322] = -udata->p[3];
  J->data[323] = udata->p[3];
  J->data[324] = -udata->p[3];
  J->data[325] = udata->p[3];
  J->data[326] = -udata->p[3];
  J->data[327] = udata->p[3];
  J->data[328] = udata->k[1]*udata->p[3]*udata->w[2];
  J->data[329] = -udata->p[3];
  J->data[330] = -udata->p[0]*udata->w[0];
  J->data[331] = udata->p[0]*udata->w[0];
  J->data[332] = udata->p[1]*x_tmp[1]*-4.0;
  J->data[333] = udata->p[1]*x_tmp[1]*2.0;
  J->data[334] = -udata->p[2];
  J->data[335] = udata->k[0]*udata->p[2]*udata->w[3];
  J->data[336] = -udata->p[3];
  J->data[337] = udata->p[3]*2.0;
  J->data[338] = -udata->p[3];
  J->data[339] = udata->p[3];
  J->data[340] = -udata->p[3];
  J->data[341] = udata->p[3];
  J->data[342] = -udata->p[3];
  J->data[343] = udata->p[3];
  J->data[344] = -udata->p[3];
  J->data[345] = udata->p[3];
  J->data[346] = udata->k[1]*udata->p[3]*udata->w[2];
  J->data[347] = -udata->p[3];
  J->data[348] = -udata->p[0]*udata->w[0];
  J->data[349] = udata->p[0]*udata->w[0];
  J->data[350] = udata->p[1]*x_tmp[1]*-4.0;
  J->data[351] = udata->p[1]*x_tmp[1]*2.0;
  J->data[352] = -udata->p[2];
  J->data[353] = udata->k[0]*udata->p[2]*udata->w[3];
  J->data[354] = -udata->p[3];
  J->data[355] = udata->p[3]*2.0;
  J->data[356] = -udata->p[3];
  J->data[357] = udata->p[3];
  J->data[358] = -udata->p[3];
  J->data[359] = udata->p[3];
  J->data[360] = -udata->p[3];
  J->data[361] = udata->p[3];
  J->data[362] = -udata->p[3];
  J->data[363] = udata->p[3];
  J->data[364] = udata->k[1]*udata->p[3]*udata->w[2];
  J->data[365] = -udata->p[3];
  J->data[366] = -udata->p[0]*udata->w[0];
  J->data[367] = udata->p[0]*udata->w[0];
  J->data[368] = udata->p[1]*x_tmp[1]*-4.0;
  J->data[369] = udata->p[1]*x_tmp[1]*2.0;
  J->data[370] = -udata->p[2];
  J->data[371] = udata->k[0]*udata->p[2]*udata->w[3];
  J->data[372] = -udata->p[3];
  J->data[373] = udata->p[3]*2.0;
  J->data[374] = -udata->p[3];
  J->data[375] = udata->p[3];
  J->data[376] = -udata->p[3];
  J->data[377] = udata->p[3];
  J->data[378] = -udata->p[3];
  J->data[379] = udata->p[3];
  J->data[380] = -udata->p[3];
  J->data[381] = udata->p[3];
  J->data[382] = udata->k[1]*udata->p[3]*udata->w[2];
  J->data[383] = -udata->p[3];
for(inz = 0; inz<384; inz++) {
   if(amiIsNaN(J->data[inz])) {
       J->data[inz] = 0;
       if(!udata->nan_JSparse) {
           warnMsgIdAndTxt("AMICI:mex:fJ:NaN","AMICI replaced a NaN value in Jacobian and replaced it by 0.0. This will not be reported again for this simulation run.");
           udata->nan_JSparse = TRUE;
       }
   }
   if(amiIsInf(J->data[inz])) {
       warnMsgIdAndTxt("AMICI:mex:fJ:Inf","AMICI encountered an Inf value in Jacobian! Aborting simulation ... ");
       return(-1);
   }
}
return(status);

}


