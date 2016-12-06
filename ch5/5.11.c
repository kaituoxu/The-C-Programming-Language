#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line-io.h"

#define MAXLINES 5000

void Qsort(void *lineptr[], int left, int right,
					 int (*cmp)(void *, void *));
int NumCmp(char *, char *);

int main(int argc, char *argv[]) {
	char *lineptr[MAXLINES];
	int nlines;
	int numeric = 0;

	if (argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	if ((nlines = ReadLines(lineptr, MAXLINES)) >= 0 ) {
		Qsort((void **) lineptr, 0, nlines-1, (int (*)(void*,void*))(numeric ? NumCmp : strcmp));
		WriteLines(lineptr, nlines);
		return 0;
	} else {
		printf("Input too big to sort\n");
		return 1;
	}
}


void Qsort(void *v[], int left, int right,
					 int (*cmp)(void *, void *)) {
	int last, i;
	void Swap(void *v[], int, int);

	if (left >= right)
		return ;
	Swap(v, left, (left+right)/2);
	last = left;
	for (i = left+1; i <= right; i++) {
		if ((*cmp)(v[i], v[left]) < 0)
			Swap(v, i, ++last);
	}
	Swap(v, left, last);
	Qsort(v, left, last-1, cmp);
	Qsort(v, last+1, right, cmp);
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
