#include <stdio.h>

/* echo: version 1 */

// int main(int argc, char *argv[]) {
// 	int i;
// 
// 	for (i = 1; i < argc; i++) {
// 		printf("%s%s", argv[i], (i < argc - 1) ? " " : "\n");
// 	}	
// 
// 	return 0;
// }

/* echo: version 2 */

int main(int argc, char *argv[]) {
	while (--argc > 0) {
		printf("%s%s", *++argv, (argc > 1) ? " " : "\n");
	}
	return 0;
}
