#include <stdio.h>
#include<ctype.h>

void part1();
void counter(char filename[], char *alphabet, int *letterCounter);

int main() {
    part1();
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
