/* undcl */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { kName, kParens, kBrackets };

void Dcl(void);
void DirDcl(void);
int GetToken(void);
int NextToken(void);

int  g_tokentype;
char g_token[MAXTOKEN];
char g_name[MAXTOKEN];
char g_datatype[MAXTOKEN];
char g_out[1000];


/* undcl: convert word description to declaration */
int main(int argc, char *argv[]) {
  int type;
  char temp[MAXTOKEN];

  // main loop
  while (GetToken() != EOF) {
    strcpy(g_out, g_token);
    while ((type = GetToken()) != '\n') {
      if (type == kParens || type == kBrackets) {
        strcat(g_out, g_token);
      } else if (type == '*') {
        sprintf(temp, "(*%s)", g_out);
        strcpy(g_out, temp);
      } else if (type == kName) {
        sprintf(temp, "%s %s", g_token, g_out);
        strcpy(g_out, temp);
      } else {
        printf("invalid input at %s\n", g_token);
      }
    }
    printf("%s\n", g_out);
  } // main loop
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
      printf("error: missing )\n");
  } else if (g_tokentype == kName) {
    strcpy(g_name, g_token);
  } else {
    printf("error: expected name or (dcl)\n");
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


// GetToken 
int GetToken(void) {
  int c;
  char *p = g_token;
  int Getch(void);
  void Ungetch(int c);

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
