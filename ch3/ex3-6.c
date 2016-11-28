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

void itoa3(int n, char s[])
{
	int sign, i, mod;

	sign = n;

	i = 0;
	do {
		if ((mod = n%10) < 0)
			mod = -mod;
		s[i++] = mod + '0';
	} while ((n /= 10) != 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void itoa4(int n, char s[], int min_len)
{
	int sign, i, mod, step;

	sign = n;

	i = 0;
	do {
		if ((mod = n%10) < 0)
			mod = -mod;
		s[i++] = mod + '0';
	} while ((n /= 10) != 0);

	if (sign < 0)
		s[i++] = '-';

// 	if (i < min_len) {
// 		step = min_len - i;
// 		for (--i; i >= 0; --i) {
// 			s[i + step] = s[i];
// 		}
// 		for (i = 0; i < step; ++i)
// 			s[i] = ' ';
// 		s[min_len] = '\0';
// 	} else {
// 		s[i] = '\0';
// 	}

	s[i] = '\0';

	if (i < min_len) {
		for (; i < min_len; ++i)
			s[i] = ' ';
		s[i] = '\0';
	}
	reverse(s);
}

int main()
{
	char s[100];
	int n;
	int min_len;

	printf("INT_MIN = %d\n", INT_MIN);
	printf("INT_MAX = %d\n", INT_MAX);

	printf("10%%-6=%d\n", 10%(-6));
	printf("10%%6=%d\n", 10%(6));
	printf("-10%%6=%d\n", (-10)%(6));
	printf("-6%%10=%d\n", (-6)%(10));

	printf("Enter n: ");
	scanf("%d", &n);
	printf("n = %d\n", n);

	itoa3(n, s);
	printf("%s\n", s);

	printf("Enter min len: ");
	scanf("%d", &min_len);
	itoa4(n, s, min_len);
	printf("%s\n", s);
	return 0;
}
