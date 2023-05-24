#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char board[3][3];
    int number;
    int direction;
    int hamle;
} board;

void printBoard(board *board) {
    FILE *file = fopen("board.txt", "a");  // Open file in "a" (append) mode
    
    if (file == NULL) {
        printf("File opening error!\n");
        return;
    }

    for (int i = 0; i < 3; i++) { //print lines
        for (int j = 0; j < 3; j++) { //print columns
            printf("%c ", board->board[i][j]);
            fprintf(file, "%c ", board->board[i][j]); //write to file
        }
        printf("\n");
        fprintf(file, "\n"); 
    }
    printf("\n");
    fprintf(file, "\n"); 

    fclose(file);  // close file
}
int isValidInput(int number, char dash, char direction) {//returns 1 if it is a valid move, returns 0 if it is an erroneous move
    if (number >= 1 && number <= 8) {
        if (dash == '-') {
            if (direction == 'L' || direction == 'R' || direction == 'U' || direction == 'D') {
                return 1; // Valid inpput
            }
        }
    }
    return 0; // Invalid input
}
void shuffleBoard(board *board) {//this function creates the board and then mixes this board.
    // Başlangıç durumu
    char initialBoard[3][3] = { //create a solved board
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '_'}
    };
    //the created board is copied to the board struct
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board->board[i][j] = initialBoard[i][j];
        }
    }
    
    // Randomly shuffling the board
    srand(time(NULL));
    
    for (int i = 2; i >= 0; i--) {
        for (int j = 2; j >= 0; j--) {
            int randomI = rand() % (i + 1);
            int randomJ = rand() % (j + 1);
            
            char temp = board->board[i][j];
            board->board[i][j] = board->board[randomI][randomJ];
            board->board[randomI][randomJ] = temp;
        }
    }
}
int checkGame(board *board1){ //this function checks if the game is over. If the game is over it returns 1, otherwise it returns 0.
    char a00,a01,a02,a10,a11,a12,a20,a21,a22;
    a00=board1->board[0][0];
    a01=board1->board[0][1];
    a02=board1->board[0][2];
    a10=board1->board[1][0];
    a11=board1->board[1][1];
    a12=board1->board[1][2];
    a20=board1->board[2][0];
    a21=board1->board[2][1];
    a22=board1->board[2][2];
    if(a00=='1'&&a01=='2'&&a02=='3'&&a10=='4'&&a11=='5'&&a12=='6'&&a20=='7'&&a21=='8'&&a22=='_'){
        return 1;
    }else{
        return 0;
    }
}
int makeMove(board *board1, int number, char direction) { //this function is used when the board is solved by the user.allows movement on the board
    int i, j;
    int found = 0;
    char memory;
    // Find the position of the desired number
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            int ch = board1->board[i][j] - '0';
            if (ch== number) { 
                found = 1;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    // Move according to the desired direction
    if (direction == 'R') {
        if (j < 2) { //check the right side
            memory=board1->board[i][j+1];
            board1->board[i][j+1] = number+'0';
            board1->board[i][j] = memory; 
        } else {
            printf("Invalid input please try again\n");
            return 0;
        }
    } else if (direction == 'L') {
        if (j > 0) { //  //check the left side
            memory=board1->board[i][j-1];
            board1->board[i][j - 1] = number+'0'; 
            board1->board[i][j] = memory; 
        } else {
            printf("Invalid input please try again\n");
            return 0;
        }
    } else if (direction == 'U') {
        if (i > 0) { //check the top side
            memory=board1->board[i-1][j];
            board1->board[i - 1][j] = number+'0';
            board1->board[i][j] = memory; 
        } else {
            printf("Invalid input please try again\n");
            return 0;
        }
    } else if (direction == 'D') {
        if (i < 2) { //check the underside
            memory=board1->board[i + 1][j];
            board1->board[i + 1][j] = number+'0'; 
            board1->board[i][j] = memory; 
        } else {
            printf("Invalid input please try again\n");
            return 0;
        }
    } else {
        printf("Invalid input please try again\n");
        return 0;
    }
    return 1;
}
int findNumberBoard(board *board1,char direction,int number){//this function is used when solving the board computer.
    //The computer finds the position of the randomly selected number in the board array and then checks the validity of the desired position. If valid, 1 is returned.
    int i, j;
    int found = 0;
    for (i = 0; i < 3; i++) { //find number
        for (j = 0; j < 3; j++) {
            int ch = board1->board[i][j] - '0';
            if (ch== number) { 
                found = 1;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    if(direction=='R'){ //check the right side 
        if(j==2){
            return 0;
        }else{
            return 1;
        }
    }
    else if(direction=='L'){ //check the left side 
        if(j==0){
            return 0;
        }else{
            return 1;
        }
    }
    else if(direction=='U'){ //check the top side
        if(i==0){
            return 0;
        }else{
            return 1;
        }
    }
    else if(direction=='D'){ //check the underside
        if(i==2){
            return 0;
        }else{
            return 1;
        }
    }
    return 2;
}
void autoFinish(board *board1) { //this function decodes the board to the computer.
    if (checkGame(board1) == 1) { //terminate the function if the board is solved
        printf("The board is solved!\n");
        printBoard(board1);
        return;
    }
    struct Combination {
        int number;
        char direction;
    }; //created a structer for all possible combinations on the board
    struct Combination combinations[] = {
        {1, 'L'},
        {1, 'R'},
        {1, 'U'},
        {1, 'D'},
        {2, 'L'},
        {2, 'R'},
        {2, 'U'},
        {2, 'D'},
        {3, 'L'},
        {3, 'R'},
        {3, 'U'},
        {3, 'D'}
    };
    int numCombinations = sizeof(combinations) / sizeof(combinations[0]);
    // Select a random combination
    int randomIndex = rand() % numCombinations;
    int number = combinations[randomIndex].number;
    char direction = combinations[randomIndex].direction;
    // Apply the selected combination on the board
    if (makeMove(board1, number, direction) == 1) {
        printf("Computer move: %d-%c\n", number, direction);
        printBoard(board1);
        board1->hamle=board1->hamle+1;
        //printf("Hamle: %d",board1->hamle);
    }
    
    autoFinish(board1);
}
void write_best_score(int score) {
    FILE *file = fopen("best_score.txt", "r+");
    if (file == NULL) {
        printf("An error occurred while opening the file.\n");
        return;
    }
    if(feof(file)){
    	fprintf(file,"%d",score);
    }
    else{
    	int current_score;
    	fscanf(file, "%d", &current_score);

    	if (score > current_score) {
       	 rewind(file);  // Back to the beginning of the file

       	 fprintf(file, "%d", score);  // write score to file
	
            // Delete the rest of the file
       	 int c;
        	while ((c = fgetc(file)) != EOF) {
         	   fputc(' ', file);
       	 }
   	 }
    }
    fclose(file);
}
void print_best_score() {
    FILE *file = fopen("best_score.txt", "r"); //open the file
    if (file == NULL) {
        printf("An error occurred while opening the file.\n");
        return;
    }

    int best_score;
    fscanf(file, "%d", &best_score);  // read the score in the file
    printf("The best score is %d...\n", best_score);

    fclose(file);
}
void playGameWithUser() {//this function makes the user solve the board.
    board board1; 
    int moves=0,number;
    shuffleBoard(&board1);//create board 
    printBoard(&board1); //print the first version of the board
    char direction,dash;
    int check=0,validMove;
    while(checkGame(&board1)==0){ //this block will last until the end of the game.
        int validInput = 0;
        while (!validInput) { //this block continues until correct input is received from the user.
            printf("Enter your move (number-direction,e.g.,2-R): ");
            int scanned = scanf("%d %c %c", &number, &dash,&direction);//receive number, sign and location from the user
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            if(dash!='-'){ //if the sign is not a hyphen, suppress the error message and ask again
                printf("Invalid input. You must put a hyphen between number and position\n");
                int j;
                while ((j = getchar()) != '\n' && j != EOF);
                continue;
            }
            else{
                if (scanned != 3 || !isValidInput(number, dash, direction)) {
                    printf("Invalid input.Please try again...\n");
                } else {
                    validInput = 1;
                }
            }
        }
        if(makeMove(&board1,number,direction)==1){ //move to the desired position
            printf("\n");
            printBoard(&board1);
            moves=moves+1;
        }
    }
    int score = 1000-10*moves; //calculate score
    printf("Congratulations! You finished the game.\n");
    printf("Total number of moves : %d\n",moves);
    printf("Your Score : %d\n",score);
    write_best_score(score);//send the score to the write_best_score function and if it is the best score it will write it to the file
}
void MainMenu() {
    board board1;
    int choice;

    while (1) {
        printf("Welcome to the 8-Puzzle Game!\n");
        printf("Please select an option:\n");
        printf("1. Play game as a user\n");
        printf("2. Finish the game with PC\n");
        printf("3. Show the best score\n");
        printf("4. Exit\n> ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input please try again!\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        switch (choice) {
            case 1:
                //playGame();
                playGameWithUser();
                break;
            case 2:
                shuffleBoard(&board1);
                printBoard(&board1);
                autoFinish(&board1);
                printf("Total number of computer moves : %d\n",board1.hamle);
                board1.hamle=0;
                break;
            case 3:
                print_best_score();
                break;
            case 4:
                printf("Program terminated ...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice...\n");
                break;
        }
    }
}
int main() {
    srand(time(NULL));
   MainMenu();
    
    return 0;
}
