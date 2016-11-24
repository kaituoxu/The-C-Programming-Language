#include <stdio.h>

int Invert(int x, int p, int n)
{
	int tmp = ((~(~0<<(p+1)))&(~0<<(p+1-n)));
	printf("Oct: %o\n", tmp);
	return x ^ tmp;
}

int main()
{
	int x = 50; // 0011 0010
	int p = 4;
	int n = 3;
	printf("Oct: %o\n", Invert(x, p, n));
	return 0;
}
