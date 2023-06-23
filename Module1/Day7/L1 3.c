#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct LogEntry {
    int entryNo;
    int sensorNo;
    float temperature;
    int humidity;
    int light;
    char timestamp[9];
};

struct LogEntry logEntries[MAX_ENTRIES];
int numEntries = 0;

void extractEntries() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char *token;
        int fieldCount = 0;
        struct LogEntry entry;

        token = strtok(line, ",");
        while (token != NULL && fieldCount < 6) {
            switch (fieldCount) {
                case 0:
                    entry.entryNo = atoi(token);
                    break;
                case 1:
                    entry.sensorNo = atoi(token);
                    break;
                case 2:
                    entry.temperature = atof(token);
                    break;
                case 3:
                    entry.humidity = atoi(token);
                    break;
                case 4:
                    entry.light = atoi(token);
                    break;
                case 5:
                    strncpy(entry.timestamp, token, sizeof(entry.timestamp));
                    break;
            }
            token = strtok(NULL, ",");
            fieldCount++;
        }

        logEntries[numEntries++] = entry;
    }

    fclose(file);
}

void displayEntries() {
    printf("Log Entries:\n");
    printf("============\n");

    for (int i = 0; i < numEntries; i++) {
        printf("Entry No: %d\n", logEntries[i].entryNo);
        printf("Sensor No: %d\n", logEntries[i].sensorNo);
        printf("Temperature: %.2f\n", logEntries[i].temperature);
        printf("Humidity: %d\n", logEntries[i].humidity);
        printf("Light: %d\n", logEntries[i].light);
        printf("Timestamp: %s\n", logEntries[i].timestamp);
        printf("------------\n");
    }
}

int main() {
    extractEntries();
    displayEntries();

    return 0;
}