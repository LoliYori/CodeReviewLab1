/**
 * @file main.cpp
 * @brief Программа для вычисления целочисленных выражений
 */
#include "expression_calculator.h"

int main() {
    //FIXME: Изменено название переменной
    std::string input_expression;
    std::cout << "Введите выражение: ";
    std::getline(std::cin, input_expression);

    int result = CalculateExpression(input_expression);
    std::cout << "Ответ: " << result << std::endl;

    return 0;
}