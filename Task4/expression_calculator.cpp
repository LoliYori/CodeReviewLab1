/**
 * @file expression_calculator.cpp
 * @brief ���������� ������� ��� ���������� ���������
 */
#include "expression_calculator.h"



//FIXME: �������� � �������
int EvaluateElement(const std::string& element_str) {
    if (element_str.front() == '(' && element_str.back() == ')') {
        return CalculateExpression(element_str.substr(1, element_str.size() - 2));
    }
    return std::stoi(element_str);
}

//FIXME: �������� � �������
int EvaluateTerm(const std::string& term_str) {
    //FIXME: �������� �������� ���������� 
    int current_position = term_str.size() - 1;
    int parenthesis_level = 0;
    int operator_position = -1;

    //FIXME: �������� �� �����������
    while (current_position >= 0) {
        if (term_str[current_position] == ')') {
            
            ++parenthesis_level;
        }
        if (term_str[current_position] == '(') {
            --parenthesis_level;
        }
        if (parenthesis_level == 0 && term_str[current_position] == '*') {
            operator_position = current_position;
            break;
        }
        --current_position;
    }

    if (operator_position == -1) {
        return EvaluateElement(term_str);
    }
    return EvaluateTerm(term_str.substr(0, operator_position)) *
        EvaluateElement(term_str.substr(operator_position + 1));
}

//FIXME: �������� � �������
int CalculateExpression(const std::string& expression) {
    //FIXME: �������� �������� ���������� 
    int current_position = expression.size() - 1;
    int parenthesis_level = 0;
    int operator_position = -1;

    //FIXME: �������� �� �����������
    while (current_position >= 0) {
        if (expression[current_position] == ')') {
            ++parenthesis_level;
        }
        if (expression[current_position] == '(') {
            --parenthesis_level;
        }
        if (parenthesis_level == 0 &&
            (expression[current_position] == '-' || expression[current_position] == '+')) {
            operator_position = current_position;
            break;
        }
        --current_position;
    }
     
    if (operator_position == -1) {
        return EvaluateTerm(expression);
    }

    //FIXME: �������� �������� ����������
    char operation = expression[operator_position];
    if (operation == '+') {
        return CalculateExpression(expression.substr(0, operator_position)) +
            EvaluateTerm(expression.substr(operator_position + 1));
    }
    if (operation == '-') {
        return CalculateExpression(expression.substr(0, operator_position)) -
            EvaluateTerm(expression.substr(operator_position + 1));
    }
    return 0;
}