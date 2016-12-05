#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int c, ntab, nc;

	if (argc == 1)
		ntab = 8;
	else if (argc == 2)
		ntab = atoi(argv[1]);

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
