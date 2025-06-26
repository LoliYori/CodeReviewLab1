/**
 * @file turtle_path.h
 * @brief Заголовочный файл для задачи о черепашке
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

// FIXME: Добавлена константа максимального значения клетки
// FIXME: Добавлена константа минимального размера доски
// FIXME: Добавлена константа максимального размера доски
const int MAX_CELL_VALUE = 100;  
const int MIN_BOARD_SIZE = 2;    
const int MAX_BOARD_SIZE = 80;    

// FIXME: Изменены сигнатуры функций для возврата статуса ошибки
bool ReadBoardFromFile(const std::string& filename, int& size, std::vector<std::vector<int>>& board);
bool ReadBoardFromInput(int& size, std::vector<std::vector<int>>& board);
bool GenerateRandomBoard(int& size, std::vector<std::vector<int>>& board);
bool CalculateMaxPathSum(const std::vector<std::vector<int>>& board, int size, int& result);

#endif // TURTLE_PATH_H