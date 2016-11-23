#include <stdio.h>

#define MAXLEN 1000

int GetLine(char line[], int maxlen);
int DeleteTailBlankAndTab(char line[], int len);

int main()
{
	char line[MAXLEN] = "\0";
	char maxline[MAXLEN] = "\0";
	int len, lim;

	lim = 80;
	while ((len = GetLine(line, MAXLEN)) > 0) {
		if ((len = DeleteTailBlankAndTab(line, len)) > 0) {
// 			printf("%d ", len);
			printf("%s", line);
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

int DeleteTailBlankAndTab(char line[], int len)
{
	int has_newline = 0;

	if (line[len-1] == '\n') {
		has_newline = 1;
		--len;
	}

	for (--len; len >= 0; --len) {
		if (line[len] == ' ' || line[len] == '\t') {
			continue;
		} else {
			break;
		}
	}
	if (len < 0) {
		return 0;
	} else {
		if (has_newline == 1) {
			line[++len] = '\n';
		}
		line[++len] = '\0';
		return len-1;
	}
}
