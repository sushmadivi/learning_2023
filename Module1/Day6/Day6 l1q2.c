#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeStudents(struct Student* students, int numStudents) {
    int i;

    for (i = 0; i < numStudents; i++) {
        students[i].rollno = 0;
        strcpy(students[i].name, "");
        students[i].marks = 0.0;
    }
}

int main() {
    int numStudents, i;
    struct Student* students;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    initializeStudents(students, numStudents);

    printf("Initialized student details:\n");
    for (i = 0; i < numStudents; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollno, students[i].name, students[i].marks);
    }

    free(students);

    return 0;
}