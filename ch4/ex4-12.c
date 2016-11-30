#include <stdio.h>

#define MAXLINE 1000

void Printd(int n, char s[]) {
	static int i = 0;
	static int len = 1;

	if (n < 0) {
		s[i++] = '-';
		n = -n;
		len++;
	}
	if (n / 10) {
		len++;
		Printd(n / 10, s);
	}
	s[i++] = n % 10 + '0';
	s[i] = '\0';
	if (i == len) {
		i = 0;
		len = 1;
	}
}

int main()
{
	char s[MAXLINE];
	int n;	

	while (scanf("%d", &n)) {
		Printd(n, s);
		printf("%s\n", s);
	}

	return 0;
}
