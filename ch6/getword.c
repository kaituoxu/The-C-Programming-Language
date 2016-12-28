#include "getword.h"
#include <ctype.h>
#include <stdio.h>
#include "getch.h"

int GetWord(char *word, int lim) {
  int c;
  char *w = word;

  while (isspace(c = Getch())) {
    ;
  }
  if (c != EOF)
    *w++ = c;
  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }
  for ( ; --lim > 0; w++) {
    if (!isalnum(*w = Getch())) {
      Ungetch(*w);
      break;
    }
  }
  *w = '\0';
  return word[0];
}


/* exercise 6-1 solution */
int GetWordEx1(char *word, int lim) {
  int Comment(void);
  int c, d;
  char *w = word;

  while (isspace(c = Getch())) {
    ;
  }
  if (c != EOF)
    *w++ = c;
  if (isalpha(c) || c == '_' || c == '#') {
    for ( ; --lim > 0; w++) {
      if (!isalnum(*w = Getch()) && *w != '_') {
        Ungetch(*w);
        break;
      }
    }

  }
}
