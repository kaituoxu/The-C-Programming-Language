#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>

#define LOCALFMT 100

void MinPrintf(char *fmt, ...) {
  va_list ap;
  char local_fmt[LOCALFMT];
  char *p, *sval, cval;
  int i, ival;
  double dval;
  unsigned uval;

  va_start(ap, fmt);
  for (p = fmt; *p; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }
    i = 0;
    local_fmt[i++] = '%';
    while (*(p+1) && !isalpha(*(p+1)))
      local_fmt[i++] = *++p;
    local_fmt[i++] = *(p+1);
    local_fmt[i] = '\0';
    switch(*++p) {
      case 'd':
      case 'i':
        ival = va_arg(ap, int);
        printf(local_fmt, ival);
        break;
      case 'x':
      case 'X':
      case 'u':
      case 'o':
        uval = va_arg(ap, unsigned);
        printf(local_fmt, uval);
        break;
      case 'f':
        dval = va_arg(ap, double);
        printf(local_fmt, dval);
        break;
      case 's':
        sval = va_arg(ap, char *);
        printf(local_fmt, sval);
        break;
      default:
        printf(local_fmt);
        break;
    } // switch
  } // for p
  va_end(ap);
}

int main(int argc, char *argv[]) {
  MinPrintf("int is %d, double is %f, string is %s\n", 123, 456.7, "abcdef");
  return 0;
}
