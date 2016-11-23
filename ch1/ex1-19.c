#include <stdio.h>

#define MAXLEN 1000

int GetLine(char line[], int maxlen);
void Reverse(char from[], char to[], int len);

int main()
{
	char line[MAXLEN] = "\0";
	char reverse_line[MAXLEN] = "\0";
	int len;

	while ((len = GetLine(line, MAXLEN)) > 0) {
		Reverse(line, reverse_line, len);
		printf("Reverse: %s\n", reverse_line);
	}
	return 0;
}

int GetLine(char line[], int maxlen)
{
	int c, i;

	for (i = 0; i<maxlen-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
		line[i] = c;
	}
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

void Reverse(char from[], char to[], int len)
{
	int i;
	char c;

	for (i = 0; i < len-1; ++i) {
		to[len-2-i] = from[i];
	}
	to[len-1] = from[len-1];
	to[len] = '\0';
}
