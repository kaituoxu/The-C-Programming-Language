#include <stdio.h>

int main() {
  double sum, v;
  int day, year, month;
  char monthname[20];

  sum = 0;
  while (scanf("%lf", &v) == 1) {
    sum += v;
  }
  printf("\t%.2f\n", sum);

  scanf("%d %s %d", &day, monthname, &year);
  printf("%d %s %d\n", day, monthname, year);

  scanf("%d/%d/%d", &month, &day, &year);
  printf("%d/%d/%d\n", month, day, year);

  return 0;
}
