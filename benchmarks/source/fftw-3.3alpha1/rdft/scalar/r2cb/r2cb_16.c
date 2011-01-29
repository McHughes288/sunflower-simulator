/*
 * Copyright (c) 2003, 2007-8 Matteo Frigo
 * Copyright (c) 2003, 2007-8 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Sat Nov 15 21:05:49 EST 2008 */

#include "codelet-rdft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_r2cb -fma -reorder-insns -schedule-for-pipeline -compact -variables 4 -pipeline-latency 4 -sign 1 -n 16 -name r2cb_16 -include r2cb.h */

/*
 * This function contains 58 FP additions, 32 FP multiplications,
 * (or, 26 additions, 0 multiplications, 32 fused multiply/add),
 * 47 stack variables, 4 constants, and 32 memory accesses
 */
#include "r2cb.h"

static void r2cb_16(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP1_847759065, +1.847759065022573512256366378793576573644833252);
     DK(KP414213562, +0.414213562373095048801688724209698078569671875);
     DK(KP1_414213562, +1.414213562373095048801688724209698078569671875);
     DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     INT i;
     for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs, Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(rs), MAKE_VOLATILE_STRIDE(csr), MAKE_VOLATILE_STRIDE(csi)) {
	  E TN, TS, TF, TI;
	  {
	       E T8, TD, Tj, TL, T5, TM, TE, To, Td, Tq, Tc, TP, Ty, Te, Tr;
	       E Ts;
	       {
		    E T4, Ti, T1, T2;
		    T4 = Cr[WS(csr, 4)];
		    Ti = Ci[WS(csi, 4)];
		    T1 = Cr[0];
		    T2 = Cr[WS(csr, 8)];
		    {
			 E Tk, Tn, T6, T7;
			 T6 = Cr[WS(csr, 2)];
			 T7 = Cr[WS(csr, 6)];
			 {
			      E Tl, Th, T3, Tm;
			      Tl = Ci[WS(csi, 2)];
			      Th = T1 - T2;
			      T3 = T1 + T2;
			      Tk = T6 - T7;
			      T8 = T6 + T7;
			      Tm = Ci[WS(csi, 6)];
			      TD = FMA(KP2_000000000, Ti, Th);
			      Tj = FNMS(KP2_000000000, Ti, Th);
			      TL = FNMS(KP2_000000000, T4, T3);
			      T5 = FMA(KP2_000000000, T4, T3);
			      Tn = Tl + Tm;
			      TM = Tl - Tm;
			 }
			 {
			      E Ta, Tb, Tw, Tx;
			      Ta = Cr[WS(csr, 1)];
			      TE = Tk + Tn;
			      To = Tk - Tn;
			      Tb = Cr[WS(csr, 7)];
			      Tw = Ci[WS(csi, 1)];
			      Tx = Ci[WS(csi, 7)];
			      Td = Cr[WS(csr, 5)];
			      Tq = Ta - Tb;
			      Tc = Ta + Tb;
			      TP = Tw - Tx;
			      Ty = Tw + Tx;
			      Te = Cr[WS(csr, 3)];
			      Tr = Ci[WS(csi, 5)];
			      Ts = Ci[WS(csi, 3)];
			 }
		    }
	       }
	       {
		    E TV, TG, TW, TH, TB, Tp, TA, TC, TJ, TK;
		    {
			 E T9, Tz, Tg, Tu, TT, TU, TO, TR;
			 TV = FNMS(KP2_000000000, T8, T5);
			 T9 = FMA(KP2_000000000, T8, T5);
			 {
			      E Tv, Tf, TQ, Tt;
			      Tv = Td - Te;
			      Tf = Td + Te;
			      TQ = Tr - Ts;
			      Tt = Tr + Ts;
			      TG = Ty - Tv;
			      Tz = Tv + Ty;
			      TO = Tc - Tf;
			      Tg = Tc + Tf;
			      TW = TQ + TP;
			      TR = TP - TQ;
			      TH = Tq + Tt;
			      Tu = Tq - Tt;
			 }
			 TN = FNMS(KP2_000000000, TM, TL);
			 TT = FMA(KP2_000000000, TM, TL);
			 TU = TO + TR;
			 TS = TO - TR;
			 R0[0] = FMA(KP2_000000000, Tg, T9);
			 R0[WS(rs, 4)] = FNMS(KP2_000000000, Tg, T9);
			 R0[WS(rs, 7)] = FMA(KP1_414213562, TU, TT);
			 R0[WS(rs, 3)] = FNMS(KP1_414213562, TU, TT);
			 TB = FNMS(KP1_414213562, To, Tj);
			 Tp = FMA(KP1_414213562, To, Tj);
			 TA = FNMS(KP414213562, Tz, Tu);
			 TC = FMA(KP414213562, Tu, Tz);
		    }
		    R0[WS(rs, 6)] = FMA(KP2_000000000, TW, TV);
		    R0[WS(rs, 2)] = FNMS(KP2_000000000, TW, TV);
		    R1[0] = FMA(KP1_847759065, TA, Tp);
		    R1[WS(rs, 4)] = FNMS(KP1_847759065, TA, Tp);
		    TF = FNMS(KP1_414213562, TE, TD);
		    TJ = FMA(KP1_414213562, TE, TD);
		    TK = FMA(KP414213562, TG, TH);
		    TI = FNMS(KP414213562, TH, TG);
		    R1[WS(rs, 6)] = FMA(KP1_847759065, TC, TB);
		    R1[WS(rs, 2)] = FNMS(KP1_847759065, TC, TB);
		    R1[WS(rs, 7)] = FMA(KP1_847759065, TK, TJ);
		    R1[WS(rs, 3)] = FNMS(KP1_847759065, TK, TJ);
	       }
	  }
	  R0[WS(rs, 1)] = FMA(KP1_414213562, TS, TN);
	  R0[WS(rs, 5)] = FNMS(KP1_414213562, TS, TN);
	  R1[WS(rs, 5)] = FMA(KP1_847759065, TI, TF);
	  R1[WS(rs, 1)] = FNMS(KP1_847759065, TI, TF);
     }
}

static const kr2c_desc desc = { 16, "r2cb_16", {26, 0, 32, 0}, &GENUS };

void X(codelet_r2cb_16) (planner *p) {
     X(kr2c_register) (p, r2cb_16, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_r2cb -compact -variables 4 -pipeline-latency 4 -sign 1 -n 16 -name r2cb_16 -include r2cb.h */

/*
 * This function contains 58 FP additions, 18 FP multiplications,
 * (or, 54 additions, 14 multiplications, 4 fused multiply/add),
 * 31 stack variables, 4 constants, and 32 memory accesses
 */
#include "r2cb.h"

static void r2cb_16(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP1_847759065, +1.847759065022573512256366378793576573644833252);
     DK(KP765366864, +0.765366864730179543456919968060797733522689125);
     DK(KP1_414213562, +1.414213562373095048801688724209698078569671875);
     DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     INT i;
     for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs, Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(rs), MAKE_VOLATILE_STRIDE(csr), MAKE_VOLATILE_STRIDE(csi)) {
	  E T9, TS, Tl, TG, T6, TR, Ti, TD, Td, Tq, Tg, Tt, Tn, Tu, TV;
	  E TU, TN, TK;
	  {
	       E T7, T8, TE, Tj, Tk, TF;
	       T7 = Cr[WS(csr, 2)];
	       T8 = Cr[WS(csr, 6)];
	       TE = T7 - T8;
	       Tj = Ci[WS(csi, 2)];
	       Tk = Ci[WS(csi, 6)];
	       TF = Tj + Tk;
	       T9 = KP2_000000000 * (T7 + T8);
	       TS = KP1_414213562 * (TE + TF);
	       Tl = KP2_000000000 * (Tj - Tk);
	       TG = KP1_414213562 * (TE - TF);
	  }
	  {
	       E T5, TC, T3, TA;
	       {
		    E T4, TB, T1, T2;
		    T4 = Cr[WS(csr, 4)];
		    T5 = KP2_000000000 * T4;
		    TB = Ci[WS(csi, 4)];
		    TC = KP2_000000000 * TB;
		    T1 = Cr[0];
		    T2 = Cr[WS(csr, 8)];
		    T3 = T1 + T2;
		    TA = T1 - T2;
	       }
	       T6 = T3 + T5;
	       TR = TA + TC;
	       Ti = T3 - T5;
	       TD = TA - TC;
	  }
	  {
	       E TI, TM, TL, TJ;
	       {
		    E Tb, Tc, To, Tp;
		    Tb = Cr[WS(csr, 1)];
		    Tc = Cr[WS(csr, 7)];
		    Td = Tb + Tc;
		    TI = Tb - Tc;
		    To = Ci[WS(csi, 1)];
		    Tp = Ci[WS(csi, 7)];
		    Tq = To - Tp;
		    TM = To + Tp;
	       }
	       {
		    E Te, Tf, Tr, Ts;
		    Te = Cr[WS(csr, 5)];
		    Tf = Cr[WS(csr, 3)];
		    Tg = Te + Tf;
		    TL = Te - Tf;
		    Tr = Ci[WS(csi, 5)];
		    Ts = Ci[WS(csi, 3)];
		    Tt = Tr - Ts;
		    TJ = Tr + Ts;
	       }
	       Tn = Td - Tg;
	       Tu = Tq - Tt;
	       TV = TM - TL;
	       TU = TI + TJ;
	       TN = TL + TM;
	       TK = TI - TJ;
	  }
	  {
	       E Ta, Th, TT, TW;
	       Ta = T6 + T9;
	       Th = KP2_000000000 * (Td + Tg);
	       R0[WS(rs, 4)] = Ta - Th;
	       R0[0] = Ta + Th;
	       TT = TR - TS;
	       TW = FNMS(KP1_847759065, TV, KP765366864 * TU);
	       R1[WS(rs, 5)] = TT - TW;
	       R1[WS(rs, 1)] = TT + TW;
	  }
	  {
	       E TX, TY, Tm, Tv;
	       TX = TR + TS;
	       TY = FMA(KP1_847759065, TU, KP765366864 * TV);
	       R1[WS(rs, 3)] = TX - TY;
	       R1[WS(rs, 7)] = TX + TY;
	       Tm = Ti - Tl;
	       Tv = KP1_414213562 * (Tn - Tu);
	       R0[WS(rs, 5)] = Tm - Tv;
	       R0[WS(rs, 1)] = Tm + Tv;
	  }
	  {
	       E Tw, Tx, TH, TO;
	       Tw = Ti + Tl;
	       Tx = KP1_414213562 * (Tn + Tu);
	       R0[WS(rs, 3)] = Tw - Tx;
	       R0[WS(rs, 7)] = Tw + Tx;
	       TH = TD + TG;
	       TO = FNMS(KP765366864, TN, KP1_847759065 * TK);
	       R1[WS(rs, 4)] = TH - TO;
	       R1[0] = TH + TO;
	  }
	  {
	       E TP, TQ, Ty, Tz;
	       TP = TD - TG;
	       TQ = FMA(KP765366864, TK, KP1_847759065 * TN);
	       R1[WS(rs, 2)] = TP - TQ;
	       R1[WS(rs, 6)] = TP + TQ;
	       Ty = T6 - T9;
	       Tz = KP2_000000000 * (Tt + Tq);
	       R0[WS(rs, 2)] = Ty - Tz;
	       R0[WS(rs, 6)] = Ty + Tz;
	  }
     }
}

static const kr2c_desc desc = { 16, "r2cb_16", {54, 14, 4, 0}, &GENUS };

void X(codelet_r2cb_16) (planner *p) {
     X(kr2c_register) (p, r2cb_16, &desc);
}

#endif				/* HAVE_FMA */