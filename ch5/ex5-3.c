#include <stdio.h>

#define MAXCHAR 1000

void StrCat(char *s, char *t) {
	while (*s++)
		;
	s--;
	while (*s++ = *t++)
		;
}

int main()
{
	char s[MAXCHAR], t[MAXCHAR];

	scanf("%s", s);
	scanf("%s", t);
	StrCat(s, t);
	printf("%s\n", s);

	return 0;
}
