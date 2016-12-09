#ifndef KANDR_CH6_TREE_H_
#define KANDR_CH6_TREE_H_

typedef struct tnode *TreePtr;

typedef struct tnode {
  char *word;
  int count;
  TreePtr left;
  TreePtr right;
} TreeNode;

TreePtr AddTree(TreePtr p, char *w);
void TreePrint(TreePtr p);

TreePtr TAlloc(void);
char *StrDup(char *s);

#endif // KANDR_CH6_TREE_H_
