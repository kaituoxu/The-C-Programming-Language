#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "tree.h"
#include "getword.h"

#define MAXWORD 100

int main(int argc, char *argv[]) {
  TreePtr root;
  char word[MAXWORD];

  root = NULL;
  while (GetWord(word, MAXWORD) != EOF) {
    if (isalpha(word[0]))
      root = AddTree(root, word);
  }
  TreePrint(root);

  return 0;
}
