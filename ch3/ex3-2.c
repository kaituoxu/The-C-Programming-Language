#include <stdio.h>

#define MAXCHAR 1000

/* Copy string t to string s 
 * replace '\n' with '\\' 'n', '\t' with '\\' 't' etc.
 */
void escape(char s[], char t[])
{
	int i, j;

	for (i = 0, j = 0; t[i] != '\0'; ++i) {
		switch (t[i]) {
			case '\a':
				s[j++] = '\\';
				s[j++] = 'a';
				break;
			case '\b':
				s[j++] = '\\';
				s[j++] = 'b';
				break;
			case '\f':
				s[j++] = '\\';
				s[j++] = 'f';
				break;
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			case '\r':
				s[j++] = '\\';
				s[j++] = 'r';
				break;
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			case '\v':
				s[j++] = '\\';
				s[j++] = 'v';
				break;
			default:
				s[j++] = t[i];
				break;
		}
	}	
	s[j] = '\0';
}

int main()
{
	char t[MAXCHAR], s[MAXCHAR];
	fgets(t, sizeof(t), stdin);
	escape(s, t);
	printf("%s\n", s);	
	return 0;
}
