/*
 *   FAC - Flexible Atomic Code
 *   Copyright (C) 2001-2015 Ming Feng Gu
 * 
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 * 
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 * 
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MBPT_H_
#define _MBPT_H_

#include "dbase.h"
#include "structure.h"
#include "transition.h"

typedef struct _TR_OPT_{
  int nktr;
  int *ks;
  int naw;
  double *awgrid;
  char tfn[1024];
  int nlow, nup;
  int *low, *up;
} TR_OPT;

typedef struct _MBPT_EFF_ {
  int n, n2;
  int hsize, nbasis, *basis, hsize0;
  IDXARY *idb;
  double *h0, *e0, *heff, *heff0, *neff;
  int *imbpt;
  double *wmbpt;
  /* effective hamilton elements for 1-virtual */
  double **hab1, **hba1;
  /* effective hamilton elements for 2-virtual */
  double **hab, **hba;
} MBPT_EFF;

typedef struct _MBPT_PMA_ {
  double *tma;
  double *rma;
} MBPT_PMA;
  
typedef struct _MBPT_TR_ {
  int m, nsym1;
  int isym0, ndim0;
  IDXARY **idb;
  IDXARY *ids;
  int *isym1, *ndim1;
  MBPT_PMA ***pma;
  //MBPT_EFF **meff;
} MBPT_TR;

typedef struct _CORR_CONFIG_ {
  CONFIG *c;
  int inp, inq, np, nq;
  int ig, ncs, kp, kq;
} CORR_CONFIG;

typedef struct _MBPT_HAM_ {
  int n, n2, n3;
  int *ng, *ng2;
  int isym, dim;
  int ibra, iket;
  double a, b, c;
  double *hab1, *hba1;
  double *hab, *hba;
  double *heff0;
  int hsize0, *basis;
  MBPT_TR *mtr;
} MBPT_HAM;

typedef struct _CONFIG_PAIR_ {
  int k0;
  int k1;
  int m;
} CONFIG_PAIR;

void InitMBPT(void);
int StructureMBPT0(char *fn, double de, double ccut, int n, int *s0, int kmax, 
		   int n1, int *nm, int n2, int *nmp, int n3, int *n3g,
		   int n4, int *n4g, char *gn);
int StructureMBPT1(char *fn, char *fn0, char *fn1,
		   int n, int *s0, int nk, int *nkm, 
		   int n1, int *nm, int n2, int *nmp, int n0,
		   int ncp, int icp, int icpf);
int StructureReadMBPT(char *fn, char *fn2, int nf, char *fn1[], 
		      int nkg, int *kg, int nkg0);
void SetExtraMBPT(int m);
void SetExcMBPT(int nd, int ns, double wd, double ws, char *s);
void SetOptMBPT(int i3rd, int n3, double c, double d, double e, double f);
void SetWarnMBPT(double f, double g);
void SetSymMBPT(int nlev, int *ilev);
void TransitionMBPT(int nk, int *ks, int naw);
void TRTableMBPT(char *fn, int nlow, int *low, int nup, int *up);
int GetAWGridMBPT(double **awgrid);
void UnpackSymStateMBPT(MBPT_EFF **meff, int ms, int *s, int *m);
void UnpackSymStateTR(MBPT_TR *mtr, int ms, int ip, int *s, int *m, int *is);
void SaveTransitionMBPT(MBPT_TR *mtr);
void AdjustAngularZ(MBPT_TR *mtr);
double AngZCutMBPT(void);
void SetOptionMBPT(char *s, char *sp, int ip, double dp);
#endif
