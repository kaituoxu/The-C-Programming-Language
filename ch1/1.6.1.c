#include <stdio.h>

#define NUM_OF_DIGIT 10

int main()
{
	int c, i, nwhite, nother;
	int ndigit[NUM_OF_DIGIT];

	nwhite = nother = 0;
	for (i = 0; i < NUM_OF_DIGIT; ++i) {
		ndigit[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if ('0' <= c && c <= '9') {
			++ndigit[c-'0'];
		} else if (c == ' ' || c == '\t' || c == '\n') {
			++nwhite;
		} else {
			++nother;
		}
	}

	printf("digits =");
	for (i = 0; i < NUM_OF_DIGIT; ++i)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n", nwhite, nother);

	return 0;
}
