/**
 * @file expression_calculator.h
 * @brief ������������ ���� ��� ���������� ���������
 */
#ifndef EXPRESSION_CALCULATOR_H
#define EXPRESSION_CALCULATOR_H

#include <iostream>
#include <string>

 /**
  * @brief ��������� �������� �������������� ���������
  * @param expression ������ � ����������
  * @return ��������� ����������
  */

//FIXME: ��������� �������� �������
int CalculateExpression(const std::string& expression);

/**
 * @brief ��������� �������� �����
 * @param term_str ������ � ������
 * @return ��������� ���������� �����
 */

 //FIXME: ��������� �������� �������
int EvaluateTerm(const std::string& term_str);

/**
 * @brief ��������� �������� �������� (����� ��� ��������� � �������)
 * @param element_str ������ � ���������
 * @return ��������� ���������� ��������
 */

 //FIXME: ��������� �������� �������
int EvaluateElement(const std::string& element_str);

#endif // EXPRESSION_CALCULATOR_H