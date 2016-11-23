#include <stdio.h>

#define MAXLEN 1000

int GetLine(char line[], int maxlen);
void Copy(char to[], char from[]);

int main()
{
	char line[MAXLEN] = "\0";
	char maxline[MAXLEN] = "\0";
	int len, maxlen;

	maxlen = 0;
	while ((len = GetLine(line, MAXLEN)) > 0) {
		printf("%d ", len);
// 		if (len > maxlen) {
// 			maxlen = len;
// 			Copy(maxline, line);
// 		}
	}
// 	if (maxlen > 0) {
// 		printf("%s\n", maxline);
// 	}

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
