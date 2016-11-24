#include <stdio.h>
#include <string.h>

int Lower(int c)
{
	return ('A' <= c && c <= 'Z') ? c - 'A' + 'a' : c;
}

int main()
{
	char s[] = "AbCDEfGHIjK";
	int i;

	for (i = 0; i < strlen(s); ++i) {
		s[i] = Lower(s[i]);
	}

	printf("%s\n", s);
	
	return 0;
}
