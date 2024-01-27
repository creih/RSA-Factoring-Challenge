#include "factor.h"
/**
 * factorise - this function factorizes the number passed as parameter
 * @param: this is the parameter to factorise
 * Return: NULL from my thinking
 */
void factorise(int param)
{
	int i = 0, j = 0;

	if (param <= 1)
		return;
	while (param % 2 == 0)
	{
		printf("%d=2*%d\n", param, param / 2);
		num /= 2;
	}
	for (i = 3; i < sqrt(param); i+=2)
	{
		while (param % i == 0)
		{
			printf("%d=%d*%d\n", param, i, param / i);
			param /= i;
		}
	}
	if (param > 2)
		printf("%d=%d*%d\n", param, param, 1);
}

/**
 * read_fromfile - this function reads nbrs from file line by line
 * @fil: the file containing the numbers
 * Return: array of read nbrs
 */
int read_fromfile(const char *fil)
{
	int umubare, inshuro = 0;
	FILE *doc = fopen(fil, "r");

	if (!doc)
	{
		fprintf(stderr, "Error opening file: %s\n", fil);
		return (-1);
	}
	while (fscanf(doc, "%d", &umubare) == 1)
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
