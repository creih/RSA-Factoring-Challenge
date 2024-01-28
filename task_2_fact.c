#include "factor.h"
/**
 * is_prime - checks if num is prime
 * @num: param to be checked
 * Return: 0 for false, 1 for true
 */
int is_prime(long num)
{
        long i;

        if (num <= 1)
                return (0);
        if (num == 2 || num == 3)
                return (1);
        for (i = 2; i < num; i++)
        {
                if (num % i == 0)
                        return (0);
        }
        return (1);
}
/**
 * read_fromfile - this function reads nbrs from file line by line
 * @fil: the file containing the numbers
 * Return: array of read nbrs
 */
int read_fromfile(const char *fil)
{
        long umubare;
        long inshuro;
        FILE *doc = fopen(fil, "r");

        if (!doc)
        {
                fprintf(stderr, "Error opening file: %s\n", fil);
                return (-1);
        }
        while (fscanf(doc, "%ld", &umubare) == 1)
        {
                inshuro = umubare;
        }
        fclose(doc);
        return (inshuro);
}
/**
 * find_prime_factors - prints the prime factors of a number
 * @num: the number to find prime factors for
 */
void factor(long n)
{
        for (long i = 2; i <= n; i++)
        {
                for (long j = 0; j <= n; j++)
                {
                        if (is_prime(i) == 1 && is_prime(j) == 1 && j*i==n)
                        {
                                printf("%ld=%ld*%ld\n", n, i, j);
                                return;
                        }
                }
        }
}
/**
 * main - main entry
 * @argc: nbr of args
 * @argv: arguments
 * Return: 1 for success 0 for fail
 */
int main(int argc, char **argv)
{
        long p;
        int q, n;
        p = read_fromfile(argv[1]);
        factor(p);
        return (0);
}
