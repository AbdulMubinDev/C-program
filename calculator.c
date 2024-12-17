#include <stdio.h>

void menu() {
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

double getNumber() {
    double num;
    while (1) {
        if (scanf("%lf", &num) == 1) {
            return num;
        } else {
            printf("\nInvalid input! Please enter a valid number: ");
            while (getchar() != '\n'); 
        }
    }
}

int addition() {
    double num1, num2, result;
    char choice;
    printf("Let's do some Addition :)\n");
    printf("First enter your first number: ");
    num1 = getNumber();
    printf("Now enter the second number: ");
    num2 = getNumber();
    result = num1 + num2;
    printf("This is your result: %.2lf\n", result);

    while (1) {
        printf("Press # to return to the main menu, 0 to close the program, or 'c' to redo addition: ");
        scanf(" %c", &choice);
        while (getchar() != '\n');
        if (choice == '#') {
            return 1;
        } else if (choice == '0') {
            printf("Bye! See you again :)\n");
            return 0;
        } else if (choice == 'c') {
            return addition();
        } else {
            printf("Invalid option! Please try again.\n");
        }
    }
}

int subtraction() {
    double num1, num2, result;
    char choice;
    printf("Let's do some Subtraction :)\n");
    printf("First enter your first number: ");
    num1 = getNumber();
    printf("Now enter the second number: ");
    num2 = getNumber();
    result = num1 - num2;
    printf("This is your result: %.2lf\n", result);

    while (1) {
        printf("Press # to return to the main menu, 0 to close the program, or 'c' to redo subtraction: ");
        scanf(" %c", &choice);
        while (getchar() != '\n'); 

        if (choice == '#') {
            return 1;
        } else if (choice == '0') {
            printf("Bye! See you again :)\n");
            return 0;
        } else if (choice == 'c') {
            return subtraction();
        } else {
            printf("Invalid option! Please try again.\n");
        }
    }
}

int multiplication() {
    double num1, num2, result;
    char choice;
    printf("Let's do some Multiplication :)\n");
    printf("First enter your first number: ");
    num1 = getNumber();
    printf("Now enter the second number: ");
    num2 = getNumber();
    result = num1 * num2;
    printf("This is your result: %.2lf\n", result);

    while (1) {
        printf("Press # to return to the main menu, 0 to close the program, or 'c' to redo multiplication: ");
        scanf(" %c", &choice);
        while (getchar() != '\n'); 

        if (choice == '#') {
            return 1;
        } else if (choice == '0') {
            printf("Bye! See you again :)\n");
            return 0;
        } else if (choice == 'c') {
            return multiplication();
        } else {
            printf("Invalid option! Please try again.\n");
        }
    }
}

int division() {
    double num1, num2, result;
    char choice;
    printf("Let's do some Division :)\n");
    printf("First enter your first number: ");
    num1 = getNumber();
    printf("Now enter the second number: ");
    while (1) {
        num2 = getNumber();
        if (num2 != 0) break;
        printf("Division by zero is not allowed! Please enter another number: ");
    }
    result = num1 / num2;
    printf("This is your result: %.2lf\n", result);

    while (1) {
        printf("Press # to return to the main menu, 0 to close the program, or 'c' to redo division: ");
        scanf(" %c", &choice);
        while (getchar() != '\n'); 

        if (choice == '#') {
            return 1;
        } else if (choice == '0') {
            printf("Bye! See you again :)\n");
            return 0;
        } else if (choice == 'c') {
            return division();
        } else {
            printf("Invalid option! Please try again.\n");
        }
    }
}

int main() {
    int option;

    do {
        menu();
        printf("\nPlease select one option for basic mathematics operations: ");
        if (scanf("%d", &option) != 1) {
            printf("Invalid input! Please enter a valid option.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (option) {
            case 1:
                if (addition() == 0) return 0;
                break;
            case 2:
                if (subtraction() == 0) return 0;
                break;
            case 3:
                if (multiplication() == 0) return 0;
                break;
            case 4:
                if (division() == 0) return 0;
                break;
            case 0:
                printf("Bye! See you again :)\n");
                return 0;
            default:
                printf("Oops! You may have entered the wrong option. Try again.\n");
                break;
        }
    } while (1);

    return 0;
}
