#include <stdio.h>

int BitCount(unsigned x)
{
	int n;
	for (n = 0; x != 0; x >>= 1)
		if (x & 01)
			++n;
	return n;
}

int FastBitCount(unsigned x)
{
	int n;
	for (n = 0; x != 0; x &= (x-1))
		++n;
	return n;
}

int main()
{
	int x = 0731;
	printf("%d %d\n", BitCount(x), FastBitCount(x));
	return 0;
}
