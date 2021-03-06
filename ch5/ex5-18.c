#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { kName, kParens, kBrackets };
enum { kNo, kYes };

void Dcl(void);
void DirDcl(void);
int GetToken(void);
void ErrMsg(char *);

int g_tokentype;
char g_token[MAXTOKEN];
char g_name[MAXTOKEN];
char g_datatype[MAXTOKEN];
char g_out[1000];
int g_prevtoken = kNo;


int main(int argc, char *argv[]) {
  while (GetToken() != EOF) { // the first token of this line is data type
    strcpy(g_datatype, g_token);
    g_out[0] = '\0';
    Dcl(); // analysis reminder part of this line
    if (g_tokentype != '\n')
      printf("syntax error\n");
    printf("%s: %s %s\n", g_name, g_out, g_datatype);
  }
  return 0;
}


void Dcl(void) {
  int ns; // number of *(star)

  for (ns = 0; GetToken() == '*'; )
    ns++;
  DirDcl();
  while (ns-- > 0)
    strcat(g_out, " pointer to");
}


void DirDcl(void) {
  int type;

  if (g_tokentype == '(') {
    Dcl();
    if (g_tokentype != ')')
      ErrMsg("error: missing )\n");
  } else if (g_tokentype == kName) {
    strcpy(g_name, g_token);
  } else {
    ErrMsg("error: expected name or (dcl)\n");
  }
  while ((type = GetToken()) == kParens || type == kBrackets) {
    if (type == kParens) {
      strcat(g_out, " function returning");
    } else {
      strcat(g_out, " array");
      strcat(g_out, g_token);
      strcat(g_out, " of");
    }
  }
}


void ErrMsg(char *msg) {
  printf("%s", msg);
  g_prevtoken = kYes;
}


// GetToken 
int GetToken(void) {
  int c;
  char *p = g_token;
  int Getch(void);
  void Ungetch(int c);

  if (g_prevtoken == kYes) {
    g_prevtoken = kNo;
    return g_tokentype;
  }
  // skip over tab and blank
  while ((c = Getch()) == ' ' || c == '\t') {
    ;
  }
  // main part
  if (c == '(') {
    if ((c = Getch()) == ')') {
      strcpy(g_token, "()");
      return g_tokentype  = kParens;
    } else {
      Ungetch(c);
      return g_tokentype = '(';
    }
  } else if (c == '[') {
    for (*p++ = c; (*p++ = Getch()) != ']'; )
      ;
    *p = '\0';
    return g_tokentype = kBrackets;
  } else if (isalpha(c)) {
    for (*p++ = c; isalnum(c = Getch()); )
      *p++ = c;
    *p = '\0';
    Ungetch(c);
    return g_tokentype = kName;
  } else {
    return g_tokentype = c;
  }
}

// getch part
#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp = 0;

int Getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void Ungetch(int c) {
	if (bufp < BUFSIZE) {
		buf[bufp++] = c;
	} else {
		printf("ungetch: too many characters\n");
	}
}
