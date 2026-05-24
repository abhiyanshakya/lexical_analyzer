//
// Created by Abhiyan Shakya (shak0102) on 5/18/2026.
//

/*
 *I acknowledge the use of
 *[Anthropic Claude] to assist in the
 *[Understanding the assignment specification requirements].
 *I take full responsibility for the integrity, accuracy, and originality of the final submitted code and written content.
 */

// Standard library headers for I/O and memory allocation
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Enum for separator/ delimiter token types (;,,,(,),{,},[,])
typedef enum {
  SEMICOLON,
  COMMA,
  OPEN_PARENTHESIS,
  CLOSE_PARENTHESIS,
  OPEN_curlyBRACKET,
  CLOSE_curlyBRACKET,
  OPEN_squareBRACKET,
  CLOSE_squareBRACKET,
} TypeSeparator;

// Enum for keyword token types (int, char, if, else, while, for, do, return)
typedef enum {
  KW_INT,
  KW_CHAR,
  KW_IF,
  KW_ELSE,
  KW_WHILE,
  KW_FOR,
  KW_DO,
  KW_RETURN,
} TypeKeyword;

// Enum for literal token types (INT)
typedef enum {
  LIT_INT,
} TypeLiteral;

// Enum for identifier token type
typedef enum {
  IDENTIFIER,
} TypeIdentifier;

// Token struct for keywords, holds its type
typedef struct {
  TypeKeyword type;
} TokenKeyword;

// Token struct for separators, holds its type
typedef struct {
  TypeSeparator type;
} TokenSeparator;

// Token struct for literals, hold its type and int value
typedef struct {
  TypeLiteral type;
  int value;
} TokenLiteral;

typedef struct {
  TypeIdentifier type;
  char name[256];
} TokenIdentifier;

void lexer (FILE *file) {
  char current = fgetc (file);
  while (current != EOF) {
    if (current == ';') {
      printf("FOUND SEMICOLON\n");
    } else if (current == ',') {
      printf("FOUND COMMA\n");
    } else if (current == '(') {
      printf("FOUND OPEN PARENTHESIS\n");
    } else if (current == ')') {
      printf("FOUND CLOSED PARENTHESIS\n");
    } else if (current == '{') {
      printf("FOUND OPEN curlyBRACKET\n");
    } else if (current == '}') {
      printf("FOUND CLOSED curlyBRACKET\n");
    } else if (current == '[') {
      printf("FOUND OPEN squareBRACKET\n");
    } else if (current == ']') {
      printf("FOUND CLOSED squareBRACKET\n");
    } else if (isdigit(current)) {
      printf("FOUND DIGIT: %d\n", current - '0');
    } else if (isalpha(current)) {
      printf("FOUND CHARACTER: %c\n", current);
    }
    current = fgetc (file);
  }
}

int main() {
  FILE *file = fopen("test.unn", "r");
  if (file == NULL) {
    printf ("Not able to open the file.");
  }
  lexer(file);
}