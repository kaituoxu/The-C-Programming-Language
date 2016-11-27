#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
	int i, j, c;

	for (i = 0, j = strlen(s) -1 ; i < j; ++i, --j) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(int n, char s[])
{
	int sign, i;

	if ((sign = n) < 0) {
		n = -n;
	}

	i = 0;
	if (n == 0)
		s[i++] = '0';
	while (n > 0) {
		s[i++] = n % 10 + '0';
		n /= 10;
	}
	if (sign < 0) 
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void itoa2(int n, char s[])
{
	int sign, i;

	if ((sign = n) < 0)
		n = -n;

	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void itoa3(int n, char s[])
{
	int sign, i;

	sign = n;

	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) != 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main()
{
	char s[100];
	int n;
	printf("Enter n: ");
	scanf("%d", &n);
	printf("n = %d\n", n);
	itoa(n, s);
	printf("%s\n", s);
	itoa2(n, s);
	printf("%s\n", s);
	itoa3(n, s);
	printf("%s\n", s);
	return 0;
	return 0;
}
