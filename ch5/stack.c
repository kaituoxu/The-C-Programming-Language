#include "calc.h"
#include <stdio.h>

#define MAXVAL 100

static int sp = 0;
static double val[MAXVAL];

void Push(double f) {
	if (sp < MAXVAL) {
		val[sp++] = f;
	} else {
		printf("error: stack full, can't push %g\n", f);
	}
}

double Pop(void) {
	if (sp > 0) {
		return val[--sp];
	} else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* exercise 4-4 */
double GetTop(void) {
	return val[sp-1];
}

void SwapTop(void) {
	double tmp;
	if (sp > 1) {
		tmp = val[sp-1];
		val[sp-1] = val[sp-2];
		val[sp-2] = tmp;
	} else {
		printf("error: too few elements in stack\n");
	}
}

void Clear(void) {
	sp = 0;
}
