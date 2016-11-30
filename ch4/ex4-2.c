#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include "utils.h"

#define MAXLINE 1000

double AtofExpand(char s[])
{
	double val, power, exp;
	int i, sign, exp_sign;

	for (i = 0; isspace(s[i]); ++i) {
		;
	}
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		++i;
	for (val = 0.0; isdigit(s[i]); ++i)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		++i;
	for (power = 1.0; isdigit(s[i]); ++i) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	if (s[i] == 'e' || s[i] == 'E')
		++i;
	exp_sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		++i;
	for (exp = 0.0; isdigit(s[i]); ++i)
		exp = 10.0 * exp + (s[i] - '0');

	return sign * val / power * pow(10, exp_sign * exp);
}

int main()
{
	char s[MAXLINE];
	double sum;

	sum = 0.0;
	while (GetLine(s, MAXLINE) > 0) {
		printf("\t%g\n", sum += AtofExpand(s));
	}

	return 0;
}
