//
// Created by abhiy on 5/18/2026.
//

// Standard library headers for I/O and memory allocation
#include <stdio.h>
#include <stdlib.h>

// Enum for separator token types (Semicolon, Open Parentheses and Closed Parentheses)
typedef enum {
  SEMI,
  OPEN_PAREN,
  CLOSE_PAREN,
} TypeSeparator;

// Enum for keyword token types (EXIT)
typedef enum {
  EXIT,
} TypeKeyword;

// Enum for literal token types (INT)
typedef enum {
  INT,
} TypeLiteral;

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

int main() {
}