#include <stdio.h>
/*This is the initial include statement with necessary dependencies*/
int calc_score_opps(int score, int td_8, int td_7, int td_6, int fg, int safety) {
    if (score < 0) {
        return 0;
    }
/*If the score is less than 0, the function will return 0, which is the equivalent of doing nothing*/
    if (score == 0) {
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_8, td_7, td_6, fg, safety);
    }
/*If the score is equal to 0, the program will print the active count for each scoring option before going back into the recursive function.*/

    if ((score - 8) >= 0 && (score - 8) != 1) {
        calc_score_opps(score - 8, td_8 + 1, td_7, td_6, fg, safety);
    }
/*If the score minus 8 is greater than or equal to 0 and not one, the function will call itself again with the "td_8" count increased by one*/
    if ((score - 7) >= 0 && (score - 7) != 1) {
        calc_score_opps(score - 7, td_8, td_7 + 1, td_6, fg, safety);
    }
/*If the score minus 7 is greater than or equal to 0 and not one, the function will call itself again with the "td_7" count increased by one*/
    if ((score - 6) >= 0 && (score - 6) != 1) {
        calc_score_opps(score - 6, td_8, td_7, td_6 + 1, fg, safety);
    }
/*If the score minus 6 is greater than or equal to 0 and not one, the function will call itself again with the "td_6" count increased by one*/
    if ((score - 3) >= 0 && (score - 3) != 1) {
        calc_score_opps(score - 3, td_8, td_7, td_6, fg + 1, safety);
    }
/*If the score minus 3 is greater than or equal to 0 and not one, the function will call itself again with the "fg" count increased by one*/
    if ((score - 2) >= 0 && (score - 2) != 1) {
        calc_score_opps(score - 2, td_8, td_7, td_6, fg, safety + 1);
    }
/*If the score minus 2 is greater than or equal to 0 and not one, the function will call itself again with the "safety" count increased by one*/
}

int main() {
    int score = 2;
    int td_8 = 0;
    int td_7 = 0;
    int td_6 = 0;
    int fg = 0;
    int safety = 0;
/*These are values that will be utilized later on in the code, but they are declared and assigned values here*/
    while (score >= 2) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        calc_score_opps(score, td_8, td_7, td_6, fg, safety);
    }
/*This asks the user for an NFL score until the user inputs a value that is less than zero. It then runs the calculate score opportunities function*/
    printf("Program Terminated");
    return(0);
/*This code prints that the code has ended and returns 0 as the final value.*/
}