#include <stdio.h>

#define IN	 1 /* in word  */
#define OUT	 0 /* out word */

int main()
{
	int c, nl, nw, nc, state;

	nl = nw = nc = 0;
	state = OUT;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == ' ' || c == '\t' || c == '\n') {
			state = OUT;
		} else if (state == OUT) {
			++nw;
			state = IN;
		}
		if (c == '\n') {
			++nl;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
	
	return 0;
}
