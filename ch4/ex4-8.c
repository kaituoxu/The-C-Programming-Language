#include <stdio.h>
#include "calc.h"

int main()
{
	int c;

	while ((c = Getch_1()) != EOF) {
		putchar(c);
		if (c == '/') 
			if ((c = Getch_1()) == '*')
				Ungetch_1('!');
	}

	return 0;
}
