/* const */
#include <stdio.h>

int main()
{
	const double e = 2.71828182845905;
	const char msg[] = "warning: ";
	const char *usg = "hi, "
										"there";

	printf("%s\n", msg);
	printf("%s\n", usg);

	return 0;
}
