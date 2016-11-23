/* I use a simple stack to solve this problem.
 * I don't process comment.
 * It should be added later.
 */
#include <stdio.h>

#define MAXCHAR 1000

int main()
{
	char stack[MAXCHAR];
	int c, top, nl;

	nl = 1;
	top = -1;
	while ((c = getchar()) != EOF) {
		switch (c) {
			/* process double quotation */
			case '\"':
				while ((c = getchar()) != '\"') ;
				break;

			/* process single quotation */
			case '\'':
				if ((c = getchar()) == '\\') {
					getchar();
				}
				if ((c = getchar()) != '\'') {
					printf("error about single quotation in line: %d\n", nl);
				}
				break;

			/* process () {} [] */
			case '(':
			case '{':
			case '[':
				stack[++top] = c;
				break;
			case ')':
				if (stack[top--] != '(') {
					printf("error about () in line: %d\n", nl);
					return 0;
				}
				break;
			case '}':
				if (stack[top--] != '{') {
					printf("error about {} in line: %d\n", nl);
					return 0;
				}
				break;
			case ']':
				if (stack[top--] != '[') {
					printf("error about [] in line: %d\n", nl);
					return 0;
				}
				break;

			/* for error report */
			case '\n':
				++nl;
				break;
			default:
				;
		} // switch
	} // while
	return 0;
}
