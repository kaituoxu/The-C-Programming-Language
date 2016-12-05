#include <stdio.h>
#include <string.h> // use strstr(line, argv)
#include "utils.h"

#define MAXCHAR 1000

/* Usage:
 * argv[0] -x -n <pattern>
 * argv[0] -xn <pattern>
 */ 

int main(int argc, char *argv[]) {
	char line[MAXCHAR];
	long line_no = 0;
	int c, found = 0, except = 0, number = 0;

	while (--argc > 0 && (*++argv)[0] == '-') {
		while (c = *++argv[0]) {
			switch (c) {
				case 'x':
					except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf("%s: illegal option %c\n", argv[0], c);
					argc = 0;
					found = -1;
					break;
			}
		}
	}

	if (argc != 1) {
		printf("Usage: %s -x -n pattern\n", argv[0]);
	} else {
		while (GetLine(line, MAXCHAR) > 0) {
			line_no++;
			if ((strstr(line, *argv) != NULL) != except) {
				if (number)
					printf("%ld: ", line_no);
				printf("%s", line);
				found++;
			}
		}
	}
	
	return found;
}
