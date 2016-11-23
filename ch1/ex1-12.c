#include <stdio.h>

#define IN	 1 /* in word  */
#define OUT	 0 /* out word */

int main()
{
	int c, state, first_word;

	state = OUT;
	first_word = 1;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			state = OUT;
		} else if (state == OUT) {
			state = IN;
			if (first_word == 1) {
				first_word = 0;
				printf("%c", c);
			}
			else 
				printf("\n%c", c);
		} else if (state == IN) {
			putchar(c);
		}
	}
	
	return 0;
}
