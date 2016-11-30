#include <stdio.h>

#define SWAP(t, x, y) { t temp; (temp) = (x); (x) = (y); (y) = (temp); }

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	SWAP(int, x, y);
	printf("x = %d, y = %d\n", x, y);

	double a, b;
	scanf("%lf %lf", &a, &b);
	SWAP(double, a, b);
	printf("x = %lf, y = %lf\n", a, b);
	return 0;
}
