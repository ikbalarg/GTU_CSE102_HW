#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "util.h"
void calculator(int format,char operation,int firstOperand,int secondOperand,double fOperand,double sOperand,int mValue,int nValue); //If format is equal to 1, it represents the case 'I' and 0 represents the case 'S'. sOperand,fOperand,mValue,nValue --> these variables only work in scientific notation,otherwise they are assigned a trivial value. This value is not used.
//Part1
void leap_year(int year){
    /*The algorithm to determine if a year is a leap year is as follows: Every year that is exactly divisible by four is a leap year, except for years that are exactly divisible by 100, but these centurial years are leap years, if they are exactly divisible by 400. */
    if(year%400==0){ /*If the year is divided by 400, it is a leap year regardless of whether it is divided by 100. */
        printf("%d is a leap year\n",year);
    }
    else if(year%4==0 && year%100!=0){ /* If a year is divided by 4 and not by 100, it is a leap year.*/
        printf("%d is a leap year\n",year);
    }
    else{
        printf("%d is not a leap year\n",year);
    }
}
//Part3.Part 2 is below.
void grade_calculator(){
    int ex1,ex2,ex3,hw1,hw2;/*exams->ex(X) ,homeworks-> hw(X)  */
    float final_grade;
    printf("Enter 3 exam grades of student : ");
    scanf(" %d %d %d",&ex1,&ex2,&ex3);
    if(ex1<0 || ex1>100 || ex2<0 || ex2>100 || ex3<0 || ex3>100){
        //checking the range of numbers
        printf("Invalid input.You can enter a value between 0 and 100. Please try again\n");
    }else{
        printf("\nEnter 2 assignment grades of student : ");
        scanf(" %d %d",&hw1,&hw2);
        printf("\n");
        if(hw1<0 || hw1>100 || hw2<0 || hw2>100){
        //checking the range of numbers
            printf("Invalid input.You can enter a value between 0 and 100. Please try again\n");
        }else{
            final_grade=(ex1+ex2+ex3)/3*0.6+(hw1+hw2)/2*0.4; /*final grade calculated */
            if(final_grade<60){
                printf("Final grade: %.1f Failed!\n",final_grade);
            }
            else{
                printf("Final grade: %.1f Passed!\n",final_grade);
            }
        }
    }
}
//Part2
void enhanced_calculator(){
    char operation,format;
    int mValue,nValue;
    int checkMandNValid1=1;//with this variable the validity of m and n is checked. If not valid, this value becomes 0 and gives an error message.
    float resultDiv;
    printf("Enter the format of output (S or I): ");
    scanf(" %c", &format); //format information received
    //printf("%d",format=='S');
    if(format!='S' && format!='I'){ //checking the validity of the format
        printf("Invalid input\n");
    }
    else{ //if format valid
        int firstOperand,secondOperand; /*these variables are defined for integer format.*/
        double fOperand,sOperand;/*these variables are defined for scientific format */
        switch (format)
        {
        case 'I': /*if format is integer format*/
            printf("\nEnter the operation (+, -, /, *, !, ^, %%): ");
            scanf(" %c",&operation); /*the operation to be taken is taken by the user. */
            if(operation!='+'&&operation!='-'&&operation!='/'&&operation!='*'&&operation!='!'&&operation!='^'&&operation!='%'){ //checking the validity of the operation
                printf("\nInvalid input\n");
            }else{ //if operation valid
                int checkOperands=1 ;//checks the validity of the operands.
                if(operation=='!'){
                    //Since the factorial operation takes only one operand, this operation is kept in a separate block from the others
                    printf("Enter the first operand: ");
                    if (scanf("%d", &firstOperand)!=1){ //checks the validity of the operands.
                        printf("Invalid input\n");
                        checkOperands=0;
                    }else{ //if the operand is valid, call the function that calculates the operation
                        calculator(1,'!',firstOperand,1,0,0,0,0);
                        /*Since the last 4 inputs of the function are related to scientific notation, the value 0 is given as input. These values will not be used in the function*/
                    }
                }
                else{/*if the operation is not a factorial operation */
                    printf("Enter the first operand: ");
                    if (scanf("%d", &firstOperand)!=1){
                        checkOperands=0;
                    } //checks the validity of the operands.
                    printf("\nEnter the second operand: ");
                    if (scanf("%d", &secondOperand)!=1){
                        checkOperands=0;
                    }
                    if(checkOperands==1){ //if the operand is valid, call the function that calculates the operation
                    calculator(1,operation,firstOperand,secondOperand,0,0,0,0);
                    }
                    
                }
                if(checkOperands==0){ //if the control value is 0, the error message is displayed.
                    printf("Invalid Input\n");
                }
            }
            break;
        case 'S': /*if format is scientific format*/
            printf("Enter m and n values: ");
            if (scanf("%d %d", &mValue,&nValue)!=2){ //the validity of m and n is checked.
                checkMandNValid1=0; //if not valid, the control variable is set to 0.
            }
            else{//if valid, the size of m and n are checked
                if(nValue>mValue){
                    printf("N cannot be greater than M\n");
                    checkMandNValid1=0;
                }
                else{
                    checkMandNValid1=1;
                }
            }
            if(checkMandNValid1==0){ // print the error message,if control variable is 0
                printf("Invalid input\n");
            }else if(checkMandNValid1==1){
                printf("\nEnter the operation (+, -, /, *, !, ^, %%): ");
                scanf(" %c",&operation);/*operation variable is retrieved from the user*/
                if(operation!='+'&&operation!='-'&&operation!='/'&&operation!='*'&&operation!='!'&&operation!='^'&&operation!='%'){//validity of the operation variable is checked
                    printf("\nInvalid input\n");
                }else{
                    int checkOperands=1 ;//checks the validity of the operands.
                    if(operation=='!'){
                        //Since the factorial operation takes only one operand, this operation is kept in a separate block from the others
                        printf("Enter the first operand: ");
                        if (scanf("%lf", &fOperand)!=1){//check validity
                            printf("Invalid input\n");
                            checkOperands=0;//control variable set to 0,if not valid
                        }
                    
                    }else{//operations outside factorial
                        printf("Enter the first operand: ");
                        if (scanf("%lf", &fOperand)!=1){//checks validity
                            checkOperands=0;
                        }
                        printf("\nEnter the second operand: ");
                        if (scanf("%lf", &sOperand)!=1){//checks validity
                            checkOperands=0;
                        }
                    }
                    if(checkOperands==0){ // if operands not valid print the error message
                        printf("Invalid Inputs\n");
                    }else if(checkOperands==1){//if the operand is valid, call the function that calculates the operation.
                        if(operation=='!'){
                            calculator(0,'!',1,1,fOperand,sOperand,nValue,mValue);
                        } //Inputs 3 and 4 in the function are assigned values of 1 as they are not needed for this section.
                        else{
                            calculator(0,operation,0,0,fOperand,sOperand,nValue,mValue);
                        }
                    }
                }
            }
            break;
        }
    }
    
}
void calculator(int format,char operation,int firstOperand,int secondOperand,double fOperand,double sOperand,int nValue,int mValue){
    if (format==1){ // if format is integer format
        int result;//result for I format
        float resultDiv;//This variable is defined because the result of the division operation can also be in float
        if(operation=='!'){
            int num1 = 1, memory = firstOperand; //Factorial operation
            if (memory==0){
                num1=1;
                result=1;
            }else{
                while (memory > 0) {
                    num1 = num1 * memory;
                    memory = memory - 1;
                }
                result = num1;
            }
        }else if(operation=='+'){
            result = firstOperand + secondOperand; //addition
        }else if(operation=='-'){
            result = firstOperand - secondOperand; //subtraction
        }else if(operation=='*'){
            result = firstOperand * secondOperand; //multiplication
        }else if(operation=='/'){
            resultDiv = (float) firstOperand / secondOperand; //division.where the result is taken as float.
        }else if(operation=='%'){
            result = firstOperand % secondOperand;//mode operation
        } else if(operation=='^'){
            result = pow(firstOperand,secondOperand); //power operation
        }
        if(operation=='!'){
            printf("%d %c = %d\n",firstOperand,operation,result);
        }else if(operation=='/'){
            printf("%d %c %d = %.2f \n",firstOperand,operation,secondOperand,resultDiv);   //print blocks
        }else if(operation=='+'||operation=='-'||operation=='*'||operation=='^'||operation=='%'){
            printf("%d %c %d = %d\n",firstOperand,operation,secondOperand,result);
        }

    }else{ //if format is scientific format
        double result; //result variable created.
        if(operation=='!'){
            int num1 = 1, memory = (int)fOperand; ////Factorial operation
            if (memory==0){
                num1=1;
            }else{
                while (memory > 0) {
                    num1 = num1 * memory;
                    memory = memory - 1;
                }
                result = num1;
            }
        }else if(operation=='+'){
            result = fOperand + sOperand; //addition
        }else if(operation=='-'){
            result = fOperand - sOperand; //subtraction
        }else if(operation=='*'){
            result = fOperand * sOperand;//multiplication
        }else if(operation=='/'){
            result = fOperand / sOperand; //division
        }else if(operation=='%'){
            result = (int)fOperand % (int)sOperand; //mode operation
        } else if(operation=='^'){
            result = pow(fOperand,sOperand); //power operation
        }
        if(operation=='+'||operation=='-'||operation=='*'||operation=='^'||operation=='%'||operation=='/'||operation=='!'){
            if (operation=='!'){ /*Since there is no second oparand in the factorial, it was handled in a separate block */
                if(nValue==1){  // n=1 m=7, EX: 7.35--> 7 .350000
                    printf("%lf %c = ",fOperand,operation);
                    printf("%.*E\n",mValue-nValue,result);
                }else{
                    printf("%lf %c = ",fOperand,operation);
                    int i;
                    for(i=0;i<mValue-nValue-1;i++){  //Zero is added at the beginning to provide the value of m
                        printf("0");
                    }
                    printf("%0*.*e\n",mValue,nValue,result);
                    }
            }else{
                if(nValue==1){
                    printf("%lf %c %lf = ",fOperand,operation,sOperand);
                    printf("%.*E\n",mValue-nValue,result);
                }else{
                    printf("%lf %c %lf = ",fOperand,operation,sOperand);
                    int i;
                    for(i=0;i<mValue-nValue-1;i++){ //Zero is added at the beginning to provide the value of m
                        printf("0");
                    }
                    printf("%0*.*e\n",mValue,nValue,result);
                    }
            }
            
        }
    }
}
