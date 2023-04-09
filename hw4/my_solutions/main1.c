#include <stdio.h>
/*Tarih eklenecek,sipariş sayısı ile ilgili bir fonksiyon yazılacak,yazılan her şey bir txt dosyasına eklenecek*/
void part1();
void printMenu();
//void priceCalculate(int order1,int serving1,int order2,int serving2,int order3,int serving3,char studentCheck);
int choice(int order,int serving);
float pullPriceFromFile(int order);
void drawReceipt(int order1,int serving1,int order2,int serving2,int order3,int serving3,char studentCheck);
void printFoodName(int order);
int main() {
    part1();
}
void part1(){
    int order1,order2,order3,j;
    int serving1,serving2,serving3;
    char studentCheck;
    printMenu();
    printf("\n");
    order1=choice(1,0);
    serving1=choice(0,1);
    order2=choice(1,0);
    serving2=choice(0,1);
    order3=choice(1,0);
    serving3=choice(0,1);
    while(1){ //buffer hatası
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
    /*calculate prices*/
    //printf("%d %d %d %c",order1,order2,order3,studentCheck);
    drawReceipt(order1,serving1,order2,serving2,order3,serving3,studentCheck);

}
void drawReceipt(int order1,int serving1,int order2,int serving2,int order3,int serving3,char studentCheck){
    float order1total,order2total,order3total,totalNoVAT,totalWithVAT;
    order1total=serving1*pullPriceFromFile(order1);
    float deneme,Discount;
    deneme=pullPriceFromFile(order1);
    printf("Önemli %f\n",deneme);
    order2total=serving2*pullPriceFromFile(order2);
    order3total=serving3*pullPriceFromFile(order3);
    totalNoVAT=order1total+order2total+order3total;
    if(studentCheck=='Y'){
        Discount=(totalNoVAT*12.5)/100;
    }else{
        if(totalWithVAT>=150){
            Discount=(totalNoVAT*18)/100;
        }
    }
    if(totalNoVAT>150&&studentCheck=='N'){
        totalNoVAT=totalNoVAT-totalNoVAT*1/10;
    }else if(studentCheck=='Y'){
        totalWithVAT=totalNoVAT-(totalNoVAT*125)/1000;
    }
    printf("\t200102002071\t08.04.2023/00.00\n");
    printf("\t------------------------------------\n");
    printf("\tProduct\t\t      Price(TL)\n");
    printf("\t------------------------------------\n");
    if (serving1==1){
        printf("\t   ");
        printFoodName(order1);
        printf("\t\t%.2f\n",order1total);
    }else{
        printf("\t%d *",serving1);
        printFoodName(order1);
        printf("\t\t%.2f\n",order1total);
    }
    if (serving2==1){
        printf("\t   ");
        printFoodName(order2);
        printf("\t\t%.2f\n",order2total);
    }else{
        printf("\t%d *",serving2);
        printFoodName(order2);
        printf("\t\t%.2f\n",order2total);
    }
    if (serving3==1){
        printf("\t   ");
        printFoodName(order3);
        printf("\t\t%.2f\n",order3total);
    }else{
        printf("\t%d *",serving3);
        printFoodName(order3);
        printf("\t\t%.2f\n",order3total);
    }
    printf("\tTotal:   \t\t%.2f\n",totalNoVAT);
    if(studentCheck=='Y'){
        printf("\tStudent discount:   \t%.2f\n",Discount);
    }else{
        if(totalNoVAT>=150){
            printf("\tDiscount:   \t\t%.2f\n",Discount);
        }else{
            Discount=0;
        }
    }
    printf("\t------------------------------------\n");
    printf("\tPrice:   \t\t%.2f\n",totalNoVAT-Discount);
    totalWithVAT=(totalNoVAT-Discount)+((totalNoVAT-Discount)*18)/100;
    printf("\tPrice+VAT:\t\t%.2f\n",totalWithVAT);
}
void printFoodName(int order){
    FILE *dosya;
    dosya = fopen("dosya.txt","r");
    if(dosya == NULL) {
        printf("Dosya açılamadı.");
        //return 0;
    }
    char c;
    int counterLineCheck= 0,readCheck=0;
    while((c = fgetc(dosya)) != EOF) {
        if(c<='z' &&c>='a' || c<='Z' &&c>='A'||c==' '||c=='\n'){
            if(readCheck==0){
                counterLineCheck++;
            }
            if(c=='\n'){
                readCheck=0;
            }else{
                if(order==counterLineCheck){
                    printf("%c",c);
                    readCheck=1;
                }
                
                
                readCheck=1;
            }
        }
    }
    fclose(dosya);
}
float pullPriceFromFile(int order){
    FILE *file;
    file = fopen("dosya.txt","r");
    if(file == NULL) {
        printf("Dosya açılamadı.");
        //return 0;
    }
    int line=order;
    float price;
    char c;
    int counterLineCheck= 1,lineSpace=0,readCheck=0;
    while((c = fgetc(file)) != EOF) {
        if(c=='\n'){
           counterLineCheck++;
        }
        if (counterLineCheck==line){
            fscanf(file, "%f", &price);
        }
    }
    //printf("%f",fiyat);
    fclose(file);
    return price;
}
int choice(int order,int serving){
    int choice,j;
    if(order==1 && serving==0){
        while(1){
        printf("Please choose a product (1-10): ");
        if(scanf("%d",&choice)!=1||choice<1||choice>10){
            printf("Invalid choice.Please select again \n");
            while ((j = getchar()) != '\n' && j != EOF); /*clean buffer */
        }else{
            //if(choice<1 && choice>)
            while ((j = getchar()) != '\n' && j != EOF); /*clean buffer */
            break;
        }
        }
    }else if(order==0&&serving==1){
        while(1){
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

void printMenu(){
    FILE *dosya;
    dosya = fopen("dosya.txt","r");
    if(dosya == NULL) {
        printf("Dosya açılamadı.");
        //return 0;
    }
    char c;
    int counterLineCheck= 0,lineSpace=0,readCheck=0;
    printf("Yemek Listesi:\n");
    while((c = fgetc(dosya)) != EOF) {
        if(c<='z' &&c>='a' || c<='Z' &&c>='A'||c==' '||c=='\n'){
            if(readCheck==0){
                printf("%d. ",counterLineCheck+1);
                counterLineCheck++;
            }
            if(c=='\n'){
                readCheck=0;
                //printf("%d. ",counterLineCheck+1);
                printf("\n");
                printf("\n");
                //counterLineCheck++;
            }else{
                printf("%c",c);
                readCheck=1;
            }
        }
    }
    fclose(dosya);

}
