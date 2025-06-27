/**
 * @file k_numbers_calculator.cpp
 * @brief Реализация функций для вычисления K-ичных чисел без двух подряд идущих нулей
 */
#include "k_numbers_calculator.h"

//FIXME: Добавлены функции
bool ValidateInput(int base, int digits_count) {
    return (base >= 2 && base <= 10 && 
            digits_count > 1 && digits_count < 20 && 
            (base + digits_count) < 26);
}

//FIXME: Добавлены функции
double CalculateValidNumbersCount(int base, int digits_count) {
  //FIXME: Изменено название перменных
    double numbers_without_zero = base - 1;  
    double numbers_with_single_zero = 1;
    double numbers_with_double_zero = 0;

    // FIXME: Изменено на префиксную
    for (int current_digit = 2; current_digit <= digits_count; ++current_digit) {
        double prev_without_zero = numbers_without_zero;
        double prev_with_single_zero = numbers_with_single_zero;
        double prev_with_double_zero = numbers_with_double_zero;

        numbers_without_zero = prev_without_zero * (base - 1) + 
                              prev_with_single_zero * (base - 1);
        
        numbers_with_single_zero = prev_without_zero;
        
        numbers_with_double_zero = prev_with_double_zero * base + 
                                  prev_with_single_zero;
    }

    return numbers_without_zero + numbers_with_single_zero;
}
