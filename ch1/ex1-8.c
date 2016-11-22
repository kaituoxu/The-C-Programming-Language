#include <stdio.h>

int main()
{
	int c;
	long nspace;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			++nspace;
		}
	}
	printf("%ld\n", nspace);

	return 0;
}
