#include <stdio.h>

int StrLen(const char *s) {
	int n;
	
	for (n = 0; *s != '\0'; s++) {
		n++;
	}

	return n;
}

int StrLen2(const char *s) {
	const char *p = s;

	while (*p != '\0') 
		p++;
	return p - s;
}

int main()
{
	const char *s1 = "hi";
	const char *s2 = "hello";

	printf("%s %d\n", s1, StrLen(s1));
	printf("%s %d\n", s2, StrLen(s2));

	printf("%s %d\n", s1, StrLen2(s1));
	printf("%s %d\n", s2, StrLen2(s2));
}
