#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void displayStudents(struct Student* students, int numStudents) {
    int i;

    printf("Student details:\n");
    for (i = 0; i < numStudents; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollno, students[i].name, students[i].marks);
    }
}

int main() {
    int numStudents, i;
    struct Student* students;

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

    displayStudents(students, numStudents);

    free(students);

    return 0;
}