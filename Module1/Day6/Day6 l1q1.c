#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseInputString(char* inputString, struct Student* students, int numInputs) {
    char* token;
    int i = 0;

    token = strtok(inputString, " ");
    while (token != NULL && i < numInputs) {
        students[i].rollno = atoi(token);

        token = strtok(NULL, " ");
        strcpy(students[i].name, token);

        token = strtok(NULL, " ");
        students[i].marks = atof(token);

        token = strtok(NULL, " ");
        i++;
    }
}

int main() {
    int numInputs, i;
    char inputString[100];
    struct Student* students;

    printf("Enter the number of inputs: ");
    scanf("%d", &numInputs);

    // Clear the input buffer
    while (getchar() != '\n')
        ;

    students = (struct Student*)malloc(numInputs * sizeof(struct Student));

    printf("Enter the input string in the format 'rollno name marks':\n");
    for (i = 0; i < numInputs; i++) {
        fgets(inputString, sizeof(inputString), stdin);
        inputString[strcspn(inputString, "\n")] = '\0';  // Remove trailing newline

        parseInputString(inputString, &students[i], numInputs);
    }

    printf("\nStudent details:\n");
    for (i = 0; i < numInputs; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollno, students[i].name, students[i].marks);
    }

    free(students);

    return 0;
}