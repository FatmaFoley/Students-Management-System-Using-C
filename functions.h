/*
 * functions.h
 *
 *  Created on: Aug 8, 2025
 *      Author: fatma foley
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

// Structure representing a student with basic fields
struct student
{
    int id;             // Unique identifier for the student
    char name[50];      // Student's name (max 49 chars + null terminator)
    int age;            // Student's age
    float gpa;          // Student's GPA (Grade Point Average)
};

// Node structure for linked list that stores student data
struct node
{
    struct student data;    // Student data stored in this node
    struct node* next;      // Pointer to the next node in the list
};

// Adds a new student to the list
void addStudent(const struct student* const ptr);

// Displays all students' data currently in the list
void displayStudents(void);

// Searches for a student by their ID and prints their details
void searchStudentByID(int id);

// Updates information of an existing student identified by the ID
void updateStudent(const struct student* const ptr);

// Calculates and returns the average GPA of all students
float calculateAverageGPA(void);

// Searches and displays the student(s) with the highest GPA
void searchHighestGPA(void);

// Deletes a student from the list by their ID
void deleteStudent(int id);

#endif /* FUNCTIONS_H_ */
