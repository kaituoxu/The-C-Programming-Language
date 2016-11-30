#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100

int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = Getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				Push(atof(s));
				break;
			case '+':
				Push(Pop() + Pop());
				break;
			case '*':
				Push(Pop() * Pop());
				break;
			case '-':
				op2 = Pop();
				Push(Pop() - op2);
				break;
			case '/':
				op2 = Pop();
				if (op2 != 0.0) {
					Push(Pop() / op2);
				} else {
					printf("error: zero divisor\n");
				}
				break;
			case '\n':
				printf("\t%.8g\n", Pop());
				break;
			default:
				printf("error: unknow command %s\n", s);
				break;
		}
	}
	return 0;
}
