#include <ctype.h>
#include <stdio.h>
#include "ch4/calc.h"

#define SIZE 10

int GetFloat(float *pf) {
	int c, sign;
	double power;

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
	for (*pf = 0; isdigit(c); c = Getch())
		*pf = 10.0 * (*pf) + (c - '0');
	if (c == '.')
		c = Getch();
	for (power = 1.0; isdigit(c); c = Getch()) {
		*pf = 10.0 * (*pf) + (c - '0');
		power *= 10.0;
	}
	*pf *= sign / power;

	if (c != EOF)
		Ungetch(c);
	return c;
}

int main()
{
	float f[SIZE];
	int i;
	
	for (i = 0; i < SIZE && GetFloat(&f[i]) != EOF; ++i) {
		;
	}

	for (--i; i >= 0; --i)
		printf("%g%c", f[i], (i == 0) ? '\n' : ' ');
	return 0;
}
