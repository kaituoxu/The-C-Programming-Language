#include "calc.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp = 0;

int Getch(char *argv[]) {
	return (bufp > 0) ? buf[--bufp] : *((argv[0])++);
}

void Ungetch(int c) {
	if (bufp < BUFSIZE) {
		buf[bufp++] = c;
	} else {
		printf("ungetch: too many characters\n");
	}
}

/* exercise 4-7 */
void Ungets(char s[]) {
	size_t i = strlen(s);
	while (i > 0)
		Ungetch(s[--i]);
}


int buffer = EOF;
int Getch_1(void) {
	int temp;
	temp = buffer;
	buffer = EOF;
	return (temp > 0) ? temp : getchar();
}

void Ungetch_1(int c) {
	if (buffer == EOF) {
		buffer = c;
	} else {
		printf("ungetch: too many characters\n");
	}
}
