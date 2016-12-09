#include "tree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

TreePtr AddTree(TreePtr p, char *w) {
  int cond;

  if (p == NULL) {
    p = TAlloc();
    p->word = StrDup(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0) {
    p->count++;
  } else if (cond < 0) {
    p->left = AddTree(p->left, w);
  } else  { 
    p->right = AddTree(p->right, w);
  }
  return p;
}

void TreePrint(TreePtr p) {
  if (p != NULL) {
    TreePrint(p->left);
    printf("%4d %s\n", p->count, p->word);
    TreePrint(p->right);
  }
}

TreePtr TAlloc(void) {
  return (TreePtr)malloc(sizeof(TreeNode));
}

char *StrDup(char *s) {
  char *p;

  p = (char *)malloc(strlen(s) + 1);
  if (p != NULL)
    strcpy(p, s);
  return p;
}
