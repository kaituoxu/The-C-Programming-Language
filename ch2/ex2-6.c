#include <stdio.h>

int SetBits(int x, int p, int n, int y)
{
	int tmp = ((~(~0<<(p+1)))&(~0<<(p+1-n)));
	printf("Oct: %o\n", tmp);
	return (x & ~tmp) | ((y<<(p+1-n)) & tmp);
}

int main()
{
	int x = 50; // 0011 0010
	int y = 3;  // 0000 0011
	int p = 4;
	int n = 2;
	printf("Oct: %o\n", SetBits(x, p, n, y));
	return 0;
}
