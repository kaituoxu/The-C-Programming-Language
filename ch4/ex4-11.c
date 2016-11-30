#include "calc.h"
#include <ctype.h>
#include <stdio.h>

#define MAXLINE 1000

int Getop(char s[]) {
	int i, c;
	static int buf = EOF;

	if (buf != EOF) {
		s[0] = c = buf;
		buf = EOF;
	} else {
		s[0] = c = Getch();
	}

	while (c == ' ' || c == '\t') {
		s[0] = c = Getch();
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
	if (c != EOF) {
		if (buf == EOF) 
			buf = c;
		else 
			printf("ungetch: too many characters\n");
		//Ungetch(c);	
	}
	return NUMBER;
}

int main()
{
	char s[MAXLINE];
	int type;

	while ((type = Getop(s)) != EOF) {
		putchar(type);
		if (type == NUMBER) {
			if ((type = Getop(s)) == '*') {
				putchar('!');
			}
		}
	}

	return 0;
}
