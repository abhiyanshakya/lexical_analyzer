//
// Created by Abhiyan Shakya (shak0102) on 5/18/2026.
//

/*
 *I acknowledge the use of
 *[Anthropic Claude] to assist in the
 *[Understanding the assignment specification requirements].
 *I take full responsibility for the integrity, accuracy, and originality of the final submitted code and written content.
 *The link to full conversation with AI (Anthropic Claude):
 */

// Standard library headers for I/O and memory allocation
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * new_code
 */
typedef enum {
  STATE_START,
  STATE_IN_WORD, //read letters/ _
  STATE_IN_NUMBER, //read digits
  STATE_ERROR,
  STATE_ACCEPT,
} State;

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

/**
 *
 * @param input
 * @param append
 *
 * new_code
 */
void lexer(FILE *input, FILE *append) {
  State state = STATE_START;
  char buffer[256];
  int i = 0;
  char current = fgetc(input);

  while (current != EOF) {
    switch (state) {
      case STATE_START:
        if (isalpha(current) || current == '_') {
          buffer[i++] = current;
          state = STATE_IN_WORD;
          current = fgetc(input);
        } else if (isdigit(current)) {
          buffer[i++] = current;
          state = STATE_IN_NUMBER;
          current = fgetc(input);
        } else if (isspace(current)) {
          current = fgetc(input);
        } else if (current == ';') {
          TokenSeparator *token = malloc(sizeof(TokenSeparator));
          token->type = SEMICOLON;
          fprintf(stdout, "\n<DELIMITER, ;>");
          fprintf(append, "\n<DELIMITER, ;>");
          free(token);
          current = fgetc(input);
        } else if (current == ',') {
          TokenSeparator *token = malloc(sizeof(TokenSeparator));
          token->type = COMMA;
          fprintf(stdout, "\n<DELIMITER, ,>");
          fprintf(append, "\n<DELIMITER, ,>");
          free(token);
          current = fgetc(input);
        } else if (current == '(') {
          TokenSeparator *token = malloc(sizeof(TokenSeparator));
          token->type = OPEN_PARENTHESIS;
          fprintf(stdout, "\n<DELIMITER, (>");
          fprintf(append, "\n<DELIMITER, (>");
          free(token);
          current = fgetc(input);
        } else if (current == ')') {
          TokenSeparator *token = malloc(sizeof(TokenSeparator));
          token->type = CLOSE_PARENTHESIS;
          fprintf(stdout, "\n<DELIMITER, )>");
          fprintf(append, "\n<DELIMITER, )>");
          free(token);
          current = fgetc(input);
        } else if (current == '{') {
          TokenSeparator *token = malloc(sizeof(TokenSeparator));
          token->type = OPEN_CURLYBRACKET;
          fprintf(stdout, "\n<DELIMITER, {>");
          fprintf(append, "\n<DELIMITER, {>");
          free(token);
          current = fgetc(input);
        } else if (current == '}') {
          TokenSeparator *token = malloc(sizeof(TokenSeparator));
          token->type = CLOSE_CURLYBRACKET;
          fprintf(stdout, "\n<DELIMITER, }>");
          fprintf(append, "\n<DELIMITER, }>");
          free(token);
          current = fgetc(input);
        } else if (current == '[') {
          TokenSeparator *token = malloc(sizeof(TokenSeparator));
          token->type = OPEN_SQUAREBRACKET;
          fprintf(stdout, "\n<DELIMITER, [>");
          fprintf(append, "\n<DELIMITER, [>");
          free(token);
          current = fgetc(input);
        } else if (current == ']') {
          TokenSeparator *token = malloc(sizeof(TokenSeparator));
          token->type = CLOSE_SQUAREBRACKET;
          fprintf(stdout, "\n<DELIMITER, ]>");
          fprintf(append, "\n<DELIMITER, ]>");
          free(token);
          current = fgetc(input);
        } else {
          state = STATE_ERROR;
        }
        break;

      case STATE_IN_WORD:
        if (isalpha(current) || isdigit(current) || current == '_') {
          buffer[i++] = current;
          current = fgetc(input);
        } else {
          buffer[i] = '\0';
          i = 0;
          if (strcmp(buffer, "int") == 0) {
            TokenKeyword *token = malloc(sizeof(TokenKeyword));
            token->type = KW_INT;
            fprintf(stdout, "\n<KEYWORD, int>");
            fprintf(append, "\n<KEYWORD, int>");
            free(token);
          } else if (strcmp(buffer, "char") == 0) {
            TokenKeyword *token = malloc(sizeof(TokenKeyword));
            token->type = KW_CHAR;
            fprintf(stdout, "\n<KEYWORD, char>");
            fprintf(append, "\n<KEYWORD, char>");
            free(token);
          } else if (strcmp(buffer, "if") == 0) {
            TokenKeyword *token = malloc(sizeof(TokenKeyword));
            token->type = KW_IF;
            fprintf(stdout, "\n<KEYWORD, if>");
            fprintf(append, "\n<KEYWORD, if>");
            free(token);
          } else if (strcmp(buffer, "else") == 0) {
            TokenKeyword *token = malloc(sizeof(TokenKeyword));
            token->type = KW_ELSE;
            fprintf(stdout, "\n<KEYWORD, else>");
            fprintf(append, "\n<KEYWORD, else>");
            free(token);
          } else if (strcmp(buffer, "while") == 0) {
            TokenKeyword *token = malloc(sizeof(TokenKeyword));
            token->type = KW_WHILE;
            fprintf(stdout, "\n<KEYWORD, while>");
            fprintf(append, "\n<KEYWORD, while>");
            free(token);
          } else if (strcmp(buffer, "for") == 0) {
            TokenKeyword *token = malloc(sizeof(TokenKeyword));
            token->type = KW_FOR;
            fprintf(stdout, "\n<KEYWORD, for>");
            fprintf(append, "\n<KEYWORD, for>");
            free(token);
          } else if (strcmp(buffer, "do") == 0) {
            TokenKeyword *token = malloc(sizeof(TokenKeyword));
            token->type = KW_DO;
            fprintf(stdout, "\n<KEYWORD, do>");
            fprintf(append, "\n<KEYWORD, do>");
            free(token);
          } else if (strcmp(buffer, "return") == 0) {
            TokenKeyword *token = malloc(sizeof(TokenKeyword));
            token->type = KW_RETURN;
            fprintf(stdout, "\n<KEYWORD, return>");
            fprintf(append, "\n<KEYWORD, return>");
            free(token);
          } else {
            TokenIdentifier *token = malloc(sizeof(TokenIdentifier));
            token->type = IDENTIFIER;
            // pointer arithmetic to copy buffer into token name
            char *src = buffer;
            char *dst = token->name;
            while (*src != '\0') {
              *dst++ = *src++;
            }
            *dst = '\0';
            fprintf(stdout, "\n<IDENTIFIER, %s>", token->name);
            fprintf(append, "\n<IDENTIFIER, %s>", token->name);
            free(token);
          }
          state = STATE_START;
        }
        break;

      case STATE_IN_NUMBER:
        if (isdigit(current)) {
          buffer[i++] = current;
          current = fgetc(input);
        } else {
          buffer[i] = '\0';
          i = 0;
          TokenLiteral *token = malloc(sizeof(TokenLiteral));
          token->type = LIT_INT;
          token->value = atoi(buffer);
          fprintf(stdout, "\n<INTEGER, %d>", token->value);
          fprintf(append, "\n<INTEGER, %d>", token->value);
          free(token);
          state = STATE_START;
        }
        break;

      case STATE_ERROR:
        fprintf(stdout, "\n<ERROR, unrecognised character: '%c'>", current);
        fprintf(append, "\n<ERROR, unrecognised character: '%c'>", current);
        while (current != EOF && !isspace(current) &&
               current != ';' && current != ',' &&
               current != '(' && current != ')' &&
               current != '{' && current != '}' &&
               current != '[' && current != ']') {
          current = fgetc(input);
        }
        state = STATE_START;
        break;
    }
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