#include <stdio.h>
#include <string.h>
#include "utils.h"

#define MAXLINES 5000

int main()
{
	char *lineptr[MAXLINES];
	int nlines;

	if ((nlines = ReadLines(lineptr, MAXLINES)) >= 0) {
		Qsort(lineptr, 0, nlines-1);
		WriteLines(lineptr, nlines);
		return 0;	
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}
