/**
 * @file expression_calculator.h
 * @brief Заголовочный файл для вычисления выражений
 */
#ifndef EXPRESSION_CALCULATOR_H
#define EXPRESSION_CALCULATOR_H

#include <iostream>
#include <string>

 /**
  * @brief Вычисляет значение целочисленного выражения
  * @param expression Строка с выражением
  * @return Результат вычисления
  */

//FIXME: Добавлено название функций
int CalculateExpression(const std::string& expression);

/**
 * @brief Вычисляет значение терма
 * @param term_str Строка с термом
 * @return Результат вычисления терма
 */

 //FIXME: Добавлено название функций
int EvaluateTerm(const std::string& term_str);

/**
 * @brief Вычисляет значение элемента (числа или выражения в скобках)
 * @param element_str Строка с элементом
 * @return Результат вычисления элемента
 */

 //FIXME: Добавлено название функций
int EvaluateElement(const std::string& element_str);

#endif // EXPRESSION_CALCULATOR_H