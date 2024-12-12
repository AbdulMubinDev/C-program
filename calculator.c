#include <stdio.h>

void menu(){
    
    printf("Welcome to this beginner project made by @AbdulMubinDev\n\n");
    printf("=========================================\n");
    printf("|                   MENU                |\n");
    printf("=========================================\n");
    printf("|  1. Addition       |  2. Subtraction  |\n");
    printf("|--------------------|------------------|\n");
    printf("|  3. Multiplication |  4. Division     |\n");
    printf("|---------------------------------------|\n");
    printf("|               0. Close                |\n");
    printf("========================================\n");
}

int addition(){
    int num1, num2, result; 

    printf("Let's do some Addition :) ");
    printf("\nFirst enter your first number: ");
    scanf("%d", &num1);

    printf("Now enter the second number: ");
    scanf("%d", &num2);

    result = num1 + num2; 
    printf("This is your result: %d", result);
}

int subtraction(){
    int num1, num2, result; 

    printf("Let's do some Substraction :) ");
    printf("\nFirst enter your first number: ");
    scanf("%d", &num1);

    printf("Now enter the second number: ");
    scanf("%d", &num2);

    result = num1 - num2; 
    printf("This is your result: %d", result);
}

int multiplication(){
    int num1, num2, result; 

    printf("Let's do some Multiplication :) ");
    printf("\nFirst enter your first number: ");
    scanf("%d", &num1);

    printf("Now enter the second number: ");
    scanf("%d", &num2);

    result = num1 * num2; 
    printf("This is your result: %d", result);
}

int division(){
    int num1, num2, result; 

    printf("Let's do some Division :) ");
    printf("\nFirst enter your first number: ");
    scanf("%d", &num1);

    printf("Now enter the second number: ");
    scanf("%d", &num2);

    result = num1 / num2; 
    printf("This is your result: %d", result);
}


int main(){

    int option; 

    menu();

    printf("\nPlease select one option for basic mathmatics operations: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1 :
        addition();
        break;
    case 2 :
        subtraction();
        break;
    case 3 : 
        multiplication();
        break;
    case 4 :
        division();
        break;  
    case 0 :
        printf("Bye see you again :)");
        return 0;
        break;

    default:
        printf("Opss you maybe enter wrong option :} Try again");
        break;
    }
    return 0; 
}