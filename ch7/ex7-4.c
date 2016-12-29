#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>

#define LOCALFMT 100

void MinScanf(char *fmt, ...) {
  va_list ap;
  char *p, *cpnt, *spnt;
  char local_fmt[LOCALFMT];
  int i, *ipnt;
  double *dpnt;

  i = 0;
  va_start(ap, fmt);
  for (p = fmt; *p; p++) {
    if (*p != '%') {
      local_fmt[i++] = *p;
      continue;
    }
    local_fmt[i++] = '%';
    while (*(p+1) && !isalpha(*(p+1)))
      local_fmt[i++] = *++p;
    local_fmt[i++] = *(p+1);
    local_fmt[i] = '\0';
    switch(*++p) {
      case 'd':
      case 'i':
      case 'o':
      case 'u':
      case 'x':
        ipnt = va_arg(ap, int *);
        scanf(local_fmt, ipnt);
        break;
      case 'f':
        dpnt = va_arg(ap, double *);
        scanf(local_fmt, dpnt);
        break;
      case 'c':
        cpnt = va_arg(ap, char *);
        scanf(local_fmt, cpnt);
        break;
      case 's':
        spnt = va_arg(ap, char *);
        scanf(local_fmt, spnt);
        break;
      default:
        scanf(local_fmt);
        break;
    }
    i = 0;
  }
  va_end(ap);
}

int main(int argc, char *argv[]) {
  int n;
  char c, s[100];

  MinScanf("%d %c %s", &n, &c, s);
  printf("[DEBUG] n=%d c=%c s=%s\n", n, c, s);

  return 0;
}
