#include<stdio.h>
#include<stdlib.h>
#define left 'a'
#define right 'd'
#define up 'w'
#define down 's'
int checkFunction(int c_xaxis,int c_yaxis,int d_xaxis,int d_yaxis);/* this function checks if the game is over*/
void printTable(int x, int c_xaxis,int c_yaxis,int d_xaxis,int d_yaxis); //this function prints the table
void gameplay(int axis_size,int c_xaxis,int c_yaxis,int d_xaxis,int d_yaxis);/*this function works when the game wants to be played. It provides movements on the table until the game ends. */
void thegame();/* This function works until you exit the game. Shows the menu. Connects to the gameplay function.*/
int main(){
    thegame();//all functions work in conjunction with this function
}
void printTable(int x, int c_xaxis,int c_yaxis,int d_xaxis,int d_yaxis){
    int i,j;
    for (i=1;i<2*(x+2);i++){ /*drawing of the top of the wall*/
        printf("-");
    }
    printf("\n");
    for(i=1;i<x+1;i++){/*"i" represents rows, j represents columns.The columns for each row are printed with a loop.*/
         for(j=1;j<x+2;j++){ /*print n+1 lines for n columns*/
            if((j==c_yaxis && i==c_xaxis)||(j==d_yaxis && i==d_xaxis)){
                if((j==c_yaxis && i==c_xaxis)){
                    printf("C|");/*Printing the expression C */
                }
                else if((j==d_yaxis && i==d_xaxis)){
                    printf("D|");/*Printing the expression D */
                }
            }
            else{
                printf(" |");
            }
        }
        printf("\n");
    }
    for (i=1;i<2*(x+2);i++){ /* drawing under the wall*/
        printf("-");
    }
    printf("\n");
}
void gameplay(int axis_size,int c_xaxis,int c_yaxis,int d_xaxis,int d_yaxis){
    int counter=0; /*counts the number of valid steps*/
    while(checkFunction(c_xaxis,c_yaxis,d_xaxis,d_yaxis)==1){/*this loop continues until the game is over, i.e. until the values of D and C are equal to each other.*/
        printf("Where do you want to go?\nLeft--> a\nRight--> d\nUp--> w\nDown--> s\n ");
        char direction;/* Holds direction data*/
        while(1==1){ /*The loop continues until you enter a valid direction*/
            direction=getchar();
            if(direction=='\n'){/*Print error code if input is a space character*/
                printf("Invalid input. Please try again ...\n");
            }else if (getchar() != '\n') {/*if the input is not a space character, the other characters in the input are read. If the other characters are not spaces, an error message is printed. i.e. here it is checked that the input is a single character*/
                while (getchar() != '\n');
                printf("Invalid input. Please try again ...\n");
                continue;
            }else if(direction!=left&&direction!=right&&direction!=up&&direction!=down){//print error if the direction variable does not match a defined variable
                printf("Invalid input. Please try again ...\n");
            }
            else{// if every think is ok
                break;
            }
            
        }
        switch (direction)
        {
            case left: //if direction equals 'a'
                if (c_yaxis==2){ //check wall.
                    printf("Invalid entry. There is a wall at the destination\n ");
                }else{
                    c_yaxis=c_yaxis-1;
                    counter++;
                }
                break;
            case right: //If direction equals 'd'
                if(c_yaxis==axis_size+1){//check wall
                    printf("Invalid entry. There is a wall at the destination\n ");
                }
                else{
                    c_yaxis=c_yaxis+1;
                    counter++;
                }
                break;
            case up://If direction equals 'w'
                if(c_xaxis==1){//check wall
                    printf("Invalid entry. There is a wall at the destination\n ");
                    
                }
                else{
                    c_xaxis=c_xaxis-1;
                    counter++;
                }
                break;
            case down://If direction equals 's'
                if(c_xaxis==axis_size){//check wall
                    printf("Invalid entry. There is a wall at the destination\n ");
                    
                }
                else{
                    c_xaxis=c_xaxis+1;
                    counter++;
                }
                break;
        }
        if(checkFunction(c_xaxis,c_yaxis,d_xaxis,d_yaxis)==1){ //Check the values of d and c. If they are not equal, i.e. the game is not over, print the table.
            printTable(axis_size,c_xaxis,c_yaxis,d_xaxis,d_yaxis);}
        }
    /* if the game is over, print a congratulatory message and the number of steps*/
    printf("Your valid step count : %d\n",counter);
    printf("Congratulations you have completed the game\n");
}
void thegame(){
    int choose;/*holds the user's choice */
    int j;
    int axis_size, c_xaxis, c_yaxis, d_xaxis, d_yaxis; /*Variables were declerate to hold the positions of c and d on the x and y axis.*/
    while(choose!='3'){/*this loop continues until the game is exited*/
        printf("Welcome to the 2D puzzle game!\n1. New Game\n2. Help\n3.Exit\n");
        choose = getchar();/*the user's choice in the game's menu is taken as input*/
        if (choose == '\n') { /*Print error code if input is a space character*/
            printf("Invalid input. Please try again...\n");
            continue;
        } else if (getchar() != '\n') {/*if the input is not a space character, the other characters in the input are read. If the other characters are not spaces, an error message is printed. i.e. here it is checked that the input is a single character*/
            while (getchar() != '\n');
            printf("Invalid input. Please try again...\n");
            continue;
        } else { /*this block is entered if the first letter of the input is not a space character and the input is a single character.*/
            if (choose == '2') {/*print the help message if choose equals 2 */
                printf("The character is able to move one space in any of the four cardinal directions: up, down, left, and right. Diagonal moves are not allowed. The user will input their desired move using the following keys: 'a' for left, 'd' for right, 'w' for up, and 's' for down. These moves should be defined at the beginning of the code with direction names as the keys. Any control or selection with [a, d, w, s] characters will result in a missgrading. The game will prompt the user for a new move after each move is made until the game is over.");
            } else if (choose == '3') {/*quit the game if choose equals 0. Close the loop*/
                printf("Closing...\n");
                break;
            } else if (choose == '1') { //if choose equals 0
                while (1) { /*this loop continues until valid axis input */
                    printf("Give axis size: ");
                    if (scanf("%d", &axis_size) != 1) {/*print error message if the input is not char*/
                        printf("Invalid input. Please try again\n");
                        while ((j = getchar()) != '\n' && j != EOF); /*clean buffer */
                    } else if (axis_size < 5 || axis_size > 10) {/*print error message if the input does not fit the range */
                        printf("Invalid input. Please try again\n");
                        while ((j = getchar()) != '\n' && j != EOF);//clean buffer
                    } else {
                        while ((j = getchar()) != '\n' && j != EOF);//clean buffer
                        break;
                    }
                }
                while (1) { /*this loop is for reassigning the values of c and d if they are the same*/
                    c_xaxis = rand() % axis_size + 1;
                    c_yaxis = rand() % axis_size + 1;
                    d_xaxis = rand() % axis_size + 1; /*generate random numbers in the desired range */
                    d_yaxis = rand() % axis_size + 1;
                    if (c_xaxis == d_xaxis && c_yaxis == d_yaxis) { /*If c==d */
                        printf("Creating the table randomly again\n");
                    } else if (d_yaxis < 2 || c_yaxis < 2) { /*For n columns, n+1 lines are printed. If the value of c or d in any column is on line 1, it goes outside the wall. So in this case a random value is assigned again. */
                        printf("Creating the table randomly again\n");
                    } else {
                        break;
                    }
                }
                printTable(axis_size, c_xaxis, c_yaxis, d_xaxis, d_yaxis);/* table is printed*/
                gameplay(axis_size,c_xaxis,c_yaxis,d_xaxis,d_yaxis); /*the game is called.*/
            }
         }
    }
}
int checkFunction(int c_xaxis,int c_yaxis,int d_xaxis,int d_yaxis){
    if((c_xaxis==d_xaxis)&&(c_yaxis==d_yaxis)){ /*Checks axes. Return 0 if the game is finished*/
        return 0;
    }
    else{
        return 1;
    }
}
    

