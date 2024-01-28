#include <stdio.h>
#include <stdlib.h>

int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void factorize(int n) {
    printf("%d=", n);

    int first = 1; // Flag to determine if it's the first prime factor
    int printed = 0; // Flag to track if any factor has been printed

    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            while (n % i == 0) {
                if (!first) {
                    printf("*");
                }
                printf("%d", i);
                n /= i;
                first = 0;
                printed = 1;
            }
        }
    }

    if (!printed) {
        printf("%d", n); // If the number is prime, print the number itself
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int n;
    if (fscanf(file, "%d", &n) != 1) {
        fprintf(stderr, "Error reading RSA number from file\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    factorize(n);

    return 0;
}
