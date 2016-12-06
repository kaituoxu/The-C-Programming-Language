#include "line-io.h"
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


