#include <stdio.h>
#include <string.h>

int StrEnd(const char *s, const char *t) {
	int t_len = strlen(t);

	while (*s++)
		;
	s--;
	t += t_len;

	while (t_len--) {
		if (*s-- != *t--)
			return 0;
	}
	return 1;
}

int main()
{
	const char *s = "abc";
	const char *t = "bc";

	printf("%d\n", StrEnd(s, t));
	return 0;
}
