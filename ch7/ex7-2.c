#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100
#define OCTLEN 6

int main(int argc, char *argv[]) {
  int c, pos;
  int Inc(int pos, int n);

  pos = 0;
  while ((c = getchar()) != EOF) {
    if (iscntrl(c) || c == ' ') {
      pos = Inc(pos, OCTLEN);
      printf(" \\%03o ", c);
      if (c == '\n') {
        pos = 0;
        putchar('\n');
      }
    } else {
      pos = Inc(pos, 1);
      putchar(c);
    }
  }
  return 0;
}

int Inc(int pos, int n) {
  if (pos + n < MAXLINE)
    return pos+n;
  else {
    putchar('\n');
    return n;
  }
}
