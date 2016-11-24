#include <stdio.h>

int any(char s1[], char s2[])
{
	int i, j;
	for (i = 0; s1[i] != '\0'; ++i) {
		for (j = 0; s2[j] != '\0'; ++j) {
			if (s1[i] == s2[j]) {
				return i+1;
			}
		}
	}
	return -1;	
}


int main()
{
	char s1[] = "hello, world";
	char s2[] = "wxyz";
	
	printf("s1:%s\n"
				 "s2:%s\n", s1, s2);
	printf("s2 first occur in s1 %d\n", any(s1, s2));
	return 0;
}
