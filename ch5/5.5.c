/* array version */
void StrCpy1(char *s, char *t) {
	int i;

	i = 0;
	while ((s[i] = t[i]) != '\0') 
		i++;
}

/* pointer version 1 */
void StrCpy2(char *s, char *t) {
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}

/* pointer version 2 */
void StrCpy3(char *s, char *t) {
	while ((*s++ = *t++) != '\0')
		;
}

/* pointer version 3 */
void StrCpy4(char *s, char *t) {
	while (*s++ = *t++)
		;
}

/* array version */
int StrCmp1(char *s, char *t) {
	int i;
	for (i = 0; s[i] == t[i]; i++) {
		if (s[i] == '\0')
			return 0;
	}

	return s[i] - t[i];
}

/* pointer version */
int StrCmp2(char *s, char *t) {
	for ( ; *s == *t; s++, t++) {
		if (*s == '\0')
			return 0;
	}

	return *s - *t;
}
