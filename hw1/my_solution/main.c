//
//  main.c
//  
//
//  Created by Muhammet İkbal Arğuç on 7.03.2023.
//

#include <stdio.h>
#include "util.h"
int main() {
    int num1;
    int num2;
    printf("Give first number : \n");
    scanf("%d",&num1);
    printf("Give second number : \n");
    scanf("%d",&num2);
    printf("First Number : %d \nSecond Number : %d\n",num1,num2);
    find_gcd(num1,num2);
    printf("Function that adds two numbers\n");
    printf("Give first number : \n");
    scanf("%d",&num1);
    printf("Give second number : \n");
    scanf("%d",&num2);
    add_function(num1,num2);
    printf("Function multiplying two numbers\n");
    printf("Give first number : \n");
    scanf("%d",&num1);
    printf("Give second number : \n");
    scanf("%d",&num2);
    multpily_function(num1,num2);
    printf("Function that checks the range of the number\n");
    printf("Give first number : \n");
    scanf("%d",&num1);
    between1to10(num1);
}
