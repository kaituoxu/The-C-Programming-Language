#include <stdio.h>
#include <limits.h>
/* signed char
 * unsigned char
 * signed short int
 * unsigned short int
 * signed int
 * unsigned int
 * signed long int
 * unsigned long int
 */

int main()
{
	printf("signed char: %d %d\n", CHAR_MIN, CHAR_MAX);
	printf("unsigned char: %d %d\n", 0, UCHAR_MAX);
	printf("signed short int: %d %d\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned short int: %d %d\n", 0, USHRT_MAX);
	printf("signed int: %d %d\n", INT_MIN, INT_MAX);
	printf("unsigned int: %d %d\n", 0, UINT_MAX);
	printf("signed long int: %ld %ld\n", LONG_MIN, LONG_MAX);
	printf("unsigned long int: %d %ld\n", 0, ULONG_MAX);
	return 0;
}
