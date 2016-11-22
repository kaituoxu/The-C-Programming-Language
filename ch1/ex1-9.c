#include <stdio.h>

/* version 1 */

// int main()
// {
// 	int c;
// 
// 	while ((c = getchar()) != EOF) {
// 		if (c == ' ') {
// 			putchar(' ');
// 			while ((c = getchar()) == ' ') ;
// 		} 
// 		putchar(c);
// 	}
// 
// 	return 0;
// }

/* version 2 */

#define PREV_IS_BLANK 1
#define PREV_NO_BLANK 0

int main()
{
	int c, state;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (state == PREV_NO_BLANK) {
				putchar(' ');
				state = PREV_IS_BLANK;
			}
		} else {
			putchar(c);
			state = PREV_NO_BLANK;
		}
	}
	
	return 0;
}
