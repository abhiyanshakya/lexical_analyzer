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
#include <stdio.h>
#include <stdlib.h>

// Enum for separator/ delimiter token types (;,,,(,),{,},[,])
typedef enum {
  SEMICOLON,
  COMMA,
  OPEN_PAREN,
  CLOSE_PAREN,
  OPEN_BRACE,
  CLOSE_BRACE,
  OPEN_BRACKET,
  CLOSE_BRACKET,
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

void lexer (FILE *input, FILE *output) {
  char current = fgetc(input);

  while (current != EOF) {
    printf("%c", current);
    fprintf(output, "%c", current);
  }
}

int main() {
  FILE *input = fopen("test.unn", "r");
  if (input == NULL) {
    printf("Failed to Open test.unn\n");
    return 1;
  }
  FILE *output = fopen("output.txt", "w");
  if (output == NULL) {
    printf("Failed to open output.txt\n");
    return 1;
  }

  lexer(input, output);
  fclose(input);
  fclose(output);
  return 0;
}