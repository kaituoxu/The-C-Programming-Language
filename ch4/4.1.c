#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int GetLine(char line[], int lim);
int StrIndex(char line[], char pattern[]);

char pattern[] = "ould";

int main()
{
	char line[MAXLINE];
	int found;

	found = 0;
	while (GetLine(line, MAXLINE) > 0) {
		if (StrIndex(line, pattern) >= 0) {
			printf("%s", line);
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


int StrIndex(char line[], char pattern[])
{
	int i, j;
	
	for (i = 0; line[i] != '\0'; ++i) {
		for (j = 0; j < strlen(pattern); ++j) {
			if (line[i+j] != pattern[j])
				break;
		}
		if (j == strlen(pattern)) 
			return i;
	}
	return -1;
}

/* K&R version */
int strindex(char s[], char t[])
{
	int i, j, k;

	for (i = 0; s[i] != '\0'; ++i) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k) {
			;
		}
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}
