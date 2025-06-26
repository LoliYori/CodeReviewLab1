/* 
 * Основной файл программы для подсчёта K-ичных чисел без двух подряд идущих нулей
 */
#include "k_numbers_calculator.h"
#include <iostream>

int main() {
    std::cout << "Среди чисел в системе счисления с основанием K (2<=K<=10) определить " << std::endl;
    std::cout << "сколько имеется чисел из N(1<N<20, K + N<26) разрядов таких," << std::endl;
    std::cout << "что в их записи не содержится два и более подряд идущих нулей." << std::endl;
    std::cout << "Вам необходимо ввести два числа - число разрядов и систему счисления." << std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    
    // FIXME: Изменены названия перменных
    int digits_count;
    int base;
    std::cout << "Введите число N - число разрядов в числе: ";
    std::cin >> digits_count;
    std::cout << "Введите число K - систему счисления: ";
    std::cin >> base;

    // FIXME: Добавлена проверка на входные данные
    if (!ValidateInput(base, digits_count)) {
        std::cout << "Некорректные входные данные!" << std::endl;
        return 1;
    }

    double result = CalculateValidNumbersCount(base, digits_count);
    std::cout << "Количество чисел, в которых нет два и более подряд идущих нулей: " << result << std::endl;
    
    return 0;
}
