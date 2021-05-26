#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <assert.h>

#include "measurement.h"
#include "single.h"
#include "double.h"

int initialize(int dim, double complex *psi){
    psi[0] = 1 + 0i;
    for(int i = 1; i < dim; i++){
        psi[i] = 0 + 0i;
    }
}

int dump(int dim, double complex *psi){
    for(int i = 0; i < dim; i++){
        printf("%04d %f+%fi\n", i, creal(psi[i]), cimag(psi[i]));
    }
}

int main(int argc, char **argv){
    double complex d[1024];
    double complex U[4];
    
    int num = argc > 1 ? atoi(argv[1]) : 3;
    int i = argc > 2 ? atoi(argv[2]) : 0;

    num = num < 1 ? 1 : num;
    
    int dim = 1 << num;
    dim = dim > 1024 ? 1024 : dim;
    
    printf("--X|0>--\n");
    initialize(dim, d);
    dump(dim, d);
    X(U);
    single_qubit_gate(i, U, d, dim);
    printf("--\n");
    dump(dim, d);

    printf("--Z|0>--\n");
    initialize(dim, d);
    dump(dim, d);
    Z(U);
    single_qubit_gate(i, U, d, dim);
    printf("--\n");
    dump(dim, d);

    printf("--Y|0>--\n");
    initialize(dim, d);
    dump(dim, d);
    Y(U);
    single_qubit_gate(i, U, d, dim);
    printf("--\n");
    dump(dim, d);
    
    printf("--X|1>--\n");
    initialize(dim, d);
    X(U);
    single_qubit_gate(i, U, d, dim);
    dump(dim, d);
    X(U);
    single_qubit_gate(i, U, d, dim);
    printf("--\n");
    dump(dim, d);

    printf("--Z|1>--\n");
    initialize(dim, d);
    X(U);
    single_qubit_gate(i, U, d, dim);
    dump(dim, d);
    Z(U);
    single_qubit_gate(i, U, d, dim);
    printf("--\n");
    dump(dim, d);

    printf("--Y|1>--\n");
    initialize(dim, d);
    X(U);
    single_qubit_gate(i, U, d, dim);
    dump(dim, d);
    Y(U);
    single_qubit_gate(i, U, d, dim);
    printf("--\n");
    dump(dim, d);
    
    printf("--H|0>--\n");
    for(int i = 0; i < 10; i++){
        initialize(dim, d);
        H(U);
        single_qubit_gate(i, U, d, dim);
        int r = measurement(0, d);
        printf("%d ", r);
    }
    printf("\n");

    {
        printf("--CNOT(0<-1) |00> => |00>--\n");
        initialize(4, d); // 2-qubit
        dump(4, d);
        printf("=>\n");
        double complex U1[16];
        CNOT(U1);
        double_qubit_gate(0, 1, U1, d, 4);
        dump(4, d);
    }
    {
        printf("--CNOT(0<-1) |01> => |01>--\n");
        initialize(4, d); // 2-qubit
        X(U);
        single_qubit_gate(0, U, d, 4);
        dump(4, d);
        printf("=>\n");
        double complex U1[16];
        CNOT(U1);
        double_qubit_gate(0, 1, U1, d, 4);
        dump(4, d);
    }
    {
        printf("--CNOT(0<-1) |10> => |11> --\n");
        initialize(4, d); // 2-qubit
        X(U);
        single_qubit_gate(1, U, d, 4);
        dump(4, d);
        printf("=>\n");
        double complex U1[16];
        CNOT(U1);
        double_qubit_gate(0, 1, U1, d, 4);
        dump(4, d);
    }
    {
        printf("--CNOT(0<-1) |11> => |10> --\n");
        initialize(4, d); // 2-qubit
        X(U);
        single_qubit_gate(0, U, d, 4);
        single_qubit_gate(1, U, d, 4);
        dump(4, d);
        printf("=>\n");
        double complex U1[16];
        CNOT(U1);
        double_qubit_gate(0, 1, U1, d, 4);
        dump(4, d);
    }
        
    {
        printf("--CNOT(1<-0) |00> => |00>--\n");
        initialize(4, d); // 2-qubit
        dump(4, d);
        printf("=>\n");
        double complex U1[16];
        CNOT2(U1);
        double_qubit_gate(0, 1, U1, d, 4);
        dump(4, d);
    }
    {
        printf("--CNOT(1<-0) |01> => |11>--\n");
        initialize(4, d); // 2-qubit
        X(U);
        single_qubit_gate(0, U, d, 4);
        dump(4, d);
        printf("=>\n");
        double complex U1[16];
        CNOT2(U1);
        double_qubit_gate(0, 1, U1, d, 4);
        dump(4, d);
    }
    {
        printf("--CNOT(1<-0) |10> => |10> --\n");
        initialize(4, d); // 2-qubit
        X(U);
        single_qubit_gate(1, U, d, 4);
        dump(4, d);
        printf("=>\n");
        double complex U1[16];
        CNOT2(U1);
        double_qubit_gate(0, 1, U1, d, 4);
        dump(4, d);
    }
    {
        printf("--CNOT(1<-0) |11> => |01> --\n");
        initialize(4, d); // 2-qubit
        X(U);
        single_qubit_gate(0, U, d, 4);
        single_qubit_gate(1, U, d, 4);
        dump(4, d);
        printf("=>\n");
        double complex U1[16];
        CNOT2(U1);
        double_qubit_gate(0, 1, U1, d, 4);
        dump(4, d);
    }

    {
        printf("--CNOT(0<-1) |011> => |010> --\n");
        initialize(8, d); // 3-qubit
        X(U);
        single_qubit_gate(0, U, d, 8);
        single_qubit_gate(1, U, d, 8);
        dump(8, d);
        printf("=>\n");
        double complex U1[16];
        CNOT(U1);
        double_qubit_gate(0, 1, U1, d, 8);
        dump(8, d);
    }

    {
        printf("--CNOT(0<-2) |111> => |110> --\n");
        initialize(8, d); // 3-qubit
        X(U);
        single_qubit_gate(0, U, d, 8);
        single_qubit_gate(1, U, d, 8);
        single_qubit_gate(2, U, d, 8);
        dump(8, d);
        printf("=>\n");
        double complex U1[16];
        CNOT(U1);
        double_qubit_gate(0, 2, U1, d, 8);
        dump(8, d);
    }

    {
        printf("--CNOT2(2<-0) |111> => |011> --\n");
        initialize(8, d); // 3-qubit
        X(U);
        single_qubit_gate(0, U, d, 8);
        single_qubit_gate(1, U, d, 8);
        single_qubit_gate(2, U, d, 8);
        dump(8, d);
        printf("=>\n");
        double complex U1[16];
        CNOT2(U1);
        double_qubit_gate(0, 2, U1, d, 8);
        dump(8, d);
    }
    
}
