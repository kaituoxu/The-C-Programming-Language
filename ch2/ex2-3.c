#include <ctype.h>
#include <stdio.h>

int main()
{
	int c, n, begin;

	n = 0;
	begin = 1;
	while ((c = getchar()) != EOF) {
		if (begin == 1) {
			begin = 0;
			if (c == '0') {
				if ((c = getchar()) == 'x' || c == 'X') {
					continue;
				} else {
					n = 0;
				}
			}
		}
		if ('A' <= c && c <= 'F')
			n = n * 16 + (c - 'A') + 10;
		else if ('a' <= c && c <= 'f')
			n = n * 16 + (c - 'a') + 10;
		else if (isdigit(c))
			n = n * 16 + (c - '0');
		else if (c == '\n') {
			printf("%d\n", n);
			n = 0;
			begin = 1;
		} else {
			printf("Invalid input!\n");
			return 1;
		}
	}

	return 0;
}
