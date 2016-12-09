#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "key.h"
#include "getch.h"
#include "getword.h"

#define MAXWORD 100
#define NKEYS (sizeof key_tab / sizeof key_tab[0])

int BinSearch(char *, struct Key *, int);


int main(int argc, char *argv[]) {
  int n;
  char word[MAXWORD];

  while (GetWord(word, MAXWORD) != EOF) {
    if (isalpha(word[0]))
      if ((n = BinSearch(word, key_tab, NKEYS)) >= 0)
        key_tab[n].count++;
  }
  for (n = 0; n < NKEYS; n++) {
    if (key_tab[n].count > 0)
      printf("%4d %s\n", key_tab[n].count, key_tab[n].word);
  }

  return 0;
}


int BinSearch(char *word, struct Key tab[], int n) {
  int cond;
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if ((cond = strcmp(word, tab[mid].word)) < 0)
      high = mid - 1;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}
