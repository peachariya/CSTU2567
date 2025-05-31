#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSES 100
#define MAX_STUDENTS 100
#define MAX_REG_COURSES 10

// Structure definitions
typedef struct {
    char courseCode[11]; // +1 for null terminator
    char courseName[51]; // +1 for null terminator
    int credits;
} Course;

typedef struct {
    char studentID[11]; // +1 for null terminator
    char name[51];     // +1 for null terminator
    Course registeredCourses[MAX_REG_COURSES];
    int courseCount;
} Student;


// Function prototypes
void addCourse(Course courses[], int *courseCount);
void addStudent(Student students[], int *studentCount);
void registerCourse(Course courses[], Student students[], int courseCount, int studentCount);
void displayStudentCourses(const Student students[], int studentCount);
void saveData(const Course courses[], int courseCount, const Student students[], int studentCount);
void loadData(Course courses[], int *courseCount, Student students[], int *studentCount);


int main() {
    Course courses[MAX_COURSES];
    Student students[MAX_STUDENTS];
    int courseCount = 0;
    int studentCount = 0;
    int choice;

    // Load data from file on startup
    loadData(courses, &courseCount, students, &studentCount);


    do {
        printf("===== Course Registration System =====\n");
        printf("1. Add New Course\n");
        printf("2. Add New Student\n");
        printf("3. Register Course for Student\n");
        printf("4. Display Student's Registered Courses\n");
        printf("5. Save Data\n");
        printf("6. Load Data\n");
        printf("7. Exit\n");
        printf("Select an option (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addCourse(courses, &courseCount); break;
            case 2: addStudent(students, &studentCount); break;
            case 3: registerCourse(courses, students, courseCount, studentCount); break;
            case 4: displayStudentCourses(students, studentCount); break;
            case 5: saveData(courses, courseCount, students, studentCount); break;
            case 6: loadData(courses, &courseCount, students, &studentCount); break;
            case 7: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}


//Function definitions (you need to complete these functions)
void addCourse(Course courses[], int *courseCount) {
    // Add code to get course details and add to the courses array.  Handle array full.
}

void addStudent(Student students[], int *studentCount) {
    // Add code to get student details and add to the students array. Handle array full.
}

void registerCourse(Course courses[], Student students[], int courseCount, int studentCount){
    // Add code to allow a student to register for a course.  Handle course not found, student not found, and already registered.
}

void displayStudentCourses(const Student students[], int studentCount) {
   // Add code to display registered courses for a given student ID. Handle student not found.
}

void saveData(const Course courses[], int courseCount, const Student students[], int studentCount) {
    // Add code to save the course and student data to "registration_data.txt".  Handle file errors.
}

void loadData(Course courses[], int *courseCount, Student students[], int *studentCount) {
    // Add code to load course and student data from "registration_data.txt". Handle file errors and data corruption.
}