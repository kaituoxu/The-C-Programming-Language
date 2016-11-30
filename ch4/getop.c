#include "calc.h"
#include <ctype.h>
#include <stdio.h>

int Getop(char s[]) {
	int i, c;

	while ((s[0] = c = Getch()) == ' ' || c == '\t') {
		;
	}
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-')
		return c;
	i = 0;
	if (isdigit(c) || c == '-')
		while (isdigit(s[++i] = c = Getch())) {
			;
		}
	if (c == '.')
		while (isdigit(s[++i] = c = Getch())) {
			;
		}
	s[i] = '\0';
	if (c != EOF)
		Ungetch(c);	
	return NUMBER;
}
