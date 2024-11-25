#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include <stdio.h>
#include <stdlib.h>

/*!
 * @brief Структура, хранящая все данные из инфиксной записи нотации
 * @param operation Хранит используемые операции
 *
 * s - sin
 * c - cos
 * t - tan
 * S - asin
 * C - acos
 * T - atan
 * Q - sqrt
 * L - ln
 * l - log
 *
 */

typedef struct tag_stack {
  char operation;
  struct tag_stack* next;
} Stack;

/*!
 * @brief Структура для вычисления оперций
 * @param operand Хранит используемые операнды
 *
 */

typedef struct stack_op {
  double operand;
  struct stack_op* next;
} Stack_op;

/**
 * @brief Функция, добавляющая ноду в стек
 */
void push(Stack** top, char operation);

/**
 * @brief Функция, удаляющая ноду из стека
 */
char pop(Stack** top);

/**
 * @brief Функция, инициализирующая стек
 */
void initialize(Stack** top);

/**
 * @brief Функция, проверяющая стек на пустоту
 */
int isEmpty(Stack* top);

/**
 * @brief Функция, добавляющая ноду в стек
 */
void push_op(Stack_op** top, double operand);

/**
 * @brief Функция, удаляющая ноду из стека
 */
double pop_op(Stack_op** top);

/**
 * @brief Функция, инициализирующая стек
 */
void initialize_op(Stack_op** top);

/**
 * @brief Функция, проверяющая стек на пустоту
 */
int isEmpty_op(Stack_op* top);

#endif  // SRC_STACK_H_