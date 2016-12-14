#include <string.h>
#include <stdlib.h>
#include "tree.h"

#define HASHSIZE 101

struct Nlist {
  struct Nlist *next;
  char *name;
  char *defn;
};

static struct Nlist *g_hashtab[HASHSIZE];

unsigned Hash(char *s) {
  unsigned hashval;

  for (hashval = 0; *s != '\0'; s++) {
    hashval = *s + 31 * hashval;
  }
  return hashval % HASHSIZE;
}

struct Nlist *Lookup(char *s) {
  struct Nlist *np;
  
  for (np = g_hashtab[Hash(s)]; np != NULL; np = np->next) {
    if (strcmp(s, np->name) == 0)
      return np;
  }
  return NULL;
}

struct Nlist *Install(char *name, char *defn) {
  struct Nlist *np;
  unsigned hashval;

  if ((np = Lookup(name)) == NULL) {
    np = (struct Nlist *)malloc(sizeof(*np));
    if (np == NULL || (np->name = StrDup(name)) == NULL)
      return NULL;
    hashval = Hash(name);
    np->next = g_hashtab[hashval];
    g_hashtab[hashval] = np;
  } else {
    free((void *)np->defn);
  }
  if ((np->defn = StrDup(defn)) == NULL)
    return NULL;
  return np;
}
