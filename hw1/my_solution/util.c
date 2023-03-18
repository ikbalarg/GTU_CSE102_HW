#include <stdio.h>
#include "util.h"
void find_gcd(int num1,int num2){
    int remainder,larger_num,smaller_num; /* variables defined*/
    if(num2==num1){
        printf("The gcd is %d\n",num1); // check the equality of the numbers
    }
    else{ // numbers are not equal
        if (num1>num2){ /* large number and small number determined */
            larger_num=num1;
            smaller_num=num2;
        }
        else{ /* large number and small number determined */
            larger_num=num2;
            smaller_num=num1;
        }
        while (1==1){ /*continue the process until break statement*/
            if(larger_num%smaller_num==0){ /*  Check the remainder, if it is equal to zero then this is our gcd count, in this case enter this if block*/
                printf("The GCD is %d\n ",smaller_num); //print gcd number
                break;
            }
            else{/* If the remainder is not equal to zero, apply the Euclidean algorithm in this else block*/
                remainder=larger_num%smaller_num; /* Calculate the remainder and store on this variable. We will  assign this number to small number */
                larger_num=smaller_num;/*Assign the small number to the large number because of the euclidean alghoritm*/
                smaller_num=remainder; /*Assign the remainder value to the small number because of the euclidean alghoritm */
            }
        }
    }

}
void add_function(int num1,int num2){
    int num3; /* Define a new variable.*/
    num3=num2+num1; /* Holds the result of addition*/
    printf("Result:\n\t %5d\n\t %5d\n\t+\n\t-------\n\t %5d\n",num1,num2,num3);
}

void multpily_function(int num1,int num2){
    printf("First number : %d\n",num1);
    printf("Second number : %d\n",num2);
    int ones,tens,hundreds,result;
    int devide,check=0; /* variables created*/
    result=num2*num1; /*Holds the result of multiplication*/
    if (num2>num1){ /*determined the large number */
        int memory;
        check=1;
        memory=num2;
        num2=num1;
        num1=memory;  /* swap n1 to n2,n2 to n1 */
        
        /*     99     swap      122
              122    ------>     99
             x                 x
             -----            ------         */
    }
    if(99<num2 & num2<1000){ /* If the small number has 3 digits*/
        ones=(num2%10);/* The digit in the ones place*/
        hundreds=(num2/100); /*The digit in the hundreds place*/
        tens=(num2-(hundreds*100))/10; /* EX:(325-300)/10 ---> The digit in the tens place*/
        printf("\t%6d\n\t%6d\n    x\n    ----------\n\t  %03d\n\t %03d\n\t%03d\n   +\n    -----------\n\t%3d\n"
               ,num1,num2,(ones*num1),(tens*num1),(hundreds*num1),result);
    }
    else if (num2 >= 10) {  /* If the small number has 2 digits */
        ones = num2 % 10;/* The digit in the ones place*/
        tens = num2 / 10;/* The digit in the tens place*/
        printf("\t    %3d\n\t    %3d\n\tx\n\t--------\n\t   %03d\n", num1, num2, num1 * ones); /* */
        printf("\t  %03d\n", num1 * tens); /*Multiplying the larger number by the number in the tens place of the smaller number */
        printf("\t+\n"); /* "+" symbol printed */
        printf("\t--------\n\t  %4d\n", result); /*line and result printed*/
    } else {  /* If the small number has 1 digit*/
        printf("\t%5d\n\t%5d\n\tx\n\t-------\n\t%5d\n", num1, num2, num1 * num2);
    }
}
void between1to10(int num1){
    if (num1>10 || num1<1){ /* Invalid input zone defined */
        printf("Invalid input\n");
    }
    else if (num1<=5){/*5 and less than 5 input zones defined*/
        printf("The integer you entered is less than or equal to 5\n");
    }
    else if (num1>5){/*Greater than 5 entry zones defined*/
        printf("The integer you entered is greater than 5\n");
    }
}
