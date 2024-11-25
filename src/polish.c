#include "polish.h"

int getPriority(char oper) {
  switch (oper) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '^':
      return 3;
    case '%':
      return 4;
    case 'S':
    case 's':
    case 'C':
    case 'c':
    case 'T':
    case 't':
    case 'L':
    case 'l':
    case 'q':
      return 5;
    default:
      return 0;
  }
}
int correct_input(char* infix) {
  int error = 0;
  int flag_bracket = 0;
  int infixLength = strlen(infix);
  for (int i = 0; i < infixLength; i++) {
    if (infix[i] == '(') flag_bracket++;
    if (infix[i] == ')') flag_bracket--;
    if (infix[i] == '.' && !isdigit(infix[i - 1]) && !isdigit(infix[i + 1]))
      error = 1;
    if (strchr("+-/*", infix[i]) != NULL &&
        strchr("+-/*", infix[i + 1]) != NULL)
      error = 1;
  }
  if (flag_bracket != 0) error = 1;
  return error;
}

char* infixToPostfix(char* infix) {
  char* postfix = malloc(sizeof(char) * strlen(infix) * 2);
  Stack* stack;
  initialize(&stack);
  int postfixIndex = 0;
  int infixLength = strlen(infix);
  int unaryFlag = 1;
  for (int i = 0; i < infixLength; i++) {
    if (isdigit(infix[i]) || infix[i] == 'x') {
      while (strchr("+-", infix[i]) == NULL &&
             (isdigit(infix[i]) || infix[i] == '.' || infix[i] == 'x')) {
        postfix[postfixIndex++] = infix[i++];
      }
      postfix[postfixIndex++] = ' ';
      i--;
      unaryFlag = 0;
    } else if (infix[i] == '(') {
      push(&stack, infix[i]);
      unaryFlag = 1;
    } else if (infix[i] == ')') {
      while (!isEmpty(stack) && stack->operation != '(') {
        postfix[postfixIndex++] = pop(&stack);
      }
      if (!isEmpty(stack) && stack->operation == '(') {
        pop(&stack);
      } else {
        printf("Некорректное выражение с использованием скобок.\n");
        exit(1);
      }
      unaryFlag = 0;
    } else if (infix[i] == '-' && unaryFlag) {
      postfix[postfixIndex++] = '0';
      postfix[postfixIndex++] = ' ';
      push(&stack, '-');
      unaryFlag = 0;
    } else if (strchr("+-*/^%", infix[i]) != NULL) {
      while (!isEmpty(stack) &&
             getPriority(stack->operation) >= getPriority(infix[i])) {
        postfix[postfixIndex++] = pop(&stack);
      }
      push(&stack, infix[i]);
      postfix[postfixIndex++] = ' ';
      unaryFlag = 0;
    } else if (strchr("sctal", infix[i]) != NULL) {
      char ch = infix[i];
      switch (ch) {
        case 's':
          if (infix[i + 1] == 'i' && infix[i + 2] == 'n') {
            ch = 's';
            i += 2;
          } else if (infix[i + 1] == 'q' && infix[i + 2] == 'r' &&
                     infix[i + 3] == 't') {
            ch = 'q';
            i += 3;
          }
          break;
        case 'c':
          if (infix[i + 1] == 'o' && infix[i + 2] == 's') {
            ch = 'c';
            i += 2;
          }
          break;
        case 't':
          if (infix[i + 1] == 'a' && infix[i + 2] == 'n') {
            ch = 't';
            i += 2;
          }
          break;
        case 'a':
          if (infix[i + 1] == 's' && infix[i + 2] == 'i' &&
              infix[i + 3] == 'n') {
            ch = 'S';
            i += 3;
          } else if (infix[i + 1] == 'c' && infix[i + 2] == 'o' &&
                     infix[i + 3] == 's') {
            ch = 'C';
            i += 3;
          } else if (infix[i + 1] == 't' && infix[i + 2] == 'a' &&
                     infix[i + 3] == 'n') {
            ch = 'T';
            i += 3;
          }
          break;
        case 'l':
          if (infix[i + 1] == 'n') {
            ch = 'L';
            i++;
          } else if (infix[i + 1] == 'o' && infix[i + 2] == 'g') {
            ch = 'l';
            i += 2;
          }
          break;
      }
      while (!isEmpty(stack) &&
             getPriority(stack->operation) >= getPriority(ch)) {
        postfix[postfixIndex++] = pop(&stack);
      }
      push(&stack, ch);
      unaryFlag = 0;
    } else if (infix[i] == ' ') {
      continue;
    } else {
      printf("Некорректный символ в инфиксном выражении\n");
      exit(1);
    }
  }

  while (!isEmpty(stack)) {
    postfix[postfixIndex++] = pop(&stack);
  }

  postfix[postfixIndex] = '\0';
  return postfix;
}
