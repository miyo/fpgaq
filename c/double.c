#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#include "double.h"

void double_qubit_gate(int k1, int k2, double complex U[16], double complex *state, int dim) {
    int q1 = 1ULL << k1;
    int q2 = 1ULL << (k2 - 1);
  
    int low_mask = q1 - 1;
    int mid_mask = (q2 - 1) ^ low_mask;
    int high_mask = ~(q2 - 1);

    int m1 = 1ULL << k1;
    int m2 = 1ULL << k2;

    int loop_dim = dim / 4;
  
    for (int i = 0; i < loop_dim; ++i) {
        int b0 = (i & low_mask) + ((i & mid_mask) << 1) + ((i & high_mask) << 2);

        int b1 = b0 + m1;
        int b2 = b0 + m2;
        int b3 = b1 + m2;

        double complex c0 = state[b0];
        double complex c1 = state[b1];
        double complex c2 = state[b2];
        double complex c3 = state[b3];

        state[b0] = U[0] * c0 + U[1] * c1 + U[2] * c2 + U[3] * c3;
        state[b1] = U[4] * c0 + U[5] * c1 + U[6] * c2 + U[7] * c3;
        state[b2] = U[8] * c0 + U[9] * c1 + U[10] * c2 + U[11] * c3;
        state[b3] = U[12] * c0 + U[13] * c1 + U[14] * c2 + U[15] * c3;
#ifdef DEBUG
        printf("%04d %04d %04d %04d %04d\n", i, b0, b1, b2, b3);
#endif
    }
}

void CNOT(double complex *U){
    U[0] = 1;
    U[1] = 0;
    U[2] = 0;
    U[3] = 0;
    
    U[4] = 0;
    U[5] = 1;
    U[6] = 0;
    U[7] = 0;
    
    U[8] = 0;
    U[9] = 0;
    U[10] = 0;
    U[11] = 1;
    
    U[12] = 0;
    U[13] = 0;
    U[14] = 1;
    U[15] = 0;
}

void CNOT2(double complex *U){
    U[0] = 1;
    U[1] = 0;
    U[2] = 0;
    U[3] = 0;
    
    U[4] = 0;
    U[5] = 0;
    U[6] = 0;
    U[7] = 1;
    
    U[8]  = 0;
    U[9]  = 0;
    U[10] = 1;
    U[11] = 0;
    
    U[12] = 0;
    U[13] = 1;
    U[14] = 0;
    U[15] = 0;
}
