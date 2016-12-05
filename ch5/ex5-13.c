#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

#define DEFALUT_LINE 10
#define MAXLINES 5000

int main(int argc, char *argv[]) {
	char *lineptr[MAXLINES];
	int nlines;
	int n, i;

	if (argc == 1)
		n = DEFALUT_LINE;
	else if (argc == 2 && (*++argv)[0] == '-')
			n = atoi(argv[0]+1);
	else {
		printf("Usage: %s [-n]\n", argv[0]);
		exit(1);
	}
	//printf("n = %d\n", n);

	if ((nlines = ReadLines(lineptr, MAXLINES)) >= 0) {
		if (n < 1 || n > nlines) n = nlines;
		for (i = nlines-n; i < nlines; ++i) {
			printf("%s\n", lineptr[i]);
		}
		return 0;	
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}
