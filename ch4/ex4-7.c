#include <stdio.h>
#include "calc.h"

int main()
{
	char *s = "hello, world.";
	int c;

	Ungets(s);
	while ((c = Getch()) != EOF)
		putchar(c);
	return 0;
}
