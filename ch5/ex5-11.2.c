#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int c, ntab, blank_str_len;

	if (argc == 1)
		ntab = 8;
	else if (argc == 2)
		ntab = atoi(argv[1]);

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			for (blank_str_len = 1; (c=getchar()) == ' '; ++blank_str_len) ;
			while (blank_str_len - ntab >= ntab) {
				blank_str_len -= ntab;
				putchar('\t');
			}
			while (blank_str_len-- > 0) {
				putchar(' ');
			}
		}
		putchar(c);
	}

	return 0;
}
