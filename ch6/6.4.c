#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "key.h"
#include "getch.h"
#include "getword.h"

#define MAXWORD 100
#define NKEYS (sizeof key_tab / sizeof key_tab[0])

struct Key *BinSearch(char *, struct Key *, int);


int main(int argc, char *argv[]) { char word[MAXWORD];
  struct Key *p;

  while (GetWord(word, MAXWORD) != EOF) {
    if (isalpha(word[0]))
      if ((p = BinSearch(word, key_tab, NKEYS)) != NULL)
        p->count++;
  }
  for (p = key_tab; p < key_tab + NKEYS; p++) {
    if (p->count > 0)
      printf("%4d %s\n", p->count, p->word);
  }

  return 0;
}


struct Key *
BinSearch(char *word, struct Key tab[], int n) {
  int cond;
  struct Key *low = &tab[0];
  struct Key *high = &tab[n];
  struct Key *mid;

  while (low < high) {
    mid = low + (high - low) / 2;
    if ((cond = strcmp(word, mid->word)) < 0)
      high = mid;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }
  return NULL;
}
