/**
 * @file turtle_path.h
 * @brief Заголовочный файл для задачи о черепашке
 * @details Задача о нахождении максимального пути черепашки в квадратном поле
 */

#ifndef TURTLE_PATH_H
#define TURTLE_PATH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

const int MAX_CELL_VALUE = 100;  
const int MIN_BOARD_SIZE = 2;  
const int MAX_BOARD_SIZE = 80;

/**
 * @brief Чтение игрового поля из файла
 * @param filename Имя файла для чтения
 * @param[out] size Размер поля (N x N)
 * @param[out] board Матрица игрового поля
 * @return true при успешном чтении, false при ошибке
 */
bool ReadBoardFromFile(const std::string& filename, 
                      int& size, 
                      std::vector<std::vector<int>>& board);

/**
 * @brief Чтение игрового поля с консоли
 * @param[out] size Размер поля (N x N)
 * @param[out] board Матрица игрового поля
 * @return true при успешном чтении, false при ошибке
 */
bool ReadBoardFromInput(int& size, 
                       std::vector<std::vector<int>>& board);

/**
 * @brief Генерация случайного игрового поля
 * @param[out] size Размер поля (N x N)
 * @param[out] board Матрица игрового поля
 * @return true при успешной генерации, false при ошибке
 */
bool GenerateRandomBoard(int& size, 
                        std::vector<std::vector<int>>& board);

/**
 * @brief Вычисление максимальной суммы пути
 * @param board Игровое поле
 * @param size Размер поля
 * @param[out] result Максимальная сумма пути
 * @return true при успешном вычислении, false при ошибке
 */
bool CalculateMaxPathSum(const std::vector<std::vector<int>>& board, 
                         int size, 
                         int& result);

#endif // TURTLE_PATH_H
