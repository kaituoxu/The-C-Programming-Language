#include <stdio.h>

int main()
{
	int c; 
	while ((c = getchar()) != EOF) {
		if (c == '/') {
		// process // and /*
			if ((c = getchar()) == '/') {
				while ((c = getchar()) != '\n') 
					;
				putchar('\n');
			} else if (c == '*') {
				while ((c=getchar()) != '*' || (c=getchar()) != '/') ;
			} else {
				putchar('/');
				putchar(c);
			}
		} else if (c == '\\') { 
				putchar('\\');
				putchar(getchar());
		} else if (c == '\"') {
			// process " "
			putchar(c);
			while ((c = getchar()) != '\"') 
				putchar(c);
			putchar('\"');
		} else {
			putchar(c);
		}
	}
}
