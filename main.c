/*
 Yusuf Saraçlıoğlu
 Date: 2022-05-22
 Intro to C Programming EHB 110E
 CRN:25333 Homework #2
 You can compile this code with Clion, Code::Blocks, Visual Studio, etc.
 Also you can compile in the following way:
 gcc main.c -o main.exe
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define DICEROLLCOUNT 10000
#define SCALEFACTOR 100


void onediceRoll() {
    int diceRolls[6] = {0, 0, 0, 0, 0, 0}; //Array to store the frequency of each dice roll
    int i;

    srand(time(NULL)); //Seed the random number generator

    for (i; i <= DICEROLLCOUNT; i++) { //Loop through the dice rolls
        diceRolls[rand() % 6]++;
    }

    printf("\nYou rolled one dice:\n");

    // get the maximum value of the array
    int h_max = 0;
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        if (diceRolls[i] > h_max) {
            h_max = diceRolls[i];
        }
    }
    // maximum value of the array / scale factor
    int max_height = h_max / SCALEFACTOR;

    // print the histogram vertically
    int k;
    for (k = max_height; k >= 0; k--) {
        for (int j = 0; j < 6; j++) {
            if (diceRolls[j] >= k * SCALEFACTOR) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("1 2 3 4 5 6\n"); // print the horizontal axis
}

void twodiceRoll() {
    // Now instead of one dice, create a simulation of two dice rolled at the same time 10000 times. At the end of each
    //roll, count the frequency of the sum of the values of the two dice.
    int diceRolls[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //Array to store the frequency of each dice roll
    int i;

    srand(time(NULL)); //Seed the random number generator

    for (i; i <= DICEROLLCOUNT; i++) { //Loop through the dice rolls
        diceRolls[(rand() % 6) + (rand() % 6)]++;
    }

    printf("\nYou rolled two dice:\n");

    // get the maximum value of the array
    int h_max = 0;
    int sum = 0;

    for (int i = 0; i < 12; i++) {
        if (diceRolls[i] > h_max) {
            h_max = diceRolls[i];
        }
    }
    // maximum value of the array / scale factor
    int max_height = h_max / SCALEFACTOR;

    // print the histogram vertically
    int k;
    for (k = max_height; k >= 0; k--) {
        for (int j = 0; j < 12; j++) {
            if (diceRolls[j] >= k * SCALEFACTOR) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("2 3 4 5 6 7 8 9 10 11 12\n"); // print the horizontal axis

}

int main() {
    onediceRoll();
    twodiceRoll();
    system("pause");
    return 0;
}

