/**
 * @file main.cpp
 * @brief ��������� ��� ���������� ������������� ���������
 */
#include "expression_calculator.h"

int main() {
    //FIXME: �������� �������� ����������
    std::string input_expression;
    std::cout << "������� ���������: ";
    std::getline(std::cin, input_expression);

    int result = CalculateExpression(input_expression);
    std::cout << "�����: " << result << std::endl;

    return 0;
}