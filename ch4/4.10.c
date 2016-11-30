#include <stdio.h>

void Printd(int n) {
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n / 10)
		Printd(n / 10);
	putchar(n % 10 + '0');
}

int main()
{
	int n;
	scanf("%d", &n);
	Printd(n);
	return 0;
}
