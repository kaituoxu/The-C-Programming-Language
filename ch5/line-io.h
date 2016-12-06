#ifndef KANDR_CH5_LINE_IO_H_
#define KANDR_CH5_LINE_IO_H_

// Memory
char *Alloc(int n);
void Afree(char *p);

// I/O
int GetLine(char *line, int maxlen);
int ReadLines(char *lineptr[], int maxlines);
void WriteLines(char *lineptr[], int nlines);

#endif // KANDR_CH5_LINE_IO_H_
