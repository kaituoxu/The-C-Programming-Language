#include "utils.h"
#include <stdio.h>

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
