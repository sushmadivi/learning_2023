#include <stdio.h>

struct Complex {
    double real;
    double imag;
};

void readComplex(struct Complex* complex) {
    printf("Enter real part: ");
    scanf("%lf", &(complex->real));

    printf("Enter imaginary part: ");
    scanf("%lf", &(complex->imag));
}

void writeComplex(struct Complex* complex) {
    printf("Complex number: %.2f + %.2fi\n", complex->real, complex->imag);
}

struct Complex addComplex(struct Complex* complex1, struct Complex* complex2) {
    struct Complex result;
    result.real = complex1->real + complex2->real;
    result.imag = complex1->imag + complex2->imag;
    return result;
}

struct Complex multiplyComplex(struct Complex* complex1, struct Complex* complex2) {
    struct Complex result;
    result.real = (complex1->real * complex2->real) - (complex1->imag * complex2->imag);
    result.imag = (complex1->real * complex2->imag) + (complex1->imag * complex2->real);
    return result;
}

int main() {
    struct Complex complex1, complex2, sum, product;

    printf("Enter the first complex number:\n");
    readComplex(&complex1);

    printf("\nEnter the second complex number:\n");
    readComplex(&complex2);

    sum = addComplex(&complex1, &complex2);
    product = multiplyComplex(&complex1, &complex2);

    printf("\nSum of the complex numbers:\n");
    writeComplex(&sum);

    printf("\nProduct of the complex numbers:\n");
    writeComplex(&product);

    return 0;
}