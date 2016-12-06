#include "utils.h"
#include <stdio.h>
#include <string.h>


void Swap(char *v[], int i, int j) {
	char *temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void Qsort(char *v[], int left, int right) {
	int i, last;

	if (left >= right)
		return ;
	Swap(v, left, (left+right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			Swap(v, ++last, i);
	Swap(v, last, left);
	Qsort(v, 0, last - 1);
	Qsort(v, last + 1, right);
}
