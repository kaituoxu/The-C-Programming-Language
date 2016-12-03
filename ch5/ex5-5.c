#include <stdio.h>
#include <string.h>

#define MAXCHAR 1000

void StrNCpy(char *s, const char *t, int n) {
	while (n-- && (*s++ = *t++))
		;
	if (n < 0)
		*s = '\0';
}

void StrNCat(char *s, const char *t, int n) {
	while (*s++)
		;
	s--;
	while (n-- && (*s++ = *t++))
		;
	if (n < 0)
		*s = '\0';
}

int StrNCmp(const char *s, const char *t, int n) {
	for (; n && *s == *t; n--, s++, t++) {
		if (*s == '\0')
			return 0;
	}	
	return *s - *t;
	
}

int main()
{
	char s[MAXCHAR];
	const char *t = "Hello,world";

	StrNCpy(s, t, 5);
	printf("%s\n", s);

	StrNCat(s, t, 10);
	printf("%s\n", s);

	printf("%d\n", StrNCmp("hello", "hello", 5));
	printf("%d\n", StrNCmp("hellx", "hello", 4));
	printf("%d\n", StrNCmp("hellx", "hello", 5));

	return 0;
}
