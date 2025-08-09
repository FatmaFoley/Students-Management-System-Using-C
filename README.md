# Students-Management-System-Using-C
Student Management System (C Language)
Project Overview
This Student Management System is a console-based application written in C that efficiently manages student records. It demonstrates key programming concepts such as structures, pointers, dynamic memory allocation, and linked lists. The system provides essential functionalities to add, display, search, update, and delete student information, as well as calculate average GPA and find the student with the highest GPA.

Features
Add a new student with unique ID validation

Display all student records

Search for a student by their ID

Update existing student details

Delete a student record securely

Calculate the average GPA of all students

Find and display the student with the highest GPA

Code Structure
The project code is divided into three files for better modularity and maintainability:

functions.h
Contains the struct definitions for student data and the declarations of all functions used in the project.

functions.c
Includes the implementation (definitions) of all functions declared in functions.h.

main.c
The entry point of the program, which contains the main function and the interactive menu that allows users to access different features.

How to Compile and Run
To compile the project, use the following command in your terminal (assuming GCC compiler):

bash
gcc main.c functions.c -o StudentManagementSystem
Then run the executable:

bash
./StudentManagementSystem
Additional Notes
The program uses a linked list to dynamically store student records, enabling efficient insertion and deletion.

Proper validation and error handling are implemented, such as preventing duplicate student IDs and handling memory allocation failures.

The project is a great exercise for learning and practicing data structures and memory management in C.
