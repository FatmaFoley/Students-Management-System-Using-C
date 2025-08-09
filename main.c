/*
 * main.c
 *
 *  Created on: Aug 9, 2025
 *      Author: Fatma Foley
 */

#include <stdio.h>
#include "functions.h"

int main()
{
    int exit = 1;       // Control variable for the main loop; exit = 0 to quit program
    int choice;         // Variable to store user's menu choice
    struct student st;  // Temporary student structure to hold input data

    // Main program loop – runs until the user chooses to exit
    while(exit)
    {
        // Display the menu options to the user
        printf("______________________________________________\n\n");
        printf("choose one of the Menu Options:\n");
        printf("press 1 to Add a Student\n");
        printf("press 2 to Display All Students\n");
        printf("press 3 to Search for a Student by ID\n");
        printf("press 4 to Update Student Information\n");
        printf("press 5 to Delete a Student by ID\n");
        printf("press 6 to Calculate Average GPA\n");
        printf("press 7 to Find Student with Highest GPA\n");
        printf("press 8 to Exit\n");
        printf("______________________________________________\n\n");
        fflush(stdout);

        // Read user's choice from standard input
        scanf("%d", &choice);

        // Handle user choice via switch-case
        switch(choice)
        {
            case 1:
                // Add a new student: prompt for details
                printf("Enter the student ID:\n");
                fflush(stdout);
                scanf("%d", &(st.id));

                printf("Enter the student name:\n");
                fflush(stdout);
                // Clear leftover newline from input buffer before using gets
                while (getchar() != '\n');
                gets(st.name);

                printf("Enter the student age:\n");
                fflush(stdout);
                scanf("%d", &(st.age));

                printf("Enter the student GPA:\n");
                fflush(stdout);
                scanf("%f", &(st.gpa));

                // Call addStudent function to append new student into linked list
                addStudent(&st);
                printf("\n");
                break;

            case 2:
                // Display all students in the list
                displayStudents();
                break;

            case 3:
                // Search for a student by ID: prompt for ID then search
                printf("Enter the student ID:\n");
                fflush(stdout);
                scanf("%d", &(st.id));
                searchStudentByID(st.id);
                printf("\n");
                break;

            case 4:
                // Update an existing student's information: prompt for new data
                printf("Enter the student ID to update his data:\n");
                fflush(stdout);
                scanf("%d", &(st.id));

                printf("Enter the student name:\n");
                fflush(stdout);
                // Clear leftover newline before using gets
                while (getchar() != '\n');
                gets(st.name);

                printf("Enter the student age:\n");
                fflush(stdout);
                scanf("%d", &(st.age));

                printf("Enter the student GPA:\n");
                fflush(stdout);
                scanf("%f", &(st.gpa));

                // Call updateStudent to update the student info in the list
                updateStudent(&st);
                printf("\n");
                break;

            case 5:
                // Delete a student by ID: prompt for ID, then delete if found
                printf("Enter the student ID to delete his data:\n");
                fflush(stdout);
                scanf("%d", &(st.id));
                deleteStudent(st.id);
                printf("\n");
                break;

            case 6:
                // Calculate and print the average GPA of all students
                calculateAverageGPA();
                printf("\n");
                break;

            case 7:
                // Find and display student(s) with the highest GPA
                searchHighestGPA();
                printf("\n");
                break;

            case 8:
                // Exit the program by setting exit flag to 0
                exit = 0;
                printf("Program finished successfully\n");
                fflush(stdout);
                break;

            default:
                // Handle invalid menu choices
                printf("Invalid choice.\nPlease, enter a valid one\n");
                printf("\n");
                fflush(stdout);
        }
    }

    // Return success status to OS when program ends
    return 0;
}
