#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[])
{
	int i, j, c;

	for (i = 0, j = strlen(s) -1 ; i < j; ++i, --j) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(int n, char s[], int base)
{
	int sign, i, mod;

	sign = n;

	i = 0;
	do {
		if ((mod = n%base) < 0)
			mod = -mod;
		s[i++] = mod + '0';
	} while ((n /= base) != 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main()
{
	char s[100];
	int n, base;

	printf("INT_MIN = %d\n", INT_MIN);
	printf("INT_MAX = %d\n", INT_MAX);

	printf("10%%-6=%d\n", 10%(-6));
	printf("10%%6=%d\n", 10%(6));
	printf("-10%%6=%d\n", (-10)%(6));
	printf("-6%%10=%d\n", (-6)%(10));

	printf("Enter n: ");
	scanf("%d", &n);
	printf("Enter base: ");
	scanf("%d", &base);
	printf("n = %d\n", n);

	itoa(n, s, base);
	printf("%s\n", s);
	return 0;
}
