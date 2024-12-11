#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int random ; 
    int attempt = 0 ;
    int guess ; 

    srand(time(NULL));

    random = (rand() % (100 - 1 +1)) + 1;

    printf("Welcome To This Guessing Game!!!\n");
    do
    {
        printf("Guess a number between 1 to 100: ");
        scanf("%d", &guess);
        attempt++;

        if (guess > random)
        {
            printf("\nGuess smaller number\n");
        }else if (guess < random)
        {
            printf("\nGuess larger number\n");
        }else if (guess > 100)
        {
            printf("Please select between this number-->(1 - 100)");
        }else {
            printf("\nCongratulations to You !!!!\nYou won the game and your total attempt was %d", attempt);
            printf("\nDeveloped by @AbdulMubinDev");
        }
        
        
    } while (random != guess);
    

    return 0; 
}