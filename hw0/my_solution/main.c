#include <stdio.h>
#include "util.h"


int main() {

    /* A fractional number: 13/7 */
    int num1 = 13, den1 = 7;
    /* A second fractional number: 13/11 */
    int num2 = 30, den2 = 11;
    /* An unitilized fractional number */
    int num3, den3;

    printf("First number: ");
    fraction_print(num1, den1);
    printf("\n");

    printf("Second number: ");
    fraction_print(num2, den2);
    printf("\n");

    printf("Addition: ");
    fraction_add(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Subtraction: ");
    fraction_sub(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Multiplication: ");
    fraction_mul(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Division: ");
    fraction_div(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    /*
     TODO: Complete this code to read two fractional numbers and print their 
             multiplication and division results...
    */
    int num4,num5,num6; /* Variables created to store the numerator values*/
    int den4,den5,den6;/* Variables created to store the denominator values.*/
    while (1==1){ /*get new input values from the user until the break statement if the denominator is equal to 0 */
        printf("Give numerator of first fractional number : ");
        scanf("%d",&num4);
        printf("\nGive denominator of first fractional number:  ");
        scanf("%d",&den4);
        printf("\nGive numerator of second fractional number : ");
        scanf("%d",&num5);
        printf("\nGive denominator of second fractional number:  ");
        scanf("%d",&den5);
        if (den4==0 || den5==0){
            printf("\nIncorrect fraction number input, please try again\n\n");
        }
        else{
            break;
        }
    }
    /*Fractional numbers taken from the user. */
    printf("First number: ");
    fraction_print(num4, den4);
    printf("\n");
    /*The first fractional number printed. */
    printf("Second number: ");
    fraction_print(num5, den5);
    printf("\n");
    /*The second fractional number printed. */
    printf("Addition: ");
    fraction_add(num4, den4, num5, den5, &num6, &den6);/*The first and the second fractional numbers are added. Then assigned to the variable that holds the numerator and denominator of the third fraction. */
    fraction_print(num6, den6); /* summed fractional number is printed which taken by the user. */
    printf("\n");

    printf("Subtraction: ");/*The first and the second fractional numbers are subtracted. Then assigned to the variable that holds the numerator and denominator of the third fraction. */
    fraction_sub(num4, den4, num5, den5, &num6, &den6);
    fraction_print(num6, den6);/* subtracted fractional number is printed which taken by the user. */
    printf("\n");

    printf("Multiplication: ");/*The first and the second fractional numbers are multiplied. Then assigned to the variable that holds the numerator and denominator of the third fraction. */
    fraction_mul(num4, den4, num5, den5, &num6, &den6);
    fraction_print(num6, den6);/* multiplied fractional number is printed which taken by the user. */
    printf("\n");

    printf("Division: ");/*The first and the second fractional numbers are divided. Then assigned to the variable that holds the numerator and denominator of the third fraction. */
    fraction_div(num4, den4, num5, den5, &num6, &den6);
    fraction_print(num6, den6);/* The divided fractional number is printed which is taken by the user. */
    printf("\n");
    

    return(0);
}
