#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
    printf("%d//%d", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 + n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 - n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3=n1*n2;
    *d3=d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3=n1*d2;
    *d3=d1*n2;
    fraction_simplify(n3, d3);
} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d) {
    if (*n>=0 & *d>=0){
        int common=1;
        if (*n==*d){
            common=*n;
        }
        else if (*n>*d){
            int i=1;
            while (i<*d+1){
                if (((*n%i)==0)&((*d%i)==0)){
                    common=i;
                }
                i++;
            }
        }
        else if (*n<*d){
            int i=1;
            while (i<*n+1){
                if (((*n%i)==0)&((*d%i)==0)){
                    common=i;
                }
                i++;
            }
        }
        int n1,d1;
        n1=*n/common;
        d1=*d/common;
        *n=n1;
        *d=d1;
    }
    else{
        if(*n<0){
            *n=*n*(-1);
        }
        if(*d<0){
            *d=*d*(-1);
        }
        if (*n>=0 & *d>=0){
            int common=1;
            if (*n==*d){
                common=*n;
            }
            else if (*n>*d){
                int i=1;
                while (i<*d+1){
                    if (((*n%i)==0)&((*d%i)==0)){
                        common=i;
                    }
                    i++;
                }
            }
            else if (*n<*d){
                int i=1;
                while (i<*n+1){
                    if (((*n%i)==0)&((*d%i)==0)){
                        common=i;
                    }
                    i++;
                }
            }
            int n1,d1;
            n1=*n/common;
            d1=*d/common;
            *n=-1*n1;
            *d=d1;
        }
    }
            
    
} /* end fraction_div */
