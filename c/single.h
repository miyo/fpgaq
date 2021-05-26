#ifndef __SINGLE_H__
#define __SINGLE_H__

#include <complex.h>

void single_qubit_gate(int k, double complex U[4], double complex *psi, int dim);
void X(double complex *U);
void Z(double complex *U);
void Y(double complex *U);
void H(double complex *U);

#endif /* __SINGLE_H__ */
