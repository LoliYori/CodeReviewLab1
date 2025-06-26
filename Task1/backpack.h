/**
 * @file backpack.h
 * @brief Заголовочный файл для решения задачи о рюкзаке
 */

#ifndef BACKPACK_H
#define BACKPACK_H

#include "backpack.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

 /**
  * @struct Artifact
  * @brief Структура, описывающая артефакт
  */
struct Artifact {
    int weight;  ///< Вес артефакта в кг
    int volume;  ///< Объем артефакта в куб.см
};

/**
 * @brief Сравнивает артефакты по весу для сортировки
 * @param a Первый артефакт
 * @param b Второй артефакт
 * @return true, если вес a меньше веса b
 */
bool SortWeight(const Artifact& a, const Artifact& b);

/**
 * @brief Решает задачу о рюкзаке
 * @param filename Имя входного файла с данными
 */
void SolveBackpackProblem(const std::string& filename);

#endif  // BACKPACK_H