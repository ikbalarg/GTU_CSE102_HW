#include <stdio.h>
#include <math.h>
#include "util.h"
void leap_year(int year){
    if(year%400==0){
        printf("%d is a leap year\n",year);
    }
    else if(year%4==0 && year%100!=0){
        printf("%d is a leap year\n",year);
    }
    else{
        printf("%d is not a leap year\n",year);
    }
}
void enhanced_calculator(){
    char operation, format;
    int mV, nV, firstOperand, secondOperand, sonuc;
    printf("Enter the format of output (S or I): ");
    scanf(" %c", &format);
    if (format == 'S') { //this block is not finished yet
        printf("\nEnter m and n values: ");
        scanf("%d %d", &mV, &nV);
        printf("\nEnter the operation (+, -, /, *, !, ^, %%): ");
        scanf(" %c", &operation);
        if (operation == '!') {
            printf("\nEnter the operand: ");
            scanf("%d", &firstOperand);
            // Factorial
            int num1 = 1, memory = firstOperand;
            if (memory == 0) {
                num1 = 1;
            } else {
                while (memory > 0) {
                    num1 = num1 * memory;
                    memory = memory - 1;
                }
            }
            sonuc = num1;
            if (format == 'I') {
                printf("%d!= %d",firstOperand,sonuc);
            } else if (format == 'S') {
                printf("%d!= %d",firstOperand,sonuc);
            } else {
                printf("Invalid format input");
            }
        } else if (operation == '+') {
            printf("Enter the first operand: ");
            scanf("%d", &firstOperand);
            printf("\nEnter the second operand: ");
            scanf("%d", &secondOperand);
            sonuc = firstOperand + secondOperand;
            if (format == 'I') {
                printf("%d+%d= %d",firstOperand,secondOperand,sonuc);
            } else if (format == 'S') {
                printf("%d+%d= %d",firstOperand,secondOperand,sonuc);
            } else {
                printf("Invalid format input");
            }
        } else if (operation == '-') {
            printf("Enter the first operand: ");
            scanf("%d", &firstOperand);
            printf("\nEnter the second operand: ");
            scanf("%d", &secondOperand);
            sonuc = firstOperand - secondOperand;
            if (format == 'I') {
                printf("%d-%d= %d",firstOperand,secondOperand,sonuc);
            } else if (format == 'S') {
                printf("%d-%d= %d",firstOperand,secondOperand,sonuc);
            } else {
                printf("Invalid format input");
            }
        } else if (operation == '*') {
            printf("Enter the first operand: ");
            scanf("%d", &firstOperand);
            printf("\nEnter the second operand: ");
            scanf("%d", &secondOperand);
            sonuc = firstOperand * secondOperand;
            if (format == 'I') {
                printf("%dx%d= %d",firstOperand,secondOperand,sonuc);
            } else if (format == 'S') {
                printf("%dx%d= %d",firstOperand,secondOperand,sonuc);
            } else {
                printf("Invalid format input");
            }
        } else if (operation == '/') {
            printf("Enter the first operand: ");
            scanf("%d", &firstOperand);
            printf("\nEnter the second operand: ");
            scanf("%d", &secondOperand);
            float sonuc;
            sonuc = firstOperand / secondOperand;
            if (format == 'I') {
                printf("%d/%d= %.1f",firstOperand,secondOperand,sonuc);
            } else if (format == 'S') {
                printf("%d/%d= %.1f",firstOperand,secondOperand,sonuc);
            } else {
                printf("Invalid format input");
            }
        } else if (operation == '%') {
            printf("Enter the first operand: ");
            scanf("%d", &firstOperand);
            printf("\nEnter the second operand: ");
            scanf("%d", &secondOperand);
            sonuc = firstOperand % secondOperand;
            if (format == 'I') {
                printf("%d %% %d= %d",firstOperand,secondOperand,sonuc);
            } else if (format == 'S') {
                printf("%d %% %d= %d",firstOperand,secondOperand,sonuc);
            } else {
                printf("Invalid format input");
            }
        } else if (operation == '^') {
            printf("Enter the first operand: ");
            scanf("%d", &firstOperand);
            printf("\nEnter the second operand: ");
            scanf("%d", &secondOperand);
            sonuc = pow(firstOperand, secondOperand);
            if (format == 'I') {
                printf("%d^%d= %d",firstOperand,secondOperand,sonuc);
            } else if (format == 'S') {
                printf("%d^%d= %d",firstOperand,secondOperand,sonuc);
            } else {
                printf("Invalid format input");
            }
        } else {
            printf("Invalid input");
        }
    }
    else if (format == 'I') {
        printf("\nEnter the operation (+, -, /, *, !, ^, %%): ");
        scanf(" %c", &operation);
        if (operation == '!') {
            printf("\nEnter the operand: ");
            scanf("%d", &firstOperand);
            // Factorial
            int num1 = 1, memory = firstOperand;
            if (memory == 0) {
                num1 = 1;
            } else {
                while (memory > 0) {
                    num1 = num1 * memory;
                    memory = memory - 1;
                }
            }
            sonuc = num1;
            printf("%d!= %d",firstOperand,sonuc);
        } else if (operation == '+') {
            printf("Enter the first operand: ");
            scanf("%d", &firstOperand);
            printf("\nEnter the second operand: ");
            scanf("%d", &secondOperand);
            sonuc = firstOperand + secondOperand;
            printf("%d + %d= %d",firstOperand,secondOperand,sonuc);
        } else if (operation == '-') {
            printf("Enter the first operand: ");
            scanf("%d", &firstOperand);
            printf("\nEnter the second operand: ");
            scanf("%d", &secondOperand);
            sonuc = firstOperand - secondOperand;
            printf("%d - %d= %d",firstOperand,secondOperand,sonuc);
        } else if (operation == '*') {
            printf("Enter the first operand: ");
            scanf("%d", &firstOperand);
            printf("\nEnter the second operand: ");
            scanf("%d", &secondOperand);
            sonuc = firstOperand * secondOperand;
            printf("%d x %d= %d",firstOperand,secondOperand,sonuc);
        } else if (operation == '/') {
            printf("Enter the first operand: ");
            scanf("%d", &firstOperand);
            printf("\nEnter the second operand: ");
            scanf("%d", &secondOperand);
            float sonuc;
            sonuc = firstOperand / secondOperand;
            printf("%d / %d= %.1f",firstOperand,secondOperand,sonuc);
        } else if (operation == '%') {
            printf("Enter the first operand: ");
            scanf("%d", &firstOperand);
            printf("\nEnter the second operand: ");
            scanf("%d", &secondOperand);
            sonuc = firstOperand % secondOperand;
            printf("%d %% %d= %d",firstOperand,secondOperand,sonuc);
        } else if (operation == '^') {
            printf("Enter the first operand: ");
            scanf("%d", &firstOperand);
            printf("\nEnter the second operand: ");
            scanf("%d", &secondOperand);
            sonuc = pow(firstOperand, secondOperand);
            printf("%d ^ %d= %d",firstOperand,secondOperand,sonuc);}
    }
}

void grade_calculator(){
    int ex1,ex2,ex3,hw1,hw2;
    float final_grade;
    printf("Enter 3 exam grades of student : ");
    scanf("%d %d %d",&ex1,&ex2,&ex3);
    printf("\nEnter 2 assignment grades of student : ");
    scanf("%d %d",&hw1,&hw2);
    printf("\n");
    final_grade=(ex1+ex2+ex3)/3*0.6+(hw1+hw2)/2*0.4;
    if(final_grade<60){
        printf("Final grade: %.1f Failed!\n",final_grade);
    }
    else{
        printf("Final grade: %.1f Passed!\n",final_grade);
    }
}
