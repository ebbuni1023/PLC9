#include <stdio.h>
#include <ctype.h>
#include <string.h>
/* Global declarations */
/* Variables */
int charClass;
char lexeme[100];
char specifier[5][10] = {"String", "int", "char", "float", "void"}; // using speicifiers in Java/C
int specIndex;
char nextChar;
int lexLen;
int token;
int nextToken;
FILE *in_fp;

/* Function declarations */
int lookup(char ch);
void addChar(void);
void getChar(void);
void getNonBlank(void);
int lex(void);
void expr(void);
void term(void);
void factor(void);

/* Character classes */
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99

/* Token codes */
#define EXCLAMATION 9
#define INT_LIT 10
#define STR_LIT 11
#define CHAR_LIT 12
#define FLOAT_LIT 13

#define STR_DEC 14
#define INT_DEC 15
#define CHAR_DEC 16
#define FLOAT_DEC 17
#define VOID_DEC 18

#define PERL_VAR 20 // $
#define PERL_ARR 21 // @ 
#define PERL_HASH 22 // %

#define ADD_OP 23 // +
#define ASSIGN_OP 24 // = 
#define SUB_OP 25 // - 
#define DIV_OP 26 // / 
#define MULT_OP 27 // *
#define MOD_OP 28 // %
#define LOGIC_AND 29 // && 
#define LOGIC_OR 30 // ||
#define LOGIC_NOT 31 // !
#define LEFT_BRACKET 32 // [
#define RIGHT_BRACKET 33 // ]
#define LEFT_PAREN 34 // (
#define RIGHT_PAREN 35 // )
#define LEFT_CURLY 36 // { 
#define RIGHT_CURLY 37 // }
#define PERL_SPECIAL 38 // $


int main(void) {
  if ((in_fp = fopen("front.in", "r")) == NULL)
    printf("ERROR - cannot open front.in \n");
  else {
    getChar();
    do {
      lex();
    } while (nextToken != EOF);
  }
  return 0;
}

int lookup(char ch) {
  switch(ch) {
    case '+':
      addChar();
      nextToken = ADD_OP;
      break;
    case '=':
      addChar();
      nextToken = ASSIGN_OP;
      break;
    case '-':
      addChar();
      nextToken = SUB_OP;
      break;
    case '/':
      addChar();
      nextToken = DIV_OP;
      break;
    case '*':
      addChar();
      nextToken = MULT_OP;
      break;
    case '%':
      addChar();
      nextToken = MOD_OP;
      getChar();
      if (charClass == LETTER) {
        addChar();
        getChar();
        while (charClass == LETTER || charClass == DIGIT) {
          addChar();
          getChar();
        }
        nextToken = PERL_HASH;
        break;
      } else {
        break;
      }
    case '&':
      addChar();
      getChar();
      if (nextChar == '&') {
        addChar();
        nextToken = LOGIC_AND;
        break;
      } else {
        break;
      }
    case '|':
      addChar();
      getChar();
      if (nextChar == '|') {
        addChar();
        nextToken = LOGIC_OR;
        break;
      } else {
        break;
      }
    case '!':
      addChar();
      nextToken = LOGIC_NOT;
      break;
    case '[':
      addChar();
      nextToken = LEFT_BRACKET;
      break;
    case ']':
      addChar();
      nextToken = RIGHT_BRACKET;
      break;
    case '{':
      addChar();
      nextToken = LEFT_CURLY;
      break;
    case '}':
      addChar();
      nextToken = RIGHT_CURLY;
      break;
    case '(':
      addChar();
      nextToken = LEFT_PAREN;
      break;
    case ')':
      addChar();
      nextToken = RIGHT_PAREN;
      break;
      
    case '$':
      addChar();
      getChar();
      if (charClass == LETTER) {
        addChar();
        getChar();
        while (charClass == LETTER || charClass == DIGIT) {
          addChar();
          getChar();
        }
        nextToken = PERL_VAR;
        break;
      } else {
        addChar();
        break;
      }
    case '@':
      addChar();
      getChar();
      if (charClass == LETTER) {
        addChar();
        getChar();
        while (charClass == LETTER || charClass == DIGIT) {
          addChar();
          getChar();
        }
        nextToken = PERL_ARR;
        break;
      } else {
        addChar();
        break;
      }
    return nextToken;
  }
}

void addChar(void) {
  if (lexLen <= 98) {
    lexeme[lexLen++] = nextChar;
    lexeme[lexLen] = '\0';
  } else
  printf("Error - lexeme is too long \n");
}

void getChar(void) {
  if ((nextChar = getc(in_fp)) != EOF) {
    if (isalpha(nextChar))
      charClass = LETTER;
    else if (isdigit(nextChar))
      charClass = DIGIT;
    else 
      charClass = UNKNOWN;
  } else 
    charClass = EOF;
}

void getNonBlank(void) {
  while (isspace(nextChar))
    getChar();
}

int isSpecifier(char buffer[]) {
  int i, flag = 0;

  for (i = 0; i < 5; ++i) {
    if(strcmp(specifier[i], buffer) == 0) {
      flag = 1;
      specIndex = i;
      break;
    } 
  }
  return flag;
}

int typeDec(void) {
  switch(specIndex) {
    case 0:
      return STR_DEC;
    case 1:
      return INT_DEC;
    case 2:
      return CHAR_DEC;
    case 3:
      return FLOAT_DEC;
    case 4:
      return VOID_DEC;
  }
}

int x;
int lex(void) {
  lexLen = 0;
  getNonBlank();
  int x;
  switch (charClass) {
    /* Identifiers */
    case LETTER:
      addChar();
      getChar();
      while (charClass == LETTER || charClass == DIGIT) {
        addChar();
        getChar();
      }

      int len = sizeof(lexeme) / sizeof(lexeme[0]);

      /* Check to see if string is a declarator */
      if (isSpecifier(lexeme) == 1) {
        nextToken = typeDec();
      } else if (len == 1) {
        nextToken = CHAR_LIT;
      } else {
        nextToken = STR_LIT;
      }

      break;

    case DIGIT:
      addChar();
      getChar();
      int hasDecimal = 0;
      while (charClass == DIGIT || nextChar == '.') {

        if (hasDecimal == 0 && nextChar == '.') {
          hasDecimal = 1;
          addChar();
          getChar();
        } else {
          addChar();
          getChar();
        }
      }
      
      if (hasDecimal == 1) {
        nextToken = FLOAT_LIT;
      } else {
        nextToken = INT_LIT;
      }
      break;

    case UNKNOWN:
      lookup(nextChar);
      getChar();
      break;
    
    case EOF:
      nextToken = EOF;
      lexeme[0] = 'E';
      lexeme[1] = 'O';
      lexeme[2] = 'F';
      lexeme[3] = '\0';
      break;
  } 
  printf("Next token is: %d, Next lexeme is %s\n", nextToken, lexeme);
  return nextToken;
}