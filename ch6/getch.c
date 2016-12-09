#include "getch.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp = 0;

int Getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void Ungetch(int c) {
	if (bufp < BUFSIZE) {
		buf[bufp++] = c;
	} else {
		printf("ungetch: too many characters\n");
	}
}

