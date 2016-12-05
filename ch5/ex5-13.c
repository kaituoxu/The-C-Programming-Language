#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

#define MAXLINES 5000

int main(int argc, char *argv[]) {
	char *lineptr[MAXLINES];
	int nlines;
	int n, i;

	if (argc == 1)
		n = 10;
	else if (argc == 2)
		if ((*++argv)[0] == '-')
			n = atoi(++argv[0]);
	//printf("n = %d\n", n);

	if ((nlines = ReadLines(lineptr, MAXLINES)) >= 0) {
		if (nlines < n) n = nlines;
		for (i = nlines-n; i < nlines; ++i) {
			printf("%s\n", lineptr[i]);
		}
		return 0;	
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}
