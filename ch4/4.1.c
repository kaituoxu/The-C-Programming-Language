#include <stdio.h>

#define MAXLEN 1024

int get_line(char *line, int lim);
int strindex(char *s, char *pattern);

int main(int argc, char *argv[])
{
	char s[MAXLEN];
	char *pattern = argv[1];

	// printf("%s\n", pattern);

	while (get_line(s, MAXLEN) != -1) {
		if (strindex(s, pattern)) {
			printf("%s\n", s);
		}
	}
	return 0;
}

int get_line(char *line, int lim)
{
	char c;
	int len = 0;
	while (len < lim && (line[len] = getchar()) != '\n' && line[len] != EOF)
		++len;
	line[len] = '\0';
	if (len == 0)
		return -1;
	return len;
}

int strindex(char *line, char *pattern)
{
	int i, j;
	for (i = 0; line[i] != '\0'; ++i) {
		for (j = 0; pattern[j] != '\0'; ++j) {
			if (line[i+j] == '\0' || line[i+j] != pattern[j])
				break;
		}
		if (pattern[j] == '\0') {
			return i+j;
		}
	}
	return 0;
}
