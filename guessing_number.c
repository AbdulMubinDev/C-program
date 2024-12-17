#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    int random, attempt = 0, guess;
    char input[20];

    srand(time(NULL));
    random = (rand() % 100) + 1; 
    printf("Welcome To This Guessing Game!!!\n");

    while (1) {
        printf("Guess a number between 1 to 100: ");
        if (!fgets(input, sizeof(input), stdin)) {
            printf("Input error. Try again.\n");
            continue;
        }

        if (sscanf(input, "%d", &guess) != 1) {
            printf("Invalid input. Please enter a numeric value between 1 and 100.\n");
            continue;
        }

        if (guess < 1 || guess > 100) {
            printf("Invalid input. Please enter a number between 1 and 100.\n");
            continue;
        }

        attempt++;

        if (guess > random) {
            printf("\nGuess smaller number\n");
        } else if (guess < random) {
            printf("\nGuess larger number\n");
        } else {
            printf("\nCongratulations to You !!!!\nYou won the game and your total attempt was %d\n", attempt);
            printf("\nDeveloped by @AbdulMubinDev\n");
            break;
        }
    }

    return 0;
}