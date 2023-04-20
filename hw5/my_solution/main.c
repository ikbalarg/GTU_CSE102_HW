#include <stdio.h>
#include<ctype.h>

void part1();
void part3();
void draw_board(char arr[][3]);
void game(char arr[][3]);
int checkGame(char arr[][3]);
void move(int *moveArr,int orderOfMoves,int *checkValid);
void counter(char filename[], char *alphabet, int *letterCounter);
int main() {
    part1();
    part3();
}
void part1() {
    char filename[256];
    char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int letterCounter[26] = {0};
    printf("Enter the file name: ");
    scanf("%s", filename);
    counter(filename, alphabet, letterCounter);
    for (int i = 0; i < 26; i++) {
        if(letterCounter[i]!=0){
            printf("%c : %d\n", alphabet[i],letterCounter[i]);
        }
    }
}
void counter(char filename[], char *alphabet, int *letterCounter) {
    FILE *file;
    int c;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found!\n");
        return;
    }
    char upper;
    while ((c = fgetc(file)) != EOF) {
        for (int i = 0; i < 26; i++) {
            upper=toupper(c);
            if (upper == alphabet[i]) {
                letterCounter[i] = letterCounter[i] + 1;
                break;
            }
        }
    }
    fclose(file);
}
void part3(){
    char arr[3][3]={
            {'-', '-', '-'},
            {'-', '-', '-'},
            {'-', '-', '-'}
    };
    draw_board(arr);
    game(arr);
    char choice;
    while(1){
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
        } else {
            draw_board(arr);
            game(arr);
        }
    } 
}
void game(char arr[][3]){
    int moveArr[2]={0,0};
    int counts=1;
    int num;
    while(checkGame(arr)!=1){
        num=counts%2;
        int checkValidMove;
        move(moveArr,num,&checkValidMove);
        while(1){
            if(arr[moveArr[0]-1][moveArr[1]-1]=='X'||arr[moveArr[0]-1][moveArr[1]-1]=='O'){
                printf("Invalid input please try again...\n");
                move(moveArr,num,&checkValidMove);
            }else{
                break;
            }
        }
        if(num==1){
            arr[moveArr[0]-1][moveArr[1]-1]='X';
            if(checkValidMove==1){
                counts=counts+1;
            } 
        }else if(num==0){
            arr[moveArr[0]-1][moveArr[1]-1]='O';
            if(checkValidMove==1){
                counts=counts+1;
            }
        }

        draw_board(arr);
        checkGame(arr);
        if(counts>=10){
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
int checkGame(char arr[][3]){
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
void move(int *moveArr,int orderOfMoves,int *checkValid){
    int row,col;
    if(orderOfMoves==1){
        printf("Player 1 (X), enter your move (row/col):");
    }else if(orderOfMoves==0){
        printf("Player 2 (Y), enter your move (row/col):");
    }
    while(1){
        char buffer;
        while (scanf("%d%d", &row, &col) != 2) { // İki tane integer girilene kadar döngü devam eder
            printf("Invalid input. Please enter two integers separated by a space.\n");
            *checkValid=0;
            while ((buffer = getchar()) != '\n' && buffer != EOF) {} // Buffer temizle
        }
        if(row>3||row<1||col>3||col<1){
            printf("Invalid input. Please enter two integers separated by a space.\n");
            *checkValid=0;
            continue;
        }else{
            *checkValid=1;
            break;
        }
    }
    moveArr[0]=row;
    moveArr[1]=col;
}
void draw_board(char arr[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%c ",arr[i][j]);
        }
        printf("\n");
    }
}
