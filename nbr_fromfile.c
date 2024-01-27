#include "factor.h"
/**
 * factorise - this function factorizes the number passed as parameter
 * @param: this is the parameter to factorise
 * Return: NULL from my thinking
 */
void factorise(long param)
{
	long i = 0, j = 0;
	
	for (i = 0; i < param; i++)
	{
		for (j = 0; j < param; j++)
		{
			if (i * j == param)
			{
				printf("%ld=%ld*%ld\n", param, j, i);
				return;
			}
		}
	}
}

/**
 * read_fromfile - this function reads nbrs from file line by line
 * @fil: the file containing the numbers
 * Return: array of read nbrs
 */
int read_fromfile(const char *fil)
{
	long umubare, inshuro = 0;
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
int main(int args, char **argv)
{
	int nbr_nbrs = 0;
	
	if (args != 2)
		return (-1);
	nbr_nbrs = read_fromfile(argv[1]);
	return (nbr_nbrs);
}
