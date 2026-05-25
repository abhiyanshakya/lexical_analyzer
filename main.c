//
// Created by Abhiyan Shakya (shak0102) on 5/18/2026.
//

/*
 *I acknowledge the use of
 *[Anthropic Claude] to assist in the
 *[Understanding the assignment specification requirements].
 *I take full responsibility for the integrity, accuracy, and originality of the final submitted code and written content.
 *The link to full conversation with AI (Anthropic Claude): https://claude.ai/share/d11192d8-365a-4044-98ea-f851f8722500
 */

// Standard library headers for I/O and memory allocation
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Enum for Separator/Delimiter token types (;,,,(,),{,},[,])
typedef enum {
  SEMICOLON,
  COMMA,
  OPEN_PARENTHESIS,
  CLOSE_PARENTHESIS,
  OPEN_CURLYBRACKET,
  CLOSE_CURLYBRACKET,
  OPEN_SQUAREBRACKET,
  CLOSE_SQUAREBRACKET,
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

// Enum for literal token types (0,1,2,3,4,5,6,7,8,9)
typedef enum {
  LIT_INT,
} TypeLiteral;

// Enum for identifier token type (Sequences starting with an alphabet letter or underscore followed by letters, digits, or underscores)
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

// Token struct for Identifier, hold its type and
typedef struct {
  TypeIdentifier type;
  char name[256];
} TokenIdentifier;

void lexer(FILE *input, FILE *append) {
  char current = fgetc(input);

  while (current != EOF) {
    if (current == ';') {
      fprintf(stdout, "\nFOUND SEMICOLON");
      fprintf(append, "\nFOUND SEMICOLON");
    } else if (current == ',') {
      fprintf(stdout, "\nFOUND COMMA");
      fprintf(append, "\nFOUND COMMA");
    } else if (current == '(') {
      fprintf(stdout, "\nFOUND OPEN PARENTHESIS");
      fprintf(append, "\nFOUND OPEN PARENTHESIS");
    } else if (current == ')') {
      fprintf(stdout, "\nFOUND CLOSED PARENTHESIS");
      fprintf(append, "\nFOUND CLOSED PARENTHESIS");
    } else if (current == '{') {
      fprintf(stdout, "\nFOUND OPEN CURLYBRACKET");
      fprintf(append, "\nFOUND OPEN CURLYBRACKET");
    } else if (current == '}') {
      fprintf(stdout, "\nFOUND CLOSED CURLYBRACKET");
      fprintf(append, "\nFOUND CLOSED CURLYBRACKET");
    } else if (current == '[') {
      fprintf(stdout, "\nFOUND OPEN SQUAREBRACKET");
      fprintf(append, "\nFOUND OPEN SQUAREBRACKET");
    } else if (current == ']') {
      fprintf(stdout, "\nFOUND CLOSED SQUAREBRACKET");
      fprintf(append, "\nFOUND CLOSED SQUAREBRACKET");
    }
    current = fgetc (input);
  }
}

int main() {
  FILE *input = fopen("test.c", "r");
  if (input == NULL) {
    printf ("Not able to read anything.");
    return 1;
  }
  FILE *output = fopen("output.txt", "w");
  if (output == NULL) {
    printf("Note able to write anything.");
  }
  FILE *append = fopen("output.txt", "a");
  lexer(input, append);
  fclose(input);
  fclose(output);
  fclose(append);
  return 0;
}