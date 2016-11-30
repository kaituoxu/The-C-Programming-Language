#include <stdio.h>

void Swap(int v[], int i, int j) {
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void Printd(int n) {
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n / 10)
		Printd(n / 10);
	putchar(n % 10 + '0');
}

void Qsort(int v[], int left, int right) {
	int i, last;

	if (left >= right)
		return ;
	Swap(v, left, (left + right) / 2);
	last = left;
	for (i = left+1; i <= right; ++i)
		if (v[i] < v[left])
			Swap(v, ++last, i);
	Swap(v, left, last);
	Qsort(v, left, last-1);
	Qsort(v, last+1, right);
}

int main()
{
// 	int n;
// 	scanf("%d", &n);
// 	Printd(n);
	int v[] = { 10, 2, 3, 5, 4, 1, 9, 8, 6, 7 };
	int i;

	Qsort(v, 0, 9);

	for (i = 0; i < 10; ++i)
		printf("%d%c", v[i], (i < 9) ? ' ' : '\n');
	
	return 0;
}
