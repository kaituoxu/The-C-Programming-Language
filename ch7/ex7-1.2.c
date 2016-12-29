#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int c;

  printf("[DEBUG] argv[0] = %s\n", argv[0]);

  if (strcmp(argv[0]+strlen(argv[0])-strlen("lower"), "lower") == 0) {
    while ((c = getchar()) != EOF) {
      putchar(tolower(c));
    }
  } else if (strcmp(argv[0]+strlen(argv[0])-strlen("upper"), "upper") == 0) {
    while ((c = getchar()) != EOF) {
      putchar(toupper(c));
    }
  } else {
    while ((c = getchar()) != EOF) {
      putchar(c);
    }
  }
}
