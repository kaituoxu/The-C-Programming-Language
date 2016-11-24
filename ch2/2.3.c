#include <stdio.h>

int main()
{
	enum months { JAN = 1, FEB, MAR, APR, MAY, JUN,
								JUL, AUG, SEP, OCT, NOV, DEC };
	printf("%d\n", OCT);

	return 0;
}
