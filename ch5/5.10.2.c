#include <stdio.h>
#include <string.h>
#include "utils.h"

#define MAXCHAR 1000

int main(int argc, char *argv[]) {
	char line[MAXCHAR];
	int found = 0;

	if (argc != 2) {
		printf("Usage: %s <pattern>\n", argv[0]);
	} else {
		while (GetLine(line, MAXCHAR) > 0) {
			if (strstr(line, argv[1]) != NULL) {
				printf("%s", line);
				found++;
			}
		}
	}

	return found;
}
