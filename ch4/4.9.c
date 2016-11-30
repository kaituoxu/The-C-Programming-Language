#include <stdio.h>
#include <string.h>

int main()
{
	char s[] = "abcde";
	printf("%lu %lu\n", sizeof(s), strlen(s));
	return 0;
}
