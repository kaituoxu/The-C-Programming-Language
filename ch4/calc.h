#ifndef KandR_CH4_CALC_H_
#define KandR_CH4_CALC_H_

// getch.c
#define NUMBER '0'
int Getch(void);
void Ungetch(int);
void Ungets(char s[]);
int Getch_1(void);
void Ungetch_1(int c);

// getop.c
int Getop(char s[]);

// stack.c
void Push(double f);
double Pop(void);
double GetTop(void);
void SwapTop(void);
void Clear(void);

#endif // KandR_CH4_CALC_H_
