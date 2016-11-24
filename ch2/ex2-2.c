#include <stdio.h>

#define MAXLINE 1000

int main()
{
	/* equal to:
	 * for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
	 *   s[i] = c;
	 */
	char s[MAXLINE];
	int i, c, lim;

	lim = MAXLINE;
	for (i = 0; i<lim-1; ++i) {
		if ((c = getchar()) != '\n') {
			if (c != EOF) {
				s[i] = c;
			} else {
				break;
			}
		} else {
			break;
		}
	}
	printf("%s\n", s);

	return 0;
}
