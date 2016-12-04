#include <stdio.h>

char *MonthName(int n) {
	static char *name[] = {
		"Illegal month",
		"January", "February", "March",
		"April", "May", "June",
		"July", "Augutst", "September",
		"October", "November", "December"
	};

	return (n < 1 || n > 12) ? name[0] : name[n];
}

int main(int argc, char *argv[]) {
	int n;
	
	scanf("%d", &n);
	printf("%s\n", MonthName(n));
}
