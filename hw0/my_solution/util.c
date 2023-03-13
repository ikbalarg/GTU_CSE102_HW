#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
    printf("%d//%d", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 + n2*d1; //add two fractional numbers
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 - n2*d1; //subtract two fractional numbers
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3=n1*n2; //multiply two fractional numbers
    *d3=d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3=n1*d2; //divide two fractional numbers
    *d3=d1*n2;
    fraction_simplify(n3, d3);
} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d) { /*Use the Euclidean algorithm and find GCD.*/
    int gcd;
    int remainder,larger_num,smaller_num; /* variables defined*/
    if(*n==0){ /*If the numerator is equal to 0, the GCD value is equal to zero.
    in this case there is a problem when the values are divided by the GCD value.*/
        *n=0; /*Therefore the value of n is set to 0*/
    }
    else{
        if(*n==*d){
            gcd=*n; /*The gcd value is equal to the numerator or denominator if the numbers are equal*/
        }
        else{ // numbers are not equal
            if (*n>*d){ /* large number and small number determined */
                larger_num=*n;
                smaller_num=*d;
            }
            else{ /* large number and small number determined */
                larger_num=*d;
                smaller_num=*n;
            }
            while (1==1){ /*continue the process until break statement*/
                if(larger_num%smaller_num==0){ /*  Check the remainder, if it is equal to zero then this is our gcd count, in this case enter this if block*/
                    gcd=smaller_num;
                    break;
                }
                else{/* If the remainder is not equal to zero, apply the Euclidean algorithm in this else block*/
                    remainder=larger_num%smaller_num; /* Calculate the remainder and store on this variable. We will  assign this number to small number */
                    larger_num=smaller_num;/*Assign the small number to the large number because of the euclidean alghoritm*/
                    smaller_num=remainder; /*Assign the remainder value to the small number because of the euclidean alghoritm */
                }
            }
        }
        *n=*n/gcd; /*simplify the numerator value with GCD*/
        *d=*d/gcd; /*simplify the denominator value with GCD*/
        if(*n>=0 & *d<0){ /* (a/-b) ----> (-a/b) */
            *n=*n*-1;
            *d=*d*-1;}
    }
} /* end fraction_div */
