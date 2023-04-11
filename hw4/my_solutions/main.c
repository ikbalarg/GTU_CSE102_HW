#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int printMenu();/*This function prints menu without price information,returns 0 if file not found*/
int choice(int order,int serving); /*This function takes two parameter. we choose food from the menu if order=1 and serving=0. We we get information about the number of services, if serving=1 and order=0  */
float pullPriceFromFile(int order);/* this function pulls the price information from the file and takes the number of the dish in the menu as input*/
void draawReceipt_1(int dish1,int dish2,int dish3,int dish4,int dish5,int dish6,int dish7,int dish8,
int dish9,int dish10,char studentChec);/*dishn--> holds information about how many of the "n" numbered dishes in the menu were purchased.this function takes the information about how many dishes in the menu have been ordered and prints the receipt. It also creates a txt file and prints the orders there*/
void printFoodName(int order,FILE *writeFile);/* This function prints food name. */
float printDishPrice(int order, int lineNumber,FILE *writeFile);/*this function takes three inputs.One is a txt file to write data into. order-->the order quantity,lineNumber=the number of the dish on the menu  */
int part2();/* part2 of homework*/
void part1();/*This function receives the quantity data for each dish and passes it to the other function */
int main() {
    part1();
    int control=1;
    while(control==1){ /* if the user answers N to the question do you want to play again, 0 is returned and the loop terminates*/
        control=part2();
    }
}
void part1(){
    if(printMenu()==0){/* returns 0 if file not found. program ends*/
        return;
    }
    printf("\n");
    int dish1=0,dish2=0,dish3=0,dish4=0,dish5=0,dish6=0,dish7=0,dish8=0,dish9=0,dish10=0;/*these variables hold the serving amount for each dish. This way, if a dish is ordered again at different times, it will not appear more than once on the receipt.*/
    char studentCheck;
    int order,serving;
    while(1){
        order=choice(1,0);/* food is selected. Return the number "n" for dish n in the menu*/
        serving=choice(0,1);/* serving size is taken*/
        if(serving==0||order==0){
            break;
        }
        switch (order)
        { /* this switch case block calculates the portion amount for the corresponding meal received from the user. The aim is to sum the portion amounts when the same product is ordered at different times.*/
        case 1:
            dish1=dish1+serving;
            break;
        case 2:
            dish2=dish2+serving;
            break;
        case 3:
            dish3=dish3+serving;
            break;
        case 4:
            dish4=dish4+serving;
            break;
        case 5:
            dish5=dish5+serving;
            break;
        case 6:
            dish6=dish6+serving;
            break;
        case 7:
            dish7=dish7+serving;
            break;
        case 8:
            dish8=dish8+serving;
            break;
        case 9:
            dish9=dish9+serving;
            break;
        case 10:
            dish10=dish10+serving;
            break;
        default:
            break;
        }
    }
    while(1){ /* student check. If there is an incorrect entry, it will be asked again.*/
        printf("Are you student? (Y/N): \n");
        studentCheck=getchar();
        if(studentCheck=='\n'){
            printf("Invalid input. Please try again...\n ");
        }else if(getchar() != '\n'){
                while (getchar() != '\n');
                printf("Invalid input. Please try again ...\n");
                continue;
        }else{
            if(studentCheck=='Y'||studentCheck=='N'){
                break;
            }else{
                printf("Invalid input. Please try again ...\n");
            }
        }
    }
    draawReceipt_1(dish1,dish2,dish3,dish4,dish5,dish6,dish7,dish8,dish9,dish10,studentCheck);/* call the function to print the receipt*/
}
void draawReceipt_1(int dish1,int dish2,int dish3,int dish4,int dish5,int dish6,int dish7,int dish8,
int dish9,int dish10,char studentCheck){
    FILE *writeFile = fopen("output.txt","w+");/* created a new file to print the data received from the user to the file*/
    char timeString[80]; /* holds time information*/
    time_t now = time(NULL);
    strftime(timeString, 80, "%d.%m.%Y/%H:%M", localtime(&now));
    float totalNoVAT=0,totalWithVAT,Discount,eachOrderTotal;
    printf("\t200102002071\t");
    printf("%s\n", timeString);
    printf("\t------------------------------------\n");
    printf("\tProduct\t\t      Price(TL)\n");
    printf("\t------------------------------------\n");
    if(dish1>0){:/* Order item 1 on the menu if the order quantity is greater than 0:*/
        eachOrderTotal=printDishPrice(dish1, 1,writeFile);/* call the function that multiplies the price and portion of a single product*/
        totalNoVAT=totalNoVAT+eachOrderTotal;/* the total price of a single product is added to the total tax-free quantity*/
    }
    if(dish2>0){/* Order item 2 on the menu if the order quantity is greater than 0:*/
        eachOrderTotal=printDishPrice(dish2, 2,writeFile);
        totalNoVAT=totalNoVAT+eachOrderTotal;
    }
    if(dish3>0){/* Order item 3 on the menu if the order quantity is greater than 0:*/
        eachOrderTotal=printDishPrice(dish3, 3,writeFile);/* */
        totalNoVAT=totalNoVAT+eachOrderTotal;
    }
    if(dish4>0){/* Order item 4 on the menu if the order quantity is greater than 0:*/
        eachOrderTotal= printDishPrice(dish4, 4,writeFile);
        totalNoVAT=totalNoVAT+eachOrderTotal;
    }
    if(dish5>0){/* Order item 5 on the menu if the order quantity is greater than 0:*/
        eachOrderTotal= printDishPrice(dish5, 5,writeFile);
        totalNoVAT=totalNoVAT+eachOrderTotal;
    }
    if(dish6>0){/* Order item 6 on the menu if the order quantity is greater than 0:*/
       eachOrderTotal= printDishPrice(dish6, 6,writeFile);
       totalNoVAT=totalNoVAT+eachOrderTotal;
    }
    if(dish7>0){/* Order item 7 on the menu if the order quantity is greater than 0:*/
        eachOrderTotal= printDishPrice(dish7, 7,writeFile);
        totalNoVAT=totalNoVAT+eachOrderTotal;
    }
    if(dish8>0){/* Order item 8 on the menu if the order quantity is greater than 0:*/
        eachOrderTotal= printDishPrice(dish8, 8,writeFile);
        totalNoVAT=totalNoVAT+eachOrderTotal;
    }
    if(dish9>0){/* Order item 9 on the menu if the order quantity is greater than 0:*/
        eachOrderTotal=printDishPrice(dish9, 9,writeFile);
        totalNoVAT=totalNoVAT+eachOrderTotal;
    }
    if(dish10>0){/* Order item 10 on the menu if the order quantity is greater than 0:*/
        eachOrderTotal= printDishPrice(dish10, 10,writeFile);
        totalNoVAT=totalNoVAT+eachOrderTotal;
    }
    printf("\tTotal:   \t\t%.2f\n",totalNoVAT);
    fprintf(writeFile,"\tTotal:   \t\t%.2f\n",totalNoVAT);
    if(studentCheck=='Y'){/* discount is calculated if you are a student*/
        Discount=(totalNoVAT*12.5)/100;
        printf("\tStudent discount:   \t%.2f\n",Discount);
        fprintf(writeFile,"\tStudent discount:   \t%.2f\n",Discount);
        if (totalNoVAT>=150){/* if the total amount of products purchased is more than 150tl and the student is a student, a discount is applied twice on the total price without tax*/
            printf("\tDiscount:   \t\t%.2f\n",(totalNoVAT*10/100));
            fprintf(writeFile,"\tDiscount:   \t\t%.2f\n",(totalNoVAT*10/100));
            Discount=Discount+(totalNoVAT*10/100);
        }
        

    }else{
        if(totalNoVAT>=150){/* apply a discount only when ordering more than 150 tl, not students*/
            Discount=(totalNoVAT*10)/100;
            printf("\tDiscount:   \t\t%.2f\n",Discount);
            fprintf(writeFile,"\tDiscount:   \t\t%.2f\n",Discount);

        }else{
            Discount=0;
        }
    }
    printf("\t------------------------------------\n");
    printf("\tPrice:   \t\t%.2f\n",totalNoVAT-Discount);
    fprintf(writeFile,"\tPrice:   \t\t%.2f\n",totalNoVAT-Discount);
    totalWithVAT=(totalNoVAT-Discount)+((totalNoVAT-Discount)*18)/100;/* Add VAT*/
    printf("\tPrice+VAT:\t\t%.2f\n",totalWithVAT);
    fprintf(writeFile,"\tPrice+VAT:\t\t%.2f\n",totalWithVAT);
    fclose(writeFile);

}
float printDishPrice(int order, int lineNumber,FILE *writeFile){
    float orderTotal;
    if(order>0){//if the serving size is greater than 0
        orderTotal=0;
        orderTotal=order*pullPriceFromFile(lineNumber);/* function takes the product price and multiplies it by the portion quantity*/
        //totalNoVAT=totalNoVAT+orderTotal;
        if (order==1){
            printf("\t   ");
            fprintf(writeFile,"\t   ");
            printFoodName(lineNumber,writeFile);/* If the portion quantity is not equal to 1, put a "*" between the quantity and the name of the dish and print it.*/
            printf("\t\t%.2f\n",orderTotal);
            fprintf(writeFile,"\t\t%.2f\n",orderTotal);
        }else{ /* If the portion quantity is not equal to 1, put a "*" between the quantity and the name of the dish and print it. */
            printf("\t%d *",order);
            fprintf(writeFile,"\t%d *",order);
            printFoodName(lineNumber,writeFile);
            printf("\t\t%.2f\n",orderTotal);
            fprintf(writeFile,"\t\t%.2f\n",orderTotal);
        }
    }
    return orderTotal;/*returns the total price for a dish*/
}
void printFoodName(int order,FILE *writeFile){
    FILE *dosya;
    dosya = fopen("input.txt","r");
    if(dosya == NULL) {
        printf("File not found...\n");
        //return 0;
    }
    int c;
    int counterLineCheck= 0,readCheck=0;
    while((c = fgetc(dosya)) != EOF) {/*read the file to the end of the document*/
        if(c<='z' &&c>='a' || c<='Z' &&c>='A'||c==' '||c=='\n'){/* read only the letters*/
            if(readCheck==0){
                counterLineCheck++; /* The number of lines is checked as the number of lines corresponds to the dish on the menu. It is counted.*/
            }
            if(c=='\n'){
                readCheck=0;
            }else{
                if(order==counterLineCheck){/* when the number of lines is equal to the number of orders of the dish in the menu*/
                    printf("%c",c);
                    fprintf(writeFile,"%c",c);
                    readCheck=1;
                }
                
                
                readCheck=1;
            }
        }
    }
    fclose(dosya);
}
float pullPriceFromFile(int order){/* this function pulls the price information*/
    FILE *file;
    file = fopen("input.txt","r");
    if(file == NULL) {
        printf("File not found...\n");
        //return 0;
    }
    int line=order;
    float price;
    int c;
    int counterLineCheck= 1,lineSpace=0,readCheck=0;
    while((c = fgetc(file)) != EOF) {
        if(c=='\n'){
           counterLineCheck++; /*The number of lines is checked as the number of lines corresponds to the dish on the menu. It is counted.*/
        }
        if (counterLineCheck==line){/* when the number of lines is equal to the number of orders of the dish in the menu*/
            fscanf(file, "%f", &price);
        }
    }
    //printf("%f",fiyat);
    fclose(file);
    return price;/*return price information*/
}
int choice(int order,int serving){/*This function takes two parameter. we choose food from the menu if order=1 and serving=0. We we get information about the number of services, if serving=1 and order=0  */
    int choice,j;
    if(order==1 && serving==0){/*choose food */
        while(1){/* loop until the correct input is received*/
        printf("Please choose a product (1-10): ");
        if(scanf("%d",&choice)!=1||choice<0||choice>10){
            printf("Invalid choice.Please select again \n");
            while ((j = getchar()) != '\n' && j != EOF); /*clean buffer */
        }else{
            //if(choice<1 && choice>)
            while ((j = getchar()) != '\n' && j != EOF); /*clean buffer */
            break;
        }
        }
    }else if(order==0&&serving==1){// get information about the number of services
        while(1){/* loop until the correct input is received*/
        printf("How many servings do you want? ");
        if(scanf("%d",&choice)!=1||choice<0){
            printf("Invalid choice.Please select again \n");
            while ((j = getchar()) != '\n' && j != EOF); /*clean buffer */
        }else{
            while ((j = getchar()) != '\n' && j != EOF); /*clean buffer */
            break;
        }
        }
    }
    return choice;
}

int printMenu(){/*This function prints menu without price information,returns 0 if file not found*/
    FILE *dosya;
    dosya = fopen("input.txt","r");
    if(dosya == NULL) { /* if the file is not found, it returns 0 and terminates the program*/
        printf("File not found...\n");
        return 0;
    }
    int c;
    int counterLineCheck= 0,lineSpace=0,readCheck=0;
    printf("Yemek Listesi:\n");
    while((c = fgetc(dosya)) != EOF) {
        if(c<='z' &&c>='a' || c<='Z' &&c>='A'||c==' '||c=='\n'){
            if(readCheck==0){
                printf("%d. ",counterLineCheck+1); /* prints the numbers at the beginning of the dishes. Counts the lines for this.*/
                counterLineCheck++;
            }
            if(c=='\n'){
                readCheck=0;
                printf("\n");
            }else{
                printf("%c",c);
                readCheck=1;
            }
        }
    }
    fclose(dosya);
    return 1; /* prints the menu and returns 1 if the file is found*/
}
int part2(){
    char again;
    int choice,choicePC,j;
    int control=1;
try:
    printf("Please make a choice!\n1: Stone, 2: Paper, 3: Scissors\n");
    if(scanf(" %d",&choice)!=1){
        printf("Invalid input.Please try again ...\n");
        while ((j = getchar()) != '\n' && j != EOF); /*buffer'ı temizle */
        goto try;
    }else{
        if(choice<4&&choice>0){
            //srand(time(NULL));
            choicePC=(random() % 3) + 1;
            switch (choice)
            {
            case 1:
                if(choicePC==1){
                    printf("You choose Stone. I choose Stone.It's a tie!\n");
                }
                else if(choicePC==3){
                    printf("You choose Stone. I choose Scissors.You win!\n");
                }
                else if(choicePC==2){
                    printf("You choose Stone. I choose Paper.I won!\n");
                }
                break;
            case 2:
                if(choicePC==1){
                    printf("You choose Paper. I choose Stone.You win!\n");
                }
                else if(choicePC==3){
                    printf("You choose Paper. I choose Scissors.I win!\n");
                }
                else if(choicePC==2){
                    printf("You choose Paper. I choose Paper.It's a tie!\n");
                }
                break;
            case 3:
                if(choicePC==1){
                    printf("You choose Scissors. I choose Stone.I win!\n");
                }
                else if(choicePC==3){
                    printf("You choose Scissors. I choose Scissors.It's a tie!\n");
                }
                else if(choicePC==2){
                    printf("You choose Scissors. I choose Paper.You win!\n");
                }
                break;
                
            }
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            while(1){
                printf("Do you want to play again?(Y/N) \n");
                again=getchar();
                if(again=='\n'){
                    printf("Invalid input. Please try again ...\n");
                }else if (getchar() != '\n') {
                    while (getchar() != '\n');
                    printf("Invalid input. Please try again ...\n");
                    continue;
                }else{
                    if(again=='Y'){
                        return 1;
                    }else if(again=='N'){
                        return 0;
                    }else{
                        printf("Invalid input please try again ...\n");
                    }
                }
            }

        }else{
            printf("Invalid input.Please try again ...\n");
            goto try;
        }
    }
    
}
