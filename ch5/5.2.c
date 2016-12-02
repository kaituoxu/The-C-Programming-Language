#include <ctype.h>
#include <stdio.h>
#include "ch4/calc.h"

#define SIZE 10

void Swap(int *px, int *py) {
	int temp;
	temp = *px;
	*px = *py;
	*py = temp;
}

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
	for (*pn = 0; isdigit(c); c = Getch())
		*pn = 10 * (*pn) + (c - '0');
	*pn *= sign;
	if (c != EOF)
		Ungetch(c);
	return c;
}

int main()
{
	int x = 1, y = 2;
	int n, array[SIZE];

	printf("x=%d y=%d\n", x, y);
	Swap(&x, &y);
	printf("x=%d y=%d\n", x, y);

	for (n = 0; n < SIZE && Getint(&array[n]) != EOF; n++)
		;

	for (--n; n >= 0; --n) {
		printf("%d%c", array[n], (n == 0) ? '\n' : ' ');
	}

	return 0;
}
