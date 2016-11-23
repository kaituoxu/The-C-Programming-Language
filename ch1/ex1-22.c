#include <stdio.h>

int main()
{
	int c, len, n;

	printf("Enter n: ");
	scanf("%d", &n);
	getchar(); // read '\n'

	len = 0;
	while ((c = getchar()) != EOF) {
		++len;
		if (len == n && c != '\n') {
			putchar('\n');
			len -= (n-1);
		}
		if (c == '\n')
			len = 0;
		putchar(c);
	}

	return 0;
}
