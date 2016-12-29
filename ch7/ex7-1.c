#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  int c;

  while ((c = *argv[0]++) != '\0') {
    if (isupper(c)) {
      putchar(tolower(c));
    } else if (islower(c)) {
      putchar(toupper(c));
    } else {
      putchar(c);
    }
  }
  putchar('\n');

  return 0;
}
