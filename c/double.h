#ifndef __DOUBLE_H__
#define __DOUBLE_H__

#include <complex.h>

void double_qubit_gate(int k1, int k2, double complex U[16], double complex *psi, int dim);
void CNOT(double complex *U);
void CNOT2(double complex *U);

#endif /* __DOUBLE_H__ */
