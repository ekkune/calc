#ifndef SRC_CALC_H_
#define SRC_CALC_H_

#include "polish.h"

/**
 * @brief функция, прозводящая подсчет между двумя операндами
 *
 * @param operand2 переменная, которая хранит значение второго операнда
 * @param operand1 переменная, которая хранит значение первого операнда
 * @param oper переменная, которая хранит операцию
 * @param result переменная, которая хранит результат предыдущей операции
 * @return double  возвращает измененное значение результата
 */
double calc(double operand2, double operand1, char oper, double* result);

/**
 * @brief функция, вычисляющая значения выражения
 *
 * @param postfix переменная, которая хранит строку в постфиксной записи
 * @param x хранит, значение x, если он введен, в случае отстутствия стоит 0
 * @return double возвращает результат вычисления всего выражения
 */
double calculatePostfix(char* postfix, double x);

/**
 * @brief функция, собирающая всем промежуточные функции
 *
 * @param infix переменная, хранящая входное инфиксное значение
 * @param answer переменная, в которую будет записан результат
 * @param x хранит, значение x, если он введен, в случае отстутствия стоит
 * @return int возвращает "1" в случае ошибки
 */
int getAnswer(char* infix, double* answer, double x);

#endif  // SRC_CALC_H_
