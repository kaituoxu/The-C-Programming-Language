#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "line-io.h"

#define MAXLINES 5000

void Qsort(void *lineptr[], int left, int right,
					 int (*cmp)(void *, void *), int reverse, int ignore);
int NumCmp(char *, char *);

int main(int argc, char *argv[]) {
	char *lineptr[MAXLINES];
	int nlines;
	int c, numeric = 0, reverse = 0, ignore = 0;

	while (--argc > 0 && (*++argv)[0] == '-') {
		while ((c = *++argv[0])) {
			switch (c) {
				case 'n':
					numeric = 1;
					break;
				case 'r':
					reverse = 1;
					break;
				case 'f':
					ignore = 1;
					break;
				default:
					printf("error: illegal option %c\n", c);
					argc = -1;
					break;
			}
		}
	}
	if (argc != 0) {
		printf("Usage: ./a.out -n -r\n");
		exit(1);
	}

	if ((nlines = ReadLines(lineptr, MAXLINES)) >= 0 ) {
		Qsort((void **) lineptr, 0, nlines-1, 
					(int (*)(void*,void*))(numeric ? NumCmp : strcmp), reverse, ignore);
		WriteLines(lineptr, nlines);
		return 0;
	} else {
		printf("Input too big to sort\n");
		return 1;
	}
}


void Qsort(void *v[], int left, int right,
					 int (*cmp)(void *, void *), int reverse, int ignore) {
	int last, i;
	void Swap(void *v[], int, int);

	if (left >= right)
		return ;
	Swap(v, left, (left+right)/2);
	last = left;
	for (i = left+1; i <= right; i++) {
		if (!ignore) {
			if ((!reverse && (*cmp)(v[i], v[left]) < 0) ||
					(reverse && (*cmp)(v[i], v[left]) > 0))
				Swap(v, i, ++last);
		} else {
			if ((!reverse && (*cmp)(v[i], v[left]) < 0) ||
					(reverse && (*cmp)(v[i], v[left]) > 0))
				Swap(v, i, ++last);
		}
	}
	Swap(v, left, last);
	Qsort(v, left, last-1, cmp, reverse, ignore);
	Qsort(v, last+1, right, cmp, reverse, ignore);
}

int NumCmp(char *s1, char *s2) {
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else 
		return 0;
}

void Swap(void *v[], int i, int j) {
	void *tmp;

	tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}
