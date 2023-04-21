#include <stdio.h>
#include<ctype.h>
#include <math.h>
void part1();
void part2();
void part3();
void draw_board(char arr[][3]);/*this function prints the current board in tic toc toe game */
void game(char arr[][3]);/*code that runs the tic toc toe game*/
int checkGame(char arr[][3]);/*checks if the tic toc toe game is finished*/
void move(int *moveArr,int orderOfMoves,int *checkValid);/*Function that allows inputs to be added to the desired position in tic toc toe.*/
void counter(char filename[], char *alphabet, int *letterCounter);/*function that counts characters in the first part*/

typedef enum {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    ORANGE
} Color;/* created color enum structure*/
double colorVectors[5][3] = {/* created array holding the values of colors.*/
    {1.0, 0.0, 0.0}, // RED
    {0.0, 1.0, 0.0}, // GREEN
    {0.0, 0.0, 1.0}, // BLUE
    {0.5, 0.5, 0.0}, // YELLOW
    {0.5, 0.4, 0.2}  // ORANGE
};
void colorMixer(Color c1, Color c2, Color (*f)(Color, Color));/* this function takes two variables of type color and a pointer function.*/
Color mixColors(Color c1, Color c2);/* this function mixes variables of type color from a function called "colorMixer".*/
double distance(double v1[3], double v2[3]);/* this function calculates the distance of the vector of two input colors*/
int main() {
    part1();
    while(getchar() != '\n');//clean buffer
    part2();
    printf("\n");
    part3();
}
void part1() {
    char filename[256];
    char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int letterCounter[26] = {0};
    printf("Enter the file name: ");
    scanf("%s", filename); /* retrieval of the document name from the user.*/
    counter(filename, alphabet, letterCounter);/*The counter function sends the received filename, the alphabet array and the array representing the number of each character.*/
    for (int i = 0; i < 26; i++) {
         /*printing the number of all characters*/
        printf("%c : %d\n", alphabet[i],letterCounter[i]);
    }
}
void counter(char filename[], char *alphabet, int *letterCounter) {
    FILE *file;
    int c;
    file = fopen(filename, "r");/* file opens in read mode*/
    if (file == NULL) {
        printf("File not found!\n");
        return;
    }
    char upper;
    while ((c = fgetc(file)) != EOF) {/* read all characters until the end of the file*/
        for (int i = 0; i < 26; i++) {
            upper=toupper(c);
            if (upper == alphabet[i]) {
                letterCounter[i] = letterCounter[i] + 1; /* the counter value of the character in the file is incremented by one.*/
                break;
            }
        }
    }
    fclose(file);
}
void part2(){
    char color1,color2; /* variables holding the characters r,g,b,y,o received as input from the user*/
    Color colorType1,colorType2;/* variables of type color created to assign the characters received from the user to the corresponding variable of type color created with the enum.*/
    while(1){
        printf("Enter Color 1 (r,g,b,y,o):");
        if(scanf("%c",&color1)!=1||(color1!='r'&&color1!='g'&&color1!='b'&&color1!='y'&&color1!='o')){
            printf("Invalid input please try again...\n");
            while(getchar() != '\n'); // clean buffer
            continue;/* Re-requests the value if incorrect input is received from the user*/
        }
        while(getchar() != '\n'); //clean buffer
        printf("Enter Color 2 (r,g,b,y,o):");
        if(scanf("%c",&color2)!=1||(color2!='r'&&color2!='g'&&color2!='b'&&color2!='y'&&color2!='o')){
            printf("Invalid input please try again...\n");
            while(getchar() != '\n'); // clean buffer
            continue;/* Re-requests the value if incorrect input is received from the user*/
        }
        switch (color1)/*assigning the received character value to a variable of type color*/
        {
        case 'r':
             colorType1=RED;
            break;
        
        case 'g':
            colorType1=GREEN;
            break;
        case 'b':
            colorType1=BLUE;
            break;
        case 'o':
            colorType1=ORANGE;
            break;
        case 'y':
            colorType1=YELLOW;
            break;
        }
        switch (color2)/*assigning the received character value to a variable of type color*/
        {
        case 'r':
             colorType2=RED;
            break;
        
        case 'g':
            colorType2=GREEN;
            break;
        case 'b':
            colorType2=BLUE;
            break;
        case 'o':
            colorType2=ORANGE;
            break;
        case 'y':
            colorType2=YELLOW;
            break;
        }
        break;
    }
    colorMixer(colorType1, colorType2, mixColors);
}
void colorMixer(Color c1, Color c2, Color (*f)(Color, Color)) {
    Color result = f(c1, c2);/* The function f is the "mixColors" function that mixes colors.*/
    printf("Mixed Color: ");
    switch (result) /* print the result variable of type color with the name of the color and its values*/
    {
    case 0:
       printf("RED [1.0, 0.0, 0.0]");
        break;
    case 1:
       printf("GREEN [0.0, 1.0, 0.0]");
        break;
    case 2:
       printf("BLUE [0.0, 0.0, 1.0]");
        break;
    case 3:
       printf("YELLOW [0.5, 0.5, 0.0]");
        break;
    case 4:
        printf( "ORANGE [0.5, 0.4, 0.2]");
        break;
    }
}
Color mixColors(Color c1, Color c2) {
    double v1[3] = {colorVectors[c1][0], colorVectors[c1][1], colorVectors[c1][2]};
    double v2[3] = {colorVectors[c2][0], colorVectors[c2][1], colorVectors[c2][2]};
    /* The values of the received color type variables are assigned to arrays v1 and v2.*/
    double mixed[3];
    for (int i = 0; i < 3; i++) {/* colors of the same index are mixed.*/
        mixed[i] = (v1[i] + v2[i]) / 2;
    }
    
    int closest;
    double minDist; //distance(mixed, colorVectors[RED]);/* variable created to hold the shortest distance*/
    
    for (int i = 1; i < 5; i++) {
        double dist = distance(mixed, colorVectors[i]);/*calculating the distance of the blended color from the color in the corresponding index */
        if (dist < minDist) {
            minDist = dist;
            closest = i;
        }
    }
    
    return closest;
}
double distance(double v1[3], double v2[3]) {
    double sum = 0;
    for (int i = 0; i < 3; i++) {/* calculation of the two received arrays with the Euclidean formula*/
        sum += (v1[i] - v2[i]) * (v1[i] - v2[i]);
    }
    return sqrt(sum);
}
void part3(){
    char arr[3][3]={
            {'-', '-', '-'},
            {'-', '-', '-'},
            {'-', '-', '-'}
    };
    draw_board(arr);//prints the received array
    game(arr);//calls the game with the array created in the first case
    char choice;
    while(1){/* This loop is entered after the game has been played once. It continues until the user wants to quit the game.*/
        char arr[3][3]={
            {'-', '-', '-'},
            {'-', '-', '-'},
            {'-', '-', '-'}
        };
        printf("Do you want to play again? (Y/N) ");
        if(scanf(" %c", &choice) != 1 || (choice != 'Y' && choice != 'N')){
            printf("Invalid input. Please try again...\n");
            while(getchar() != '\n'); // tampon bölgesini temizle
            continue;
        }
        if(choice=='N'){
            break;
        } else {/* If the user wants to continue the game, the first board is printed and then the game is called.*/
            draw_board(arr);
            game(arr);
        }
    } 
}
void game(char arr[][3]){
    int moveArr[2]={0,0};/* array to hold the coordinates to be received from the user*/
    int counts=1;/* the worst case in the game is 9 moves. Any number of moves greater than this must end the game. This variable was created for this reason.*/
    int num;
    while(checkGame(arr)!=1){/*The checkGame function checks if the game is over. If the game is over, the loop is exited. */
        num=counts%2;/* if this number is odd---> X, if this number is even---> O */
        int checkValidMove;
        move(moveArr,num,&checkValidMove);
        while(1){/* the validity of the values received from the user is checked.*/
            if(arr[moveArr[0]-1][moveArr[1]-1]=='X'||arr[moveArr[0]-1][moveArr[1]-1]=='O'){
                printf("Invalid input please try again...\n");
                move(moveArr,num,&checkValidMove);
            }else{
                break;
            }
        }
        if(num==1){/* Adding X to the board*/
            arr[moveArr[0]-1][moveArr[1]-1]='X';
            if(checkValidMove==1){
                counts=counts+1;
            } 
        }else if(num==0){/* Adding O to the board*/
            arr[moveArr[0]-1][moveArr[1]-1]='O';
            if(checkValidMove==1){
                counts=counts+1;
            }
        }

        draw_board(arr);
        checkGame(arr);
        if(counts>=10){/* the worst case in the game is 9 moves. Any number of moves greater than this must end the game. */
            printf("No winner. The game is tied\n");
            break;
        }
    }
    if(counts<10){
        if(num==0){
            printf("Player 2 wins!\n");
        }else{
            printf("Player 1 wins!\n");
        }
    }
}
int checkGame(char arr[][3]){/* this function compares the array of the board with the winning states in the game. If the board has a scenario suitable for the end, 1 is returned.*/
    if(arr[0][0]!='-'&&arr[0][0]==arr[0][1]&&arr[0][1]==arr[0][2]){
        return 1;
    }else if(arr[1][0]!='-'&&arr[1][0]==arr[1][1]&&arr[1][1]==arr[1][2]){
        return 1;
    }else if(arr[2][0]!='-'&&arr[2][0]==arr[2][1]&&arr[2][1]==arr[2][2]){
        return 1;
    }else if(arr[0][0]!='-'&&arr[0][0]==arr[1][0]&&arr[1][0]==arr[2][0]){
        return 1;
    }else if(arr[0][1]!='-'&&arr[0][1]==arr[1][1]&&arr[1][1]==arr[2][1]){
        return 1;
    }else if(arr[0][2]!='-'&&arr[0][2]==arr[1][2]&&arr[1][2]==arr[2][2]){
        return 1;
    }else if(arr[0][0]!='-'&&arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2]){
        return 1;
    }else if(arr[0][2]!='-'&&arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0]){
        return 1;
    }else{
        return 0;
    }
}
void move(int *moveArr,int orderOfMoves,int *checkValid){/*Function that allows inputs to be added to the desired position in tic toc toe.*/
    int row,col;
    if(orderOfMoves==1){
        printf("Player 1 (X), enter your move (row/col):");
    }else if(orderOfMoves==0){
        printf("Player 2 (Y), enter your move (row/col):");
    }
    while(1){/* code that continues until it receives correct input from the user*/
        char buffer;
        //Receiving coordinates from the user
        while (scanf("%d%d", &row, &col) != 2) {
            printf("Invalid input. Please enter two integers separated by a space.\n");
            *checkValid=0;
            while ((buffer = getchar()) != '\n' && buffer != EOF) {} // Buffer temizle
        }
        if(row>3||row<1||col>3||col<1){
            printf("Invalid input. Please enter two integers separated by a space.\n");
            *checkValid=0;
            continue;
        }else{
            *checkValid=1;//this pointer value is used in the game function to prevent the counter from incrementing on invalid inputs. If this variable is set equal to 1, the counter in the game function will be incremented by 1.
            break;
        }
    }
    moveArr[0]=row;
    moveArr[1]=col;
}
void draw_board(char arr[][3]){/* printing the board*/
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%c ",arr[i][j]);
        }
        printf("\n");
    }
}
