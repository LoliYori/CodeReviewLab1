/**
 * @file k_numbers_calculator.h
 * @brief ������������ ���� ��� ���������� K-����� ����� ��� ���� ������ ������ �����
 */
#ifndef K_NUMBERS_CALCULATOR_H
#define K_NUMBERS_CALCULATOR_H

 /**
  * @brief ��������� ������������ ������� ������
  * @param base ��������� ������� ���������
  * @param digits_count ���������� ��������
  * @return true ���� ������ ���������, false � ��������� ������
  */

// FIXME: ��������� �������
bool ValidateInput(int base, int digits_count);

/**
 * @brief ��������� ���������� ����� ��� ���� ������ ������ �����
 * @param base ��������� ������� ���������
 * @param digits_count ���������� ��������
 * @return ���������� ���������� �����
 */

 // FIXME: ��������� �������
double CalculateValidNumbersCount(int base, int digits_count);

#endif // K_NUMBERS_CALCULATOR_H