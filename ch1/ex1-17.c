#include <stdio.h>

#define MAXLEN 1000

int GetLine(char line[], int maxlen);
void Copy(char to[], char from[]);

int main()
{
	char line[MAXLEN] = "\0";
	char maxline[MAXLEN] = "\0";
	int len, lim;

	lim = 80;
	while ((len = GetLine(line, MAXLEN)) > 0) {
		if (len > lim) {
			printf("%s\n", line);
		}
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

void Copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}
