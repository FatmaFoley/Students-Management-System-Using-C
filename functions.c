/*
 * functions.c
 *
 *  Created on: Aug 8, 2025
 *      Author: Fatma Foley
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

// Head pointer for the linked list of students, initially empty
struct node* head = NULL;

/*
 * Function: addStudent
 * --------------------
 * Adds a new student to the linked list if the ID does not already exist.
 * Allocates memory for a new node, fills it with the student data, and appends it at the end.
 *
 * ptr: pointer to the student structure containing new student data
 */
void addStudent(const struct student* const ptr)
{
    // If the list is empty, create the first node
    if(head == NULL)
    {
        struct node* link = (struct node*) malloc(sizeof(struct node));
        if(link == NULL)
        {
            printf("Error, There is no enough space\n");
            fflush(stdout);
            return;
        }
        else
        {
            // Copy student info into the new node
            link->data.id = ptr->id;
            strcpy(link->data.name, ptr->name);
            link->data.age = ptr->age;
            link->data.gpa = ptr->gpa;
            // Set the head of the list and next pointer
            head = link;
            link->next = NULL;
        }
        return;
    }
    else
    {
        // Traverse the list to check if the student ID already exists
        struct node* current = head;
        while(current->next != NULL)
        {
            if(ptr->id == current->data.id)
            {
                printf("The Student Data is already exist\n");
                fflush(stdout);
                return;
            }
            current = current->next;
        }
        // Check last node for duplicate ID
        if(ptr->id == current->data.id)
        {
            printf("The Student Data is already exist\n");
            fflush(stdout);
            return;
        }
        // Allocate a new node to insert at the end
        struct node* link = (struct node*) malloc(sizeof(struct node));
        if(link == NULL)
        {
            printf("Error, There is no enough space\n");
            fflush(stdout);
            return;
        }
        else
        {
            // Copy student info into the new node
            link->data.id = ptr->id;
            strcpy(link->data.name, ptr->name);
            link->data.age = ptr->age;
            link->data.gpa = ptr->gpa;
            // Append the new node at the end
            current->next = link;
            link->next = NULL;
            printf("The student data was added successfully\n");
            fflush(stdout);
            return;
        }
    }
}

/*
 * Function: displayStudents
 * -------------------------
 * Prints all student data entries currently in the linked list.
 * If list is empty, informs that no students are present.
 */
void displayStudents(void)
{
    if(head == NULL)
    {
        printf("No students are present\n");
        fflush(stdout);
        return;
    }
    else
    {
        struct node* current = head;
        // Iterate through the list and print each student's details
        while(current != NULL)
        {
            printf("The student ID is %d\n", current->data.id);
            printf("The student name is %s\n", current->data.name);
            printf("The student age is %d\n", current->data.age);
            printf("The student GPA is %0.2f\n", current->data.gpa);
            printf("\n");
            fflush(stdout);
            current = current->next;
        }
        return;
    }
}

/*
 * Function: searchStudentByID
 * ---------------------------
 * Searches for a student in the list by their ID.
 * If found, prints student information, otherwise notifies not found.
 *
 * id: the ID of the student to search for
 */
void searchStudentByID(int id)
{
    struct node* current = head;
    // Iterate through the list looking for the matching ID
    while(current != NULL)
    {
        if(id == current->data.id)
        {
            // Student found, print details
            printf("The student ID is %d\n", current->data.id);
            printf("The student name is %s\n", current->data.name);
            printf("The student age is %d\n", current->data.age);
            printf("The student GPA is %0.2f\n", current->data.gpa);
            fflush(stdout);
            return;
        }
        current = current->next;
    }
    // If not found in list
    printf("The ID was not found\n");
    fflush(stdout);
    return;
}

/*
 * Function: updateStudent
 * -----------------------
 * Updates the student information for a given student ID.
 * If the student is found, updates name, age and GPA.
 * If not, prints a message saying the ID was not found.
 *
 * ptr: pointer to the student struct with updated data
 */
void updateStudent (const struct student* const ptr)
{
    if(head == NULL)
    {
        printf("No students are present\n");
        fflush(stdout);
        return;
    }
    else
    {
        struct node* current = head;
        // Iterate the list to find the matching student ID
        while(current != NULL)
        {
            if(ptr->id == current->data.id)
            {
                // Update student's data fields
                strcpy(current->data.name, ptr->name);
                current->data.age = ptr->age;
                current->data.gpa = ptr->gpa;
                printf("The student data was updated successfully\n");
                return;
            }
            current = current->next;
        }
    }
    // Student with given ID not found
    printf("The ID %d was not found\n", ptr->id);
    fflush(stdout);
    return;
}

/*
 * Function: calculateAverageGPA
 * -----------------------------
 * Calculates the average GPA of all students in the list.
 * Returns the average GPA as float.
 * Prints the average GPA or informs if no students exist.
 */
float calculateAverageGPA(void)
{
    if(head == NULL)
    {
        printf("No students are present\n");
        fflush(stdout);
        return 0.0;
    }
    else
    {
        float count = 0;
        float sum = 0;
        struct node* current = head;
        // Sum all GPAs and count the total students
        while(current != NULL)
        {
            count++;
            sum += current->data.gpa;
            current = current->next;
        }
        float average = sum / count;
        printf("The students average GPA is equal to %0.2f\n", average);
        fflush(stdout);
        return average;
    }
}

/*
 * Function: searchHighestGPA
 * --------------------------
 * Finds and prints the student(s) with the highest GPA in the list.
 * If multiple students have the same highest GPA, prints all.
 * Prints message if no students are present.
 */
void searchHighestGPA(void)
{
    if(head == NULL)
    {
        printf("There are no students\n");
        fflush(stdout);
        return;
    }
    else
    {
        float max = 0;
        struct node* current = head;

        // Find the highest GPA in the list
        while(current != NULL)
        {
            if(max < current->data.gpa)
            {
                max = current->data.gpa;
            }
            current = current->next;
        }

        current = head;
        // Print all students with GPA equal to max GPA
        while(current != NULL)
        {
            if(max == current->data.gpa)
            {
                printf("------------------------------------------------\n");
                printf("The student data that has the max GPA:\n");
                printf("The student ID is %d\n", current->data.id);
                printf("The student name is %s\n", current->data.name);
                printf("The student age is %d\n", current->data.age);
                printf("The student GPA is %0.2f\n", current->data.gpa);
                printf("------------------------------------------------\n");
                fflush(stdout);
            }
            current = current->next;
        }
        return;
    }
}

/*
 * Function: deleteStudent
 * ------------------------
 * Deletes a student by ID from the linked list.
 * Updates head if the student is the first node.
 * Frees the memory of the deleted node.
 * Prints appropriate messages based on success/failure.
 *
 * id: the ID of the student to be deleted
 */
void deleteStudent(int id)
{
    if(head == NULL)
    {
        printf("No students are present\n");
        fflush(stdout);
        return;
    }

    struct node* current = head;

    // If the student to delete is the head node
    if(id == current->data.id)
    {
        head = head->next;
        free(current);
        printf("The student of ID %d was deleted successfully\n", id);
        fflush(stdout);
        return;
    }

    // Traverse to find the node before the node to delete
    while(current->next != NULL)
    {
        if(id == current->next->data.id)
        {
            struct node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            printf("The student of ID %d was deleted successfully\n", id);
            fflush(stdout);
            return;
        }
        current = current->next;
    }

    // If the ID was not found in list
    printf("The ID %d was not found\n", id);
    fflush(stdout);
}

