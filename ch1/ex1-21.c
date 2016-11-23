#include <stdio.h>

int main()
{
	int c, ntab, blank_str_len;

	ntab = 8;
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
