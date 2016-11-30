#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
			// %
			case '%':
				op2 = Pop();
				Push((int)Pop() % (int)op2);
				break;
			// sin
			case 's':
				Push(sin(Pop()));
				break;
			// exp
			case 'e':
				Push(exp(Pop()));
				break;
			// pow
			case 'p':
				op2 = Pop();
				Push(pow(Pop(), op2));
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
