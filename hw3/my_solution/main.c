#include<stdio.h>
#include<stdlib.h>
#define left 'a'
#define right 'd'
#define up 'w'
#define down 's'
int checkFunction();
void printTable(int x, int c_xaxis,int c_yaxis,int d_xaxis,int d_yaxis);
void gameplay(int axis_size,int c_xaxis,int c_yaxis,int d_xaxis,int d_yaxis);
void thegame();
int main(){
    thegame();
}
void printTable(int x, int c_xaxis,int c_yaxis,int d_xaxis,int d_yaxis){
    int i,j;
    for (i=1;i<2*(x+2);i++){
        printf("-");
    }
    printf("\n");
    for(i=1;i<x+2;i++){
         for(j=1;j<x+2;j++){
            if((j==c_yaxis && i==c_xaxis)||(j==d_yaxis && i==d_xaxis)){
                if((j==c_yaxis && i==c_xaxis)){
                    printf("C|");
                }
                else if((j==d_yaxis && i==d_xaxis)){
                    printf("D|");
                }
            }
            else{
                printf(" |");
            }
        }
        printf("\n");    
    }
    for (i=1;i<2*(x+2);i++){
        printf("-");
    }
    printf("\n");
}
void gameplay(int axis_size,int c_xaxis,int c_yaxis,int d_xaxis,int d_yaxis){
    printf("Where do you want to go?\nLeft--> a\nRight--> d\nUp--> w\nDown--> s\n ");
    char direction;
    while(1==1){
        scanf(" %c",&direction);
        if(direction!=left&&direction!=right&&direction!=up&&direction!=down){
            printf("Invalid input. Please try again ...\n");
        }
        else{
            break;
        }
    }
    printf("\n %d %d %d %d \n",c_xaxis,c_yaxis,d_xaxis,d_yaxis);
    switch (direction)
    {
    case left:
        c_yaxis=c_yaxis-1;
        break;
    case right:
        c_yaxis=c_yaxis+1;
        break;
    case up:
        c_xaxis=c_xaxis+1;
        break;
    case down:
        c_xaxis=c_xaxis-1;
        break;    
    }
    printf("\n %d %d %d %d \n",c_xaxis,c_yaxis,d_xaxis,d_yaxis);
    printTable(axis_size,c_xaxis,c_yaxis,d_xaxis,d_yaxis);   
}
void thegame(){
    int choose;
    printf("Welcome to the 2D puzzle game!\n1. New Game\n2. Help\n3.Exit\n");
    scanf("%d",&choose);
    if (choose==2){
        printf("The character is able to move one space in any of the four cardinal directions: up, down, left, and right.\n Diagonal moves are not allowed. The user will input their desired move using the following keys: 'a' for\n left, 'd' for right, 'w' for up, and 's' for down. These moves should be defined at the beginning of the code\n with direction names as the keys. Any control or selection with [a, d, w, s] characters will result in a\n missgrading. The game will prompt the user for a new move after each move is made until the game is\n over.");
    }
    else if (choose==3){
        printf("Closing...\n");
    }
    else if(choose==1){
        int axis_size;
        while (1==1){
            printf("Give axis size: ");
            scanf("%d",&axis_size);
            if(axis_size<5 || axis_size>10 ){
                printf("Invalid input please try again\n");
            }
            else{
                break;
            }
        }
        int c_xaxis,c_yaxis,d_xaxis,d_yaxis;
        /*j-->satır
        i-->sütun*/
        while(1==1){
            c_xaxis=rand()% axis_size + 1;
            c_yaxis=rand()% axis_size + 1;
            d_xaxis=rand()% axis_size + 1;
            d_yaxis=rand()% axis_size + 1;
            if(c_xaxis==d_xaxis && c_yaxis==d_yaxis){
                printf("Your inputs are same. Please tyr again ... \n");
            }
            else{
                break;
            }
        }
        printTable(axis_size,c_xaxis,c_yaxis,d_xaxis,d_yaxis);
        gameplay(axis_size,c_xaxis,c_yaxis,d_xaxis,d_yaxis);
    }
}