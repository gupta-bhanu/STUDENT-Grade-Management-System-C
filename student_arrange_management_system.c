#include<stdio.h>
#include<string.h>

int main() {
    int num;
    printf("ENTER THE NUMBER OF STUDENTS: ");
    scanf("%d", &num);

    // FIX 1: You must initialize this to calculate the array size correctly
    int no_of_subjects = 1; 

    // Unit 2: Declaring 2D arrays based on user input
    char name[num][50];
    char roll[num][20];
    float marks[num]; // FIX 2: This should be sized 'num' to store 1 mark per student
    
    char search_name[50];
    char search_roll[20];
    int choice; // FIX 3: Added a variable for the switch case
    int found = 0;

    printf("\n---- BHANU GRADING SYSTEM ----\n");

    for (int i = 0; i < num; i++) {
        printf("\nENTER DETAILS FOR STUDENT %d:\n", i + 1);
        printf("NAME: ");
        scanf("%s", name[i]);
        printf("REGISTRATION NUMBER: ");
        scanf("%s", roll[i]);
        printf("MARKS (OUT OF 100): ");
        scanf("%f", &marks[i]);
    }

    printf("\n---- SEARCH STUDENT RESULT ----\n");
    printf("1. Search by Name\n2. Search by Registration Number\n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &choice); // FIX 4: Input for the switch

    switch (choice) {
        case 1:
            printf("Enter name to search: ");
            scanf("%s", search_name);

            for(int i = 0; i < num; i++) {
                if(strcmp(name[i], search_name) == 0) { // Unit 3: String comparison
                    printf("\nStudent Found!\n");
                    printf("Reg No: %s\n", roll[i]);
                    printf("Marks: %.2f\n", marks[i]);
                    
                    // Grade logic from Unit 2
                    if(marks[i] >= 90) printf("Grade: O (Outstanding)\n");
                    else if(marks[i] >= 80) printf("Grade: A+\n");
                    else if(marks[i] >= 70) printf("Grade: A\n");
                    else if(marks[i] >= 50) printf("Grade: Pass\n");
                    else printf("Grade: Fail\n");

                    found = 1;
                }
            }
            break;

        case 2: 
            printf("Enter registration number to search: ");
            scanf("%s", search_roll);

            for(int i = 0; i < num; i++) {
                if(strcmp(roll[i], search_roll) == 0) {
                    printf("\nStudent Found!\n");
                    printf("Name: %s\n", name[i]);
                    printf("Marks: %.2f\n", marks[i]);
                    
                    if(marks[i] >= 90) printf("Grade: O (Outstanding)\n");
                    else if(marks[i] >= 80) printf("Grade: A+\n");
                    else if(marks[i] >= 70) printf("Grade: A\n");
                    else if(marks[i] >= 50) printf("Grade: Pass\n");
                    else printf("Grade: Fail\n");

                    found = 1;
                }
            }
            break;

        default:
            printf("Incorrect input\n");
            break;
    }

    if(found == 0) {
        printf("\nStudent not found in the database.\n");
    }

    return 0;
}