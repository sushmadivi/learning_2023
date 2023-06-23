#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void copyFile(FILE *source, FILE *destination, int option) {
    char ch;

    while ((ch = fgetc(source)) != EOF) {
        if (option == 1)
            ch = tolower(ch);
        else if (option == 2)
            ch = toupper(ch);
        else if (option == 3) {
            if (isalpha(ch))
                ch = tolower(ch);
            else if (ch == '.' || ch == '?' || ch == '!')
                ch = toupper(ch);
        }
        fputc(ch, destination);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments. Usage: ./cp <option> <source_file> <destination_file>\n");
        return 1;
    }

    int option = 0;
    char *optionStr = argv[1];
    FILE *sourceFile, *destinationFile;

    if (optionStr[0] == '-')
    {
        char optionChar = optionStr[1];
        switch (optionChar) {
            case 'u':
                option = 2; // Uppercase option
                break;
            case '1':
                option = 1; // Lowercase option
                break;
            case 's':
                option = 3; // Sentence case option
                break;
            default:
                printf("Invalid option: %c\n", optionChar);
                return 1;
        }

        sourceFile = fopen(argv[2], "r");
        if (sourceFile == NULL) {
            printf("Error opening the source file.\n");
            return 1;
        }

        destinationFile = fopen(argv[3], "w");
        if (destinationFile == NULL) {
            printf("Error opening the destination file.\n");
            return 1;
        }

        copyFile(sourceFile, destinationFile, option);

        fclose(sourceFile);
        fclose(destinationFile);

        printf("File copied successfully with text case option.\n");
    } else {
        sourceFile = fopen(argv[1], "r");
        if (sourceFile == NULL) {
            printf("Error opening the source file.\n");
            return 1;
        }

        destinationFile = fopen(argv[2], "w");
        if (destinationFile == NULL) {
            printf("Error opening the destination file.\n");
            return 1;
        }

        copyFile(sourceFile, destinationFile, option);

        fclose(sourceFile);
        fclose(destinationFile);

        printf("Normal file copy performed.\n");
    }

        return 0;
}
