#include "factor.h"
/**
 * factorise - this function factorizes the number passed as parameter
 * @param: this is the parameter to factorise
 * Return: NULL from my thinking
 */
void factorise(long param)
{
	long i = 0, j = 0;

	if (param <= 1)
		return;
	while (param % 2 == 0)
	{
		printf("%ld=2*%ld\n", param, param / 2);
		param /= 2;
	}
	for (i = 3; i * i <= param; i+=2)
	{
		while (param % i == 0)
		{
			printf("%ld=%ld*%ld\n", param, i, param / i);
			param /= i;
		}
	}
	if (param > 2)
		printf("%ld=%ld*%d\n", param, param, 1);
}

/**
 * read_fromfile - this function reads nbrs from file line by line
 * @fil: the file containing the numbers
 * Return: array of read nbrs
 */
int read_fromfile(const char *fil)
{
	long umubare;
	int inshuro = 0;
	FILE *doc = fopen(fil, "r");

	if (!doc)
	{
		fprintf(stderr, "Error opening file: %s\n", fil);
		return (-1);
	}
	while (fscanf(doc, "%ld", &umubare) == 1)
	{
		factorise(umubare);
		inshuro += 1;
	}

	fclose(doc);
	return (inshuro);
}
void main(int args, char **argv)
{
	if (args != 2)
		return;
	read_fromfile(argv[1]);
}
