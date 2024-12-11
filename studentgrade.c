#include <stdio.h>
#include <string.h>

// Function to calculate grade based on average
char gradecalculate(double a) {
    if (a >= 90) return 'A';
    if (a >= 75) return 'B';
    if (a >= 60) return 'C';
    if (a >= 50) return 'D';
    return 'F';
}

// Function to calculate the final result: average and grade
void finalresult(int a, int b, int e, int i, int m, double *avg, char *grade) {
    int sum = a + b + e + i + m;
    *avg = sum / 5.0; // Correct division (float)
    *grade = gradecalculate(*avg); // Get grade based on average
}

// Function to check marks and calculate final results
void markchecker(char studentname[]) {
    int marksm, marksa, marksb, markse, marksi;
    char grade;
    double average;

    printf("Marks in Math: ");
    scanf("%d", &marksm);

    printf("Marks in Arabic: ");
    scanf("%d", &marksa);

    printf("Marks in Bangla: ");
    scanf("%d", &marksb);

    printf("Marks in English: ");
    scanf("%d", &markse);

    printf("Marks in Islam: ");
    scanf("%d", &marksi);

    finalresult(marksa, marksb, markse, marksi, marksm, &average, &grade); // Pass by reference
    printf("Student Name: %s\n", studentname);
    printf("Average Marks: %.2f\n", average);
    printf("Grade: %c\n", grade);
    
    if (grade == 'F') {
        printf("Status: Failed\n");
    } else {
        printf("Status: Passed\n");
    }
}

// Function to check student information and validate subject count
void option1() {
    char studentname[50];  // Fixed size for student name
    int attemtsubj;

    printf("\nEnter student name (Just Nickname): ");
    scanf("%s", studentname);
    printf("How many subjects he/she attempted: ");
    scanf("%d", &attemtsubj);

    if (attemtsubj < 5) {
        printf("%s already failed because he/she didn't attempt all subjects.\n", studentname);
    } else if (attemtsubj > 5) {
        printf("\nPlease enter the correct subject count because the total exam was on 5 subjects.\n");
        option1(); // Recursive call to correct input
    } else {
        markchecker(studentname); // Pass student name to markchecker
    }
}

// Function to display routine information
void routine() {
    printf("In this season 5 subject test held. Here's the routine:\n");
    printf("--------------------------------------------\n");
    printf("| Math | Arabic | Bangla | English | Islam |\n");
    printf("--------------------------------------------\n");
}

// Main function to drive the program
int main() {
    int optioncheck;

    printf("Welcome To Our Grade System!!!\n");

    printf("\nPlease select an option by number:\n|1| Grade check    |2| Info > ");
    scanf("%d", &optioncheck);

    if (optioncheck == 1) {
        option1(); // Call grade check
    } else {
        routine(); // Call routine info
    }

    return 0;
}
