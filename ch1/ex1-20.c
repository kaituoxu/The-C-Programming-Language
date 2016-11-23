#include <stdio.h>

int main()
{
	int c, ntab, nc;

	printf("one tab equals how much blank space?");
	scanf("%d", &ntab);

	nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\t') {
			putchar(' ');
			for (++nc; nc % ntab != 1; ++nc)
				putchar(' ');
			--nc;
		} else {
			putchar(c);
			if (c == '\n')
				nc = 0;
		}
	}

	return 0;
}
