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

int main(){

    int option; 

    menu();
    
    printf("\nPlease select one option for basic mathmatics operations: ");
    scanf("%d", &option);
    printf("%d", option);
    return 0; 
}