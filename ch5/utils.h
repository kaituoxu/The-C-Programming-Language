#ifndef KANDR_CH5_UTILS_H_
#define KANDR_CH5_UTILS_H_

// Memory
char *Alloc(int n);
void Afree(char *p);

// I/O
int GetLine(char *line, int maxlen);
int ReadLines(char *lineptr[], int maxlines);
void WriteLines(char *lineptr[], int nlines);

// Sort
void Swap(char *v[], int i, int j);
void Qsort(char *v[], int left, int right);

#endif // KANDR_CH5_UTILS_H_
