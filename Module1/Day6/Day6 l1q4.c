#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void sortStudentsByMarks(struct Student* students, int numStudents) {
    int i, j;
    struct Student temp;

    for (i = 0; i < numStudents - 1; i++) {
        for (j = 0; j < numStudents - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
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

    sortStudentsByMarks(students, numStudents);

    printf("Sorted student details (descending order of marks):\n");
    for (i = 0; i < numStudents; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollno, students[i].name, students[i].marks);
    }

    free(students);

    return 0;
}