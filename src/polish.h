#ifndef SRC_POLISH_H_
#define SRC_POLISH_H_

#include <ctype.h>
#include <math.h>
#include <string.h>

#include "stack.h"
/**
 * @brief функция, выставляющая приотритет операциям
 * @param oper переменная, которая хранит символ переменной
 * @return вощвращает числовое значение - приоритет операции
 */
int getPriority(char oper);

/**
 * @brief функция, переводящая из инфиксной записи в постфиксную
 * @param infix переменная, которая хранит инфиксную запись
 * @return вощвращает постфиксную запись
 */
char* infixToPostfix(char* infix);

/**
 * @brief функция, проверяет инфиксную запись на корректный ввод
 * @param infix переменная, которая хранит инфиксную запись
 * @return  возвращает "1" в стлучае ошибки
 */
int correct_input(char* infix);
#endif  // SRC_POLISH_H_
