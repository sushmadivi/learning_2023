#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void searchStudentByName(struct Student* students, int numStudents, const char* searchName) {
    int i, found = 0;

    printf("Search Results:\n");
    for (i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollno, students[i].name, students[i].marks);
            found = 1;
        }
    }

    if (!found) {
        printf("No student with the name '%s' found.\n", searchName);
    }
}

int main() {
    int numStudents, i;
    struct Student* students;
    char searchName[20];

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    printf("Enter student details:\n");
    for (i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);

        printf("Enter Roll No: ");
        scanf("%d", &(students[i].rollno));

        printf("Enter Name: ");
        scanf("%s", students[i].name);

        printf("Enter Marks: ");
        scanf("%f", &(students[i].marks));

        printf("\n");
    }

    printf("Enter the name to search: ");
    scanf("%s", searchName);

    searchStudentByName(students, numStudents, searchName);

    free(students);

    return 0;
}