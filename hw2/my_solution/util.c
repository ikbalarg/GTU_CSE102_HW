#include <stdio.h>
#include <math.h>
#include <stdlib.h>
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
void enhanced_calculator2(){
    char operation,format;
    int mValue,nValue,firstOperand,secondOperand,result;
    float resultDiv;
    printf("Enter the format of output (S or I): ");
    scanf(" %c", &format);
    //printf("%d",format=='S');
    if(format!='S' && format!='I'){
        printf("Invalid input\n");
    }
    else{
        if(format == 'I'){
            printf("\nEnter the operation (+, -, /, *, !, ^, %%): ");
            scanf(" %c",&operation);
            if(operation!='+'&&operation!='-'&&operation!='/'&&operation!='*'&&operation!='!'&&operation!='^'&&operation!='%'){
                printf("\nInvalid input\n");
            }
            else{
                int checkOperands=1 ;//checks the validity of the operands.
                if(operation=='!'){
                    printf("Enter the first operand: ");
                    if (scanf("%d", &firstOperand)!=1){
                        printf("Invalid input\n");
                        checkOperands=0;
                    }
                        
                }
                else{
                    printf("Enter the first operand: ");
                    if (scanf("%d", &firstOperand)!=1){
                        checkOperands=0;
                    }
                    printf("\nEnter the second operand: ");
                    if (scanf("%d", &secondOperand)!=1){
                        checkOperands=0;
                    }
                }
                if(checkOperands==1){
                    if(operation=='!'){
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
                        result = num1;
                        //printf("\n%d!= %d",firstOperand,result);
                    }
                    else if(operation=='+'){
                        result = firstOperand + secondOperand;
                        //printf("%d+%d= %d",firstOperand,secondOperand,result);
                    }
                    else if(operation=='-'){
                        result = firstOperand - secondOperand;
                        //printf("%d-%d= %d",firstOperand,secondOperand,result);
                    }
                    else if(operation=='*'){
                        result = firstOperand * secondOperand;
                        //printf("%d*%d= %d",firstOperand,secondOperand,result);
                    }
                    else if(operation=='/'){
                        resultDiv = (float) firstOperand / secondOperand;
                        //printf("%f",resultDiv);
                        //printf("%d/%d= %f",firstOperand,secondOperand,result);
                    }
                    else if(operation=='%'){
                        result = firstOperand % secondOperand;
                        //printf("%d%%%d= %d",firstOperand,secondOperand,result);
                    }
                    else if(operation=='^'){
                        result = pow(firstOperand,secondOperand);
                        //printf("%d^%d= %d",firstOperand,secondOperand,result);
                    }
                    if(operation=='!'){
                        printf("%d %c = %d\n",firstOperand,operation,result);
                    }
                    else if(operation=='/'){
                        printf("%d %c %d = %f \n",firstOperand,operation,secondOperand,resultDiv);
                    }
                    else if(operation=='+'||operation=='-'||operation=='*'||operation=='^'||operation=='%'){
                        printf("%d %c %d = %d\n",firstOperand,operation,secondOperand,result);
                    }
                }
                else{
                    printf("Invalid input\n");
                }
               
            }
        }
    }
}
void enhanced_calculator(){
    char operation,format;
    int mValue,nValue,firstOperand,secondOperand,result;
    float resultDiv;
    printf("Enter the format of output (S or I): ");
    scanf(" %c", &format);
    //printf("%d",format=='S');
    if(format!='S' && format!='I'){
        printf("Invalid input\n");
    }
    else{
        int checkMandNValid=1;
        if (format == 'S'){
            printf("Enter m and n values: ");
            if (scanf("%d %d", &mValue,&nValue)!=2){
                checkMandNValid=0;
            }
            else{
                if(nValue>mValue){
                    printf("N cannot be greater than M\n");
                    checkMandNValid=0;
                }
                else{
                    checkMandNValid=1;
                }
            }
        }
        if(checkMandNValid==1){
            printf("\nEnter the operation (+, -, /, *, !, ^, %%): ");
            scanf(" %c",&operation);
            if(operation!='+'&&operation!='-'&&operation!='/'&&operation!='*'&&operation!='!'&&operation!='^'&&operation!='%'){
                printf("\nInvalid input\n");
            }
            else{
                int checkOperands=1 ;//checks the validity of the operands.
                if(operation=='!'){
                    printf("Enter the first operand: ");
                    if (scanf("%d", &firstOperand)!=1){
                        printf("Invalid input\n");
                        checkOperands=0;
                    }
                    
                }
                else{
                    printf("Enter the first operand: ");
                    if (scanf("%d", &firstOperand)!=1){
                        checkOperands=0;
                    }
                    printf("\nEnter the second operand: ");
                    if (scanf("%d", &secondOperand)!=1){
                        checkOperands=0;
                    }
                }
                if(checkOperands==1){
                    switch(operation){
                        int num1 = 1, memory = firstOperand;
                        case '!':
                            // Factorial
                            
                            if (memory == 0) {
                                num1 = 1;
                            } else {
                                while (memory > 0) {
                                    num1 = num1 * memory;
                                    memory = memory - 1;
                                }
                            }
                            result = num1;
                            //printf("\n%d!= %d",firstOperand,result);
                            break;
                        case '+':
                            result = firstOperand + secondOperand;
                            //printf("%d+%d= %d",firstOperand,secondOperand,result);
                            break;
                        case '-':
                            result = firstOperand - secondOperand;
                            //printf("%d-%d= %d",firstOperand,secondOperand,result);
                            break;
                        case '*':
                            result = firstOperand * secondOperand;
                            //printf("%d*%d= %d",firstOperand,secondOperand,result);
                            break;
                        case '/':
                            resultDiv = (float) firstOperand / secondOperand;
                            //printf("%f",resultDiv);
                            //printf("%d/%d= %f",firstOperand,secondOperand,result);
                            break;
                        case '%':
                            result = firstOperand % secondOperand;
                            //printf("%d%%%d= %d",firstOperand,secondOperand,result);
                            break;
                        case '^':
                            result = pow(firstOperand,secondOperand);
                            //printf("%d^%d= %d",firstOperand,secondOperand,result);
                    }
                }
                else{
                    printf("Invalid input\n");
                }
                
            }
            if(format == 'I'){
                if(operation=='!'){
                    printf("%d %c = %d\n",firstOperand,operation,result);
                }
                else if(operation=='/'){
                    printf("%d %c %d = %f \n",firstOperand,operation,secondOperand,resultDiv);
                }
                else if(operation=='+'||operation=='-'||operation=='*'||operation=='^'||operation=='%'){
                    printf("%d %c %d = %d\n",firstOperand,operation,secondOperand,result);
                }
            }
            else if(format == 'S'){
                double rs= result * pow(10, nValue) / pow(10, mValue);
                printf("Expected Output: %0*.*e\n", mValue, nValue, rs);
                printf("Bilimsel blok");
            }
        }
        else{
            printf("Invalid input\n");
        }
        
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
