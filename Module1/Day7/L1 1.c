#include <stdio.h>

int main() {
    FILE *sourceFile, *destinationFile;
    char sourceFileName[100], destinationFileName[100];
    char ch;

    // Input the source file name
    printf("Enter the source file name: ");
    scanf("%s", sourceFileName);

    // Open the source file in read mode
    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Error opening the source file.\n");
        return 1;
    }

    // Input the destination file name
    printf("Enter the destination file name: ");
    scanf("%s", destinationFileName);

    // Open the destination file in write mode
    destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Error opening the destination file.\n");
        return 1;
    }

    // Copy the contents of source file to destination file
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destinationFile);
    }

    // Close the files
    fclose(sourceFile);
    fclose(destinationFile);

    printf("File copied successfully.\n");

    return 0;
}