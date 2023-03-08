//
//  main.c
//  
//
//  Created by Muhammet İkbal Arğuç on 7.03.2023.
//

#include <stdio.h>
void find_gcd(int num1,int num2);
int main() {
    int num1;
    int num2;
    int check=1;
    while (check!=0){
        printf("Give first number : \n");
        scanf("%d",&num1);
        printf("Give second number : \n");
        scanf("%d",&num2);
        printf("First Number : %d \nSecond Number : %d\n",num1,num2);
        find_gcd(num1,num2);
        printf("\nIf you want to continue press any numerical key except 0...\n");
        scanf("%d",&check);
    }
    /* Find GCD */
    //find_gcd(num1,num2);
    
}
void find_gcd(int num1,int num2){
    int remainder,larger_num,smaller_num; /* variables defined*/
    if(num2==num1){
        printf("The gcd is %d",num1); // check the equality of the numbers
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
                printf("The GCD is %d ",smaller_num); //print gcd number
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
