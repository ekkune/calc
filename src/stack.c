#include "stack.h"

void push(Stack** top, char operation) {
  Stack* ptr = malloc(sizeof(Stack));
  ptr->operation = operation;
  ptr->next = *top;
  *top = ptr;
}

char pop(Stack** top) {
  if (*top == NULL) return 0;
  char res = (*top)->operation;
  Stack* ptr = *top;
  *top = ptr->next;
  free(ptr);
  return res;
}

void initialize(Stack** top) { *top = NULL; }

int isEmpty(Stack* top) { return (top == NULL); }

void push_op(Stack_op** top, double operand) {
  Stack_op* ptr = malloc(sizeof(Stack_op));
  ptr->operand = operand;
  ptr->next = *top;
  *top = ptr;
}

double pop_op(Stack_op** top) {
  if (*top == NULL) return 0;
  double res = (*top)->operand;
  Stack_op* ptr = *top;
  *top = ptr->next;
  free(ptr);
  return res;
}

void initialize_op(Stack_op** top) { *top = NULL; }

int isEmpty_op(Stack_op* top) { return (top == NULL); }