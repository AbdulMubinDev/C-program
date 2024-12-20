#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to calculate grade based on average marks
char gradecalculate(double avg) {
    if (avg >= 90) return 'A';
    if (avg >= 75) return 'B';
    if (avg >= 60) return 'C';
    if (avg >= 50) return 'D';
    return 'F';
}

// Function to calculate the final result
void finalresult(int a, int b, int e, int i, int m, double *avg, char *grade) {
    int sum = a + b + e + i + m;
    *avg = sum / 5.0; 
    *grade = gradecalculate(*avg); 
}

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
    } while (marks < 0);
    return marks;
}

// Function to process marks and calculate results
void markchecker(const char *studentname) {
    int marksm, marksa, marksb, markse, marksi;
    char grade;
    double average;

    // Get valid marks for each subject
    marksm = get_valid_marks("Math");
    marksa = get_valid_marks("Arabic");
    marksb = get_valid_marks("Bangla");
    markse = get_valid_marks("English");
    marksi = get_valid_marks("Islam");

    // Calculate results
    finalresult(marksa, marksb, markse, marksi, marksm, &average, &grade);

    printf("\n--------------------------------------------\n");
    printf("| Student Name  | %-30s |\n", studentname);
    printf("| Average Marks | %-28.2f |\n", average);
    printf("| Grade         | %-28c |\n", grade);
    printf("--------------------------------------------\n");

    if (grade == 'F') {
        printf("| Status        | %-28s |\n", "Failed");
    } else {
        printf("| Status        | %-28s |\n", "Passed");
    }
    printf("--------------------------------------------\n");
}

// Function to handle option 1: Grade check
void option1() {
    char studentname[50];  
    int attemptsubj;
    char input[20];

    printf("\nEnter student name (Just Nickname): ");
    fgets(studentname, sizeof(studentname), stdin);
    studentname[strcspn(studentname, "\n")] = '\0'; // Remove newline character

    while (1) {
        printf("How many subjects he/she attempted (5 required): ");
        if (!fgets(input, sizeof(input), stdin)) {
            printf("Input error. Try again.\n");
            continue;
        }
        if (sscanf(input, "%d", &attemptsubj) != 1 || attemptsubj < 0) {
            printf("Invalid input. Please enter a valid number.\n");
            continue;
        }

        if (attemptsubj < 5) {
            printf("%s was already failed because he/she didn't attempt all subjects.\n", studentname);
            return;
        } else if (attemptsubj > 5) {
            printf("\nPlease enter the correct subject count because the total exam was on 5 subjects.\n");
        } else {
            break;
        }
    }

    markchecker(studentname); 
}

// Function to display routine information
void routine() {
    printf("In this season, a 5-subject test was held. Here's the routine:\n");
    printf("--------------------------------------------\n");
    printf("| Math | Arabic | Bangla | English | Islam |\n");
    printf("--------------------------------------------\n");
}

// Main function
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
