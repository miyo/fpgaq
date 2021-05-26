#include <stdlib.h>
#include <complex.h>

#include "measurement.h"

int measurement(int k, double complex *psi){
    int result;
    double abs = cabs(psi[k]);
    double rnd = ((double)rand())/RAND_MAX;
    if(rnd < abs*abs){
        result = 0;
        psi[2*k] = 1;
        psi[2*k+1] = 0;
    }else{
        result = 1;
        psi[2*k] = 0;
        psi[2*k+1] = 1;
    }
    return result;
}
