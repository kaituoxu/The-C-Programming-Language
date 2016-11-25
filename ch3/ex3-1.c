#include <stdio.h>

#define N 15

/* find x in v, v[0] <= v[1] <= .. <= v[n-1] */
int BinarySearch(int x, int v[], int n)
{
	int mid, low, high;

	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	while (low <= high && x != v[mid]) {
		mid = (low + high) / 2;
		if (x < v[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		} 
	}
	if (low <= high)
		return mid;
	else 
		return -1;
}

int main()
{
	int v[N];
	int x, i;

	for (i = 0; i < N; ++i) 
		v[i] = i;

	printf("Enter x: ");
	scanf("%d", &x);
	printf("position of x in array v is %d\n", BinarySearch(x, v, N));

	return 0;
}
