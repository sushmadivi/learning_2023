#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

void getTimeDifference(struct Time* startTime, struct Time* endTime, struct Time* difference) {
    int startSeconds, endSeconds, timeDifference;

    startSeconds = startTime->hours * 3600 + startTime->minutes * 60 + startTime->seconds;
    endSeconds = endTime->hours * 3600 + endTime->minutes * 60 + endTime->seconds;

    timeDifference = endSeconds - startSeconds;

    difference->hours = timeDifference / 3600;
    timeDifference %= 3600;

    difference->minutes = timeDifference / 60;
    difference->seconds = timeDifference % 60;
}

int main() {
    struct Time startTime, endTime, difference;

    printf("Enter the start time (hours minutes seconds): ");
    scanf("%d %d %d", &(startTime.hours), &(startTime.minutes), &(startTime.seconds));

    printf("Enter the end time (hours minutes seconds): ");
    scanf("%d %d %d", &(endTime.hours), &(endTime.minutes), &(endTime.seconds));

    getTimeDifference(&startTime, &endTime, &difference);

    printf("\nTime Difference: %d hours %d minutes %d seconds\n", difference.hours, difference.minutes, difference.seconds);

    return 0;
}