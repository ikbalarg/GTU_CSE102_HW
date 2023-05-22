#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char board[3][3];
} board;

void printBoard(board *board) {
    FILE *file = fopen("board.txt", "a");  // Dosyayı "a" (append) modunda aç
    
    if (file == NULL) {
        printf("Dosya açma hatası!\n");
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board->board[i][j]);
            fprintf(file, "%c ", board->board[i][j]);  // Dosyaya yaz
        }
        printf("\n");
        fprintf(file, "\n");  // Dosyaya yeni satır ekle
    }
    printf("\n");
    fprintf(file, "\n");  // Dosyaya boş bir satır ekle

    fclose(file);  // Dosyayı kapat
}

void shuffleBoard(board *board) {
    // Başlangıç durumu
    char initialBoard[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '_'}
    };
    
    // Başlangıç durumu tahtaya kopyalanır
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board->board[i][j] = initialBoard[i][j];
        }
    }
    
    // Tahtayı rastgele karıştırma
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
int isValidInput(int number, char dash, char direction) {
    if (number >= 1 && number <= 8) {
        if (dash == '-') {
            if (direction == 'L' || direction == 'R' || direction == 'U' || direction == 'D') {
                return 1; // Valid inpput
            }
        }
    }
    return 0; // Invalid input
}
void makeMove(board *board1, int number, char direction) {
    int i, j;
    int found = 0;
    char memory;
    printf("makemove\n");
    // İstenen sayının konumunu bulma
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            int ch = board1->board[i][j] - '0';
            if (ch== number) { // board1 kullanılmalı
                found = 1;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    printf("i %d j %d\n",i,j);
    // İstenen yöne göre hareket ettirme
    if (direction == 'R') {
        if (j < 2) { // board1 kullanılmalı
            memory=board1->board[i][j+1];
            board1->board[i][j+1] = number+'0'; // board
            board1->board[i][j] = memory; // board1 kullanılmalı
        } else {
            printf("Hatalı hareket! Lütfen geçerli bir hareket yapın.\n");
            return;
        }
    } else if (direction == 'L') {
        if (j > 0) { // board1 kullanılmalı
            memory=board1->board[i][j-1];
            board1->board[i][j - 1] = number+'0'; // board1 kullanılmalı
            board1->board[i][j] = memory; // board1 kullanılmalı
        } else {
            printf("Hatalı hareket! Lütfen geçerli bir hareket yapın.\n");
            return;
        }
    } else if (direction == 'U') {
        printf("u\n");
        if (i > 0) { // board1 kullanılmalı
            memory=board1->board[i-1][j];
            board1->board[i - 1][j] = number+'0'; // board1 kullanılmalı
            board1->board[i][j] = memory; // board1 kullanılmalı
        } else {
            printf("Hatalı hareket! Lütfen geçerli bir hareket yapın.\n");
            return;
        }
    } else if (direction == 'D') {
        if (i < 2) { // board1 kullanılmalı
            memory=board1->board[i + 1][j];
            board1->board[i + 1][j] = number+'0'; // board1 kullanılmalı
            board1->board[i][j] = memory; // board1 kullanılmalı
        } else {
            printf("Hatalı hareket! Lütfen geçerli bir hareket yapın.\n");
            return;
        }
    } else {
        printf("Hatalı hareket! Lütfen geçerli bir hareket yapın.\n");
        return;
    }
    return;
}
int checkGame(board *board1){
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
void playGameWithUser() {
    board board1;
    int moves=0,number;
    shuffleBoard(&board1);
    printBoard(&board1);
    char direction,dash;
    int check=0;
    while(checkGame(&board1)==0){
        int validInput = 0;
        while (!validInput) {
            printf("Enter your move (number-direction,e.g.,2-R): ");
            int scanned = scanf("%d %c %c", &number, &dash,&direction);
            //direction = getchar();
            printf("%c",dash);
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            if(dash!='-'){
                printf("Invalid input. You must put a hyphen between number and position\n");
                int j;
                while ((j = getchar()) != '\n' && j != EOF);
                continue;
            }
            else{
                if (scanned != 3 || !isValidInput(number, dash, direction)) {
                    printf("1.Hatalı giriş! Lütfen doğru formatta bir girdi girin.\n");
                } else {
                    validInput = 1;
                }
            }
        }
        makeMove(&board1,number,direction);
        printBoard(&board1);
        printf("%d",checkGame(&board1));
        //check=checkGame();
    }
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
                // Otomatik olarak oyunu bitirme fonksiyonunu çağır
                // autoFinish();
                break;
            case 3:
                // En iyi skoru gösterme fonksiyonunu çağır
                // showBestScore();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Geçersiz bir seçim yaptınız!\n");
                break;
        }
    }
}
int main() {
    
   MainMenu();
    
    return 0;
}
