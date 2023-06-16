#include <stdio.h>
void swap(void *a, void *b, size_t size) {
    char temp[size]; 
    
    char *tempPtr = (char *)temp;
    char *aPtr = (char *)a;
    for (size_t i = 0; i < size; i++) {
        tempPtr[i] = aPtr[i];
    }

    
    char *bPtr = (char *)b;
    for (size_t i = 0; i < size; i++) {
        aPtr[i] = bPtr[i];
    }

    
    for (size_t i = 0; i < size; i++) {
        bPtr[i] = tempPtr[i];
    }
}

int main() {
    int a = 10;
    int b = 20;

    printf("Before swapping: a = %d, b = %d\n", a, b);
    swap(&a, &b, sizeof(int));
    printf("After swapping: a = %d, b = %d\n", a, b);

    float c = 1.5;
    float d = 3.7;

    printf("Before swapping: c = %f, d = %f\n", c, d);
    swap(&c, &d, sizeof(float));
    printf("After swapping: c = %f, d = %f\n", c, d);

    return 0;
}