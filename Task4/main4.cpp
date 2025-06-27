/**
 * @file main.cpp
 * @brief Ïðîãðàììà äëÿ âû÷èñëåíèÿ öåëî÷èñëåííûõ âûðàæåíèé
 */
#include "expression_calculator.h"

// FIXME: функции вынесены в отдельный файл, добавлен джавадок
int main() {
    //FIXME: Изменено название переменной
    std::string input_expression;
    std::cout << "Ââåäèòå âûðàæåíèå: ";
    std::getline(std::cin, input_expression);

    int result = CalculateExpression(input_expression);
    std::cout << "Îòâåò: " << result << std::endl;

    return 0;
}
