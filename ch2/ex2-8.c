#include <stdint.h>
#include <stdio.h>

/* only work on 32 bits integer */
int32_t RightROt(int32_t x, int n)
{
	int32_t t = x;
	return ((~(~0<<n) & t)<<(32-n)) | (x>>n);
}

int main()
{
	int32_t x;
	int n;
	printf("Enter x and n: ");
	scanf("%d %d", &x, &n);
	printf("x = %d, RightROt(%d, %d) = %d\n", x, x, n, RightROt(x, n));
}
