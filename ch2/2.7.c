int atoi(char s[])
{
	int i, n;
	
	n = 0;
	for (i = 0; '0' <= s[i] && s[i] <= '9'; ++i) {
		n = n * 10 + (s[i] - '0');	
	}

	return n;
}

int lower(char c)
{
	if ('A' <= c && c <= 'Z') {
		return c - 'A' + 'a';
	} else {
		return c;
	}
}
