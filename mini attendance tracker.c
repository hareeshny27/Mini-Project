#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[50];
    int present; // 1 = Present, 0 = Absent
};

struct Student s[100];
int count = 0;

// Add Student
void addStudent() {
    printf("\nEnter Roll Number: ");
    scanf("%d", &s[count].roll);

    printf("Enter Name: ");
    scanf("%s", s[count].name);

    s[count].present = 0; // default absent
    count++;

    printf("Student added successfully!\n");
}

// Mark Attendance
void markAttendance() {
    int roll, found = 0;

    printf("\nEnter Roll Number: ");
    scanf("%d", &roll);

    for(int i = 0; i < count; i++) {
        if(s[i].roll == roll) {
            printf("Enter Attendance (1 = Present, 0 = Absent): ");
            scanf("%d", &s[i].present);
            found = 1;
            printf("Attendance updated!\n");
            break;
        }
    }

    if(found == 0) {
        printf("Student not found!\n");
    }
}

// View Attendance + Percentage
void viewAttendance() {
    if(count == 0) {
        printf("\nNo student records found!\n");
        return;
    }

    int presentCount = 0;

    printf("\n--- Attendance Records ---\n");

    for(int i = 0; i < count; i++) {
        printf("Roll: %d | Name: %s | Status: %s\n",
               s[i].roll,
               s[i].name,
               s[i].present ? "Present" : "Absent");

        if(s[i].present == 1)
            presentCount++;
    }

    float percentage = (presentCount * 100.0) / count;

    printf("\nTotal Students: %d", count);
    printf("\nPresent: %d", presentCount);
    printf("\nAttendance Percentage: %.2f%%\n", percentage);
}

// Save to File
void saveToFile() {
    FILE *fp = fopen("attendance.txt", "w");

    if(fp == NULL) {
        printf("File error!\n");
        return;
    }

    for(int i = 0; i < count; i++) {
        fprintf(fp, "%d %s %d\n",
                s[i].roll,
                s[i].name,
                s[i].present);
    }

    fclose(fp);
    printf("Records saved to file successfully!\n");
}

int main() {
    int choice;

    do {
        printf("\n===== MINI ATTENDANCE TRACKER =====\n");
        printf("1. Add Student\n");
        printf("2. Mark Attendance\n");
        printf("3. View Attendance\n");
        printf("4. Save Records\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent();
                break;

            case 2:
                markAttendance();
                break;

            case 3:
                viewAttendance();
                break;

            case 4:
                saveToFile();
                break;

            case 5:
                printf("Thank you! Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 5);

    return 0;
}