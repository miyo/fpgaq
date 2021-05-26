#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#include "single.h"

void single_qubit_gate(int k, double complex U[4], double complex *psi, int dim) {
    const int target_mask = 1ULL << k;
    const int loop_dim = dim/2;
  
    for(int i = 0; i < loop_dim ; i++){
        int temp_basis = (i >> k) << (k+1);
        int basis_0 = temp_basis + i % target_mask;
        int basis_1 = basis_0 ^ target_mask;

        // fetch values
        double complex c0 = psi[basis_0];
        double complex c1 = psi[basis_1];

        // set values
        psi[basis_0] = U[0] * c0 + U[1] * c1;
        psi[basis_1] = U[2] * c0 + U[3] * c1;
    }
}

void X(double complex *U){
    U[0] = 0+0i;
    U[1] = 1+0i;
    U[2] = 1+0i;
    U[3] = 0+0i;
}

void Z(double complex *U){
    U[0] = 1+0i;
    U[1] = 0+0i;
    U[2] = 0+0i;
    U[3] = -1+0i;
}

void Y(double complex *U){
    U[0] = 0+0i;
    U[1] = 0-1i;
    U[2] = 0+1i;
    U[3] = 0+0i;
}

void H(double complex *U){
    double a = 1/sqrt(2);
    U[0] = a*(1+0i);
    U[1] = a*(1-0i);
    U[2] = a*(1+0i);
    U[3] = a*(-1+0i);
}

void rot(double complex *U, double theta){
    U[0] = 1+0i;
    U[1] = 1-0i;
    U[2] = 1+0i;
    U[3] = cos(theta) + 1i * sin(theta);
}
