#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int GetLine(char line[], int lim);
int StrRIndex(char line[], char pattern[]);

char pattern[] = "ould";

int main()
{
	char line[MAXLINE];
	int found;
	int last_pos;

	found = 0;
	while (GetLine(line, MAXLINE) > 0) {
		if ((last_pos = StrRIndex(line, pattern)) >= 0) {
			printf("%d--%s", last_pos, line);
			found++;
		}
	}

	return found;
}

int GetLine(char line[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c!='\n'; ++i) {
		line[i] = c;
	}
	if (c == '\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
}


int StrRIndex(char s[], char t[])
{
	int i, j, k, last;

	last = -1;
	for (i = 0; s[i] != '\0'; ++i) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k) {
			;
		}
		if (k > 0 && t[k] == '\0')
			last = i;
	}
	return last;
}
