#include "calc.h"

double calc(double operand2, double operand1, char oper, double* result) {
  switch (oper) {
    case '+':
      *result = operand1 + operand2;
      break;
    case '-':
      *result = operand1 - operand2;
      break;
    case '*':
      *result = operand1 * operand2;
      break;
    case '/':
      *result = operand1 / operand2;
      break;
    case '^':
      *result = pow(operand1, operand2);
      break;
    case '%':
      *result = fmod(operand1, operand2);
      break;
    case 'S':
      *result = asin(operand2);
      break;
    case 's':
      *result = sin(operand2);
      break;
    case 'C':
      *result = acos(operand2);
      break;
    case 'c':
      *result = cos(operand2);
      break;
    case 'T':
      *result = atan(operand2);
      break;
    case 't':
      *result = tan(operand2);
      break;
    case 'L':
      *result = log(operand2);
      break;
    case 'l':
      *result = log10(operand2);
      break;
    case 'q':
      *result = sqrt(operand2);
      break;
    default:
      printf("Invalid operator: %c\n", oper);
      exit(EXIT_FAILURE);
  }
  return *result;
}

double calculatePostfix(char* postfix, double x) {
  Stack_op* stack_op;
  initialize_op(&stack_op);
  int length = strlen(postfix);
  char number[20];
  double operand2 = 0;
  double operand1 = 0;
  for (int i = 0; i < length; i++) {
    if (isdigit(postfix[i]) || postfix[i] == '.') {
      int j = 0;
      while (isdigit(postfix[i]) || postfix[i] == '.') {
        number[j] = postfix[i];
        i++;
        j++;
      }
      i--;
      number[j] = '\0';
      double value = atof(number);
      push_op(&stack_op, value);
    } else if (postfix[i] == ' ') {
      continue;
    } else if (postfix[i] == 'x') {
      push_op(&stack_op, x);
    } else {
      operand2 = pop_op(&stack_op);
      if (strchr("CcSsTtLlq", postfix[i]) == NULL) operand1 = pop_op(&stack_op);
      double result = 0.;
      result = calc(operand2, operand1, postfix[i], &result);
      push_op(&stack_op, result);
    }
  }
  return pop_op(&stack_op);
}

int getAnswer(char* infix, double* answer, double x) {
  int err = correct_input(infix);
  if (!err) {
    char* postfix = infixToPostfix(infix);
    *answer = calculatePostfix(postfix, x);
    free(postfix);
  }

  return err;
}
