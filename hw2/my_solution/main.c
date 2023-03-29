
#include <stdio.h>
#include "util.h"
int main(){
    /*----------------Part1----------------------*/
    int year;
    printf("Please enter a year: ");
    scanf("%d",&year);
    leap_year(year);
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { } //clean buffer
    /*----------------Part2----------------------*/
    enhanced_calculator();
    int j;
    while ((j = getchar()) != '\n' && j != EOF) { } //clean buffer
  /*----------------Part3----------------------*/
    grade_calculator();
    /*----------------Part2----------------------*/
    //enhanced_calculator();
  
    return 0;
}
