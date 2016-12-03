#include "utils.h"
#include <stdio.h>
#include <string.h>


// Memory

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *Alloc(int n) {
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	} else {
		return NULL;
	}
}

void Afree(char *p) {
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}


// Input/Output

int GetLine(char *line, int maxlen) {
	int c, i;
	for (i = 0; i<maxlen-1 && (c=getchar())!=EOF && c!='\n'; i++) {
		line[i] = c;
	}
	if (c == '\n') {
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return i;
}

#define MAXLEN 1000

int ReadLines(char *lineptr[], int maxlines) {
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = GetLine(line, MAXLEN)) > 0) {
		if (nlines >= maxlines || (p = Alloc(len)) == NULL) {
			return -1;
		} else {
			line[len-1] = '\0'; // delete '\n'
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

void WriteLines(char *lineptr[], int nlines) {
	int i;
	for (i = 0; i < nlines; i++) {
		printf("%s\n", *lineptr++);
	}
}


// Sort

void Swap(char *v[], int i, int j) {
	char *temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void Qsort(char *v[], int left, int right) {
	int i, last;

	if (left >= right)
		return ;
	Swap(v, left, (left+right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			Swap(v, ++last, i);
	Swap(v, last, left);
	Qsort(v, 0, last - 1);
	Qsort(v, last + 1, right);
}
