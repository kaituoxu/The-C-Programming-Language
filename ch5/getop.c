#include "calc.h"
#include <ctype.h>
#include <stdio.h>

int Getop(char s[], int *argc, char **argv[]) {
	int i, c;

	++*argv;

	if (--(*argc) == 0) {
		return '\n';
	} 
	if (*argc < 0) {
		return EOF;
	}

	while ((s[0] = c = Getch(*argv)) == ' ' || c == '\t') {
		;
	}
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = Getch(*argv))) {
			;
		}
	if (c == '.')
		while (isdigit(s[++i] = c = Getch(*argv))) {
			;
		}
	s[i] = '\0';
//	if (c != EOF)
//		Ungetch(c);	
	return NUMBER;
}
