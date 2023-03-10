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
    int check=1;
    while (check!=0){
        printf("Give first number : \n");
        scanf("%d",&num1);
        printf("Give second number : \n");
        scanf("%d",&num2);
        printf("First Number : %d \nSecond Number : %d\n",num1,num2);
        //find_gcd(num1,num2);
        //add_function(num1,num2);
        multpily_function(num1,num2);
        printf("\nIf you want to continue press any numerical key except 0...\n");
        scanf("%d",&check);
    }
    /* Find GCD */
    //find_gcd(num1,num2);
    
}
