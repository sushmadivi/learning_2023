#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

double calculateVolume(struct Box* box) {
    return box->length * box->width * box->height;
}

double calculateSurfaceArea(struct Box* box) {
    return 2 * (box->length * box->width + box->length * box->height + box->width * box->height);
}

int main() {
    struct Box myBox;
    struct Box* boxPtr;

    boxPtr = &myBox;

    // Using (*) asterisk or indirection operator and (.) dot operator
    (*boxPtr).length = 3.0;
    (*boxPtr).width = 2.5;
    (*boxPtr).height = 4.0;

    double volume = calculateVolume(boxPtr);
    double surfaceArea = calculateSurfaceArea(boxPtr);

    printf("Using (*) asterisk and (.) dot operators:\n");
    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);

    // Using (->) Arrow operator
    boxPtr->length = 3.0;
    boxPtr->width = 2.5;
    boxPtr->height = 4.0;

    volume = calculateVolume(boxPtr);
    surfaceArea = calculateSurfaceArea(boxPtr);

    printf("\nUsing (->) Arrow operator:\n");
    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);

    return 0
}