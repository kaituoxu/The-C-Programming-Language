#include <stdio.h>
#include "utils.h"

#define MAXLINE 1000

int main()
{
	char line[MAXLINE];
	double sum;

	sum = 0;
	while (GetLine(line, MAXLINE) > 0) {
		printf("\t%g\n", sum += Atof(line));
	}

	return 0;
}
