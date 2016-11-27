#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXCHAR 1000

/* reverse char in string s */
void reverse(char s[])
{
	int i, j, c;

	for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/* sort v[0] ... v[n-1] */
void shellsort(int v[], int n)
{
	int gap, i, j, temp;

	for (gap = n/2; gap > 0; gap /= 2)
		for (i = gap; i < n; ++i)
			for (j = i-gap; j>=0 && v[j] > v[j+gap]; j-= gap) {
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = v[j];
			}
}

/* atoi() version 2*/
int atoi(char s[])
{
	int i, n, sign;
	for (i = 0; isspace(s[i]); ++i)
		;

	sign = (s[i] == '-') ? -1 : 1;
	
	if (s[i] == '+' || s[i] == '-')
		++i;
	
	for (n = 0; isdigit(s[i]); ++i)
		n = 10 * n + (s[i] - '0');
	
	return sign * n;	
}

int main()
{
	char s[MAXCHAR];
	printf("Enter number string: ");
	scanf("%s", s);
	printf("%d\n", atoi(s));
	return 0;
}
