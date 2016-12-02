#include <stdio.h>

int main()
{
	int x, y, z[10];
	int *ip, *iq;

	x = 1;
	y = 2;

	ip = &x;
	iq = &y;
	printf("x = %d, y = %d\n", x, y);
	printf("ip = %lx, *ip = %d\n", ip, *ip);
	printf("iq = %lx, *iq = %d\n", iq, *iq);

	*ip = 0;
	printf("After(*ip = 0)\n");
	printf("x = %d, ip = %lx, *ip = %d\n", x, ip, *ip);
	printf("y = %d, iq = %lx, *iq = %d\n", y, iq, *iq);

	iq = ip;
	printf("After(iq = ip)\n");
	printf("x = %d, y = %d, iq = %lx, *iq = %d\n", x, y, iq, *iq);

	return 0;
}
