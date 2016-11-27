#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXCHAR 1000

void expand(char s[], char t[])
{
	int i, j, k;
	int step;

	for (i = 0, j = 0, step = 2; s[i] != '\0'; ++i) {
		if (s[i+1] == '-' && s[i] < s[i+2]) {
			if (s[i+3] == '-' && s[i] < s[i+4]) {
				// process a-b-c
				step = 4;
			} else {
				step = 2;
			}
			if ((isalpha(s[i]) && isalpha(s[i+step])) || (isdigit(s[i]) && isdigit(s[i+step]))) {
				for (k = 0; s[i] + k <= s[i+step]; ++k)
					t[j++] = s[i] + k;
				if (i + step < strlen(s))
					i += step;
			}
		} else {
			t[j++] = s[i];
		}
	} //for
	t[j] = '\0';
}

int main()
{
	char s[MAXCHAR], t[MAXCHAR];
	fgets(s, sizeof(s), stdin);
	expand(s, t);
	printf("%s\n", t);

	return 0;
}
