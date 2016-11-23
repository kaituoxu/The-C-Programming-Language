#include <stdio.h>

void fahr2celsius(int lower, int upper, int step);

int main()
{
	int lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;
	fahr2celsius(lower, upper, step);

	return 0;
}

void fahr2celsius(int lower, int upper, int step)
{
	int fahr;
	for (fahr = lower; fahr <= upper; fahr+=step)
		printf("%3d %6.1lf\n", fahr, (5.0/9.0)*(fahr-32));
}
