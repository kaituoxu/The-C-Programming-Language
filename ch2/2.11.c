#include <stdio.h>
#include <stdlib.h>

#define N 100

int main()
{
	int a[N];
	int i;

	for (i = 0; i < N; ++i)
		a[i] = rand()%100000;

	for (i = 0; i < N; ++i)
		printf("%6d%c", a[i], (i%10==9 || i==N-1) ? '\n' : ' ');
	printf("You have %d item%s.\n", N, N==1 ? "" : "s");

	return 0;
}
