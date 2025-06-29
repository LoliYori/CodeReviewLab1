/**
 * @file backpack.h
 * @brief Заголовочный файл для решения задачи о рюкзаке
 * @details Задача о выборе оптимального набора артефактов с учетом ограничений на вес и объем
 */

#ifndef BACKPACK_H
#define BACKPACK_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

/**
 * @struct Artifact
 * @brief Структура, описывающая артефакт
 * @details Содержит информацию о весе и объеме артефакта
 */
struct Artifact {
    int weight; 
    int volume; 
};

/**
 * @brief Сравнивает артефакты по весу для сортировки
 * @param a Первый артефакт для сравнения
 * @param b Второй артефакт для сравнения
 * @return true, если вес артефакта a меньше веса артефакта b
 */
bool SortWeight(const Artifact& a, const Artifact& b);

/**
 * @brief Решает задачу о рюкзаке
 * @param filename Имя входного файла с данными об артефактах
 * @details Формат файла: первая строка - максимальный вес и объем,
 *          последующие строки - вес и объем каждого артефакта
 */
void SolveBackpackProblem(const std::string& filename);

#endif  // BACKPACK_H
