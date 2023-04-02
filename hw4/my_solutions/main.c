#include<stdio.h>
void menuFunction();
int main(){
    menuFunction();
}
void menuFunction(){
    FILE * fp;
    char karakter;
    int order1,order2,order3,serving1,serving2,serving3;
    int product_price1,product_price2,product_price3,product_price4,product_price5,product_price6,product_price7,
    product_price8,product_price9,product_price10;
    fp = fopen("input.txt","r");
    int num=1;
    char c,check_student;
    while ((c = fgetc(fp)) != EOF) {
        if(num>10){
            break;
        }else{
            if (c == '\n') {
            putchar(c);
            num++;
            } else {
                putchar(c);
            }
        }
    }
    printf("Please choose a product (1-10): ");
    scanf(" %d",&order1);   
    printf("How many servings do you want?") ;
    scanf(" %d",&serving1);   
    printf("Please choose a product (1-10): ");
    scanf(" %d",&order2);
    printf("How many servings do you want?") ;
    scanf(" %d",&serving2); 
    printf("Please choose a product (1-10): ");
    scanf(" %d",&order3);
    printf("How many servings do you want?") ;
    scanf(" %d",&serving3); 
    fclose(fp);
    printf("Are you student? (Y/N):");
    scanf("%c",&check_student);
    

     
}