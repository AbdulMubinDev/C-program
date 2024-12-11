#include <stdio.h>
#include <string.h>
#include <ctype.h>

char gradecalculate(double a) {
    if (a >= 90) return 'A';
    if (a >= 75) return 'B';
    if (a >= 60) return 'C';
    if (a >= 50) return 'D';
    return 'F';
}

void finalresult(int a, int b, int e, int i, int m, double *avg, char *grade) {
    int sum = a + b + e + i + m;
    *avg = sum / 5.0; 
    *grade = gradecalculate(*avg); 
}

void markchecker(char studentname[]) {
    int marksm, marksa, marksb, markse, marksi;
    char grade;
    double average;

    // Function to validate input marks
    int get_valid_marks(const char *subject) {
        int marks;
        char input[20];
        do {
            printf("Marks in %s (0-100): ", subject);
            if (!fgets(input, sizeof(input), stdin)) {
                printf("Input error. Try again.\n");
                continue;
            }
            if (sscanf(input, "%d", &marks) != 1 || marks < 0 || marks > 100) {
                printf("Invalid input. Please enter marks between 0 and 100.\n");
                marks = -1; // Reset invalid marks
            }
        } while (marks < 0 || marks > 100);
        return marks;
    }

    // Get valid marks for each subject
    marksm = get_valid_marks("Math");
    marksa = get_valid_marks("Arabic");
    marksb = get_valid_marks("Bangla");
    markse = get_valid_marks("English");
    marksi = get_valid_marks("Islam");

    // Calculate results
    finalresult(marksa, marksb, markse, marksi, marksm, &average, &grade);

    printf("\n--------------------------------------------\n");
    printf("| Student Name | %-30s |
", studentname);
    printf("| Average Marks | %-28.2f |
", average);
    printf("| Grade         | %-28c |
", grade);
    printf("--------------------------------------------\n");

    if (grade == 'F') {
        printf("| Status        | %-28s |
", "Failed");
    } else {
        printf("| Status        | %-28s |
", "Passed");
    }
    printf("--------------------------------------------\n");
}

void option1() {
    char studentname[50];  
    int attemtsubj;
    char input[20];

    printf("\nEnter student name (Just Nickname): ");
    fgets(studentname, sizeof(studentname), stdin);
    studentname[strcspn(studentname, "\n")] = '\0'; // Remove newline character

    while (1) {
        printf("How many subjects he/she attempted: ");
        if (!fgets(input, sizeof(input), stdin)) {
            printf("Input error. Try again.\n");
            continue;
        }
        if (sscanf(input, "%d", &attemtsubj) != 1 || attemtsubj < 0) {
            printf("Invalid input. Please enter a valid number.\n");
            continue;
        }

        if (attemtsubj < 5) {
            printf("%s was already failed because he/she didn't attempt all subjects.\n", studentname);
            return;
        } else if (attemtsubj > 5) {
            printf("\nPlease enter the correct subject count because the total exam was on 5 subjects.\n");
        } else {
            break;
        }
    }

    markchecker(studentname); 
}

void routine() {
    printf("In this season 5 subject test held. Here's the routine:\n");
    printf("--------------------------------------------\n");
    printf("| Math | Arabic | Bangla | English | Islam |
");
    printf("--------------------------------------------\n");
}

int main() {
    int optioncheck;
    char input[20];

    printf("Welcome To Our Grade System!!!\n");

    while (1) {
        printf("\nPlease select an option by number:\n|1| Grade check    |2| Info > ");
        if (!fgets(input, sizeof(input), stdin)) {
            printf("Input error. Try again.\n");
            continue;
        }
        if (sscanf(input, "%d", &optioncheck) != 1 || (optioncheck != 1 && optioncheck != 2)) {
            printf("Invalid option. Please select 1 or 2.\n");
            continue;
        }
        break;
    }

    if (optioncheck == 1) {
        option1(); 
    } else {
        routine(); 
    }

    printf("\nDeveloped by @AbdulMubinDev\n");
    return 0;
}
