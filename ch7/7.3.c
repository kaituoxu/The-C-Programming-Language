#include <stdarg.h>
#include <stdio.h>

void MinPrintf(char *fmt, ...) {
  va_list ap;
  char *p, *sval;
  int ival;
  double dval;

  va_start(ap, fmt);
  for (p = fmt; *p; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }
    switch(*++p) {
      case 'd':
        ival = va_arg(ap, int);
        printf("%d", ival);
        break;
      case 'f':
        dval = va_arg(ap, double);
        printf("%f", dval);
        break;
      case 's':
        for (sval = va_arg(ap, char *); *sval; sval++) {
          putchar(*sval);
        }
        break;
      default:
        putchar(*p);
        break;
    } // switch
  } // for p
  va_end(ap);
}

int main(int argc, char *argv[]) {
  MinPrintf("int is %d, double is %f, string is %s\n", 123, 456.7, "abcdef");
  return 0;
}
