#include <ctype.h>
#include <stdio.h>
#include "ch4/calc.h"

#define SIZE 10

int Getint(int *pn) {
	int c, sign;
	
	while (isspace(c = Getch())) {
		;
	}
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		Ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = Getch();
	if (!isdigit(c)) {
		Ungetch(c);
		return 0;
	}
	for (*pn = 0; isdigit(c); c = Getch())
		*pn = 10 * (*pn) + (c - '0');
	*pn *= sign;
	if (c != EOF)
		Ungetch(c);
	return c;
}

int main()
{
	int n, array[SIZE];

	for (n = 0; n < SIZE && Getint(&array[n]) != EOF; n++)
		;

	for (--n; n >= 0; --n) {
		printf("%d%c", array[n], (n == 0) ? '\n' : ' ');
	}

	return 0;
}
