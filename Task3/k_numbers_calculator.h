/**
 * @file k_numbers_calculator.h
 * @brief Заголовочный файл для вычисления K-ичных чисел без двух подряд идущих нулей
 */
#ifndef K_NUMBERS_CALCULATOR_H
#define K_NUMBERS_CALCULATOR_H

 /**
  * @brief Проверяет корректность входных данных
  * @param base Основание системы счисления
  * @param digits_count Количество разрядов
  * @return true если данные корректны, false в противном случае
  */

// FIXME: добавлена функция
bool ValidateInput(int base, int digits_count);

/**
 * @brief Вычисляет количество чисел без двух подряд идущих нулей
 * @param base Основание системы счисления
 * @param digits_count Количество разрядов
 * @return Количество допустимых чисел
 */

 // FIXME: добавлена функция
double CalculateValidNumbersCount(int base, int digits_count);

#endif // K_NUMBERS_CALCULATOR_H