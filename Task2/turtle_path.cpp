/**
 * @file turtle_path.cpp
 * @brief Реализация функций для задачи о черепашке
 */

#include "turtle_path.h"

 // FIXME: Улучшена обработка ошибок при чтении файла
 // FIXME: Изменено название функции
std::vector<std::vector<int>> ReadBoardFromFile(const std::string& filename, int& size) {
    std::ifstream input(filename);
    if (!input.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл" << std::endl;
        return false;
    }


    input >> size;
 // FIXME: Добавлена проверка
    if (size <= 1 || size >= MAX_BOARD_SIZE) {
        throw std::out_of_range("Invalid board size");
    }

    std::vector<std::vector<int>> board(size, std::vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            input >> board[i][j];
 // FIXME: Добавлена проверка
            if (board[i][j] < 0 || board[i][j] > MAX_CELL_VALUE) {
                throw std::out_of_range("Cell value out of bounds");
            }
        }
    }
    return board;
}

// FIXME: Улучшен ввод с клавиатуры с проверками
std::vector<std::vector<int>> ReadBoardFromInput(int& size) {
    std::cout << "Enter board size: ";
    std::cin >> size;

// FIXME: Добавлена проверка
    if (size <= 1 || size >= MAX_BOARD_SIZE) {
        throw std::out_of_range("Invalid board size");
    }

    std::vector<std::vector<int>> board(size, std::vector<int>(size));
    std::cout << "Enter board values row by row:" << std::endl;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cin >> board[i][j];
// FIXME: Добавлена проверка
            if (board[i][j] < 0 || board[i][j] > MAX_CELL_VALUE) {
                throw std::out_of_range("Cell value out of bounds");
            }
        }
    }
    return board;
}

// FIXME: Добавлена проверка размера доски
std::vector<std::vector<int>> GenerateRandomBoard(int& size) {
    std::cout << "Enter board size: ";
    std::cin >> size;

// FIXME: Добавлена проверка
    if (size <= 1 || size >= MAX_BOARD_SIZE) {
        throw std::out_of_range("Invalid board size");
    }

    std::vector<std::vector<int>> board(size, std::vector<int>(size));
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            board[i][j] = std::rand() % (MAX_CELL_VALUE + 1);
        }
    } 
    return board;
}

// FIXME: Оптимизирован алгоритм расчета пути
int CalculateMaxPathSum(const std::vector<std::vector<int>>& board, int size) {
    std::vector<std::vector<int>> dp(size, std::vector<int>(size, 0));
    dp[0][size - 1] = board[0][size - 1];


    for (int j = size - 2; j >= 0; --j) {
        dp[0][j] = dp[0][j + 1] + board[0][j];
    }

    for (int i = 1; i < size; ++i) {
        dp[i][size - 1] = dp[i - 1][size - 1] + board[i][size - 1];
    }

    
    for (int i = 1; i < size; ++i) {
        for (int j = size - 2; j >= 0; --j) {
            dp[i][j] = board[i][j] + std::max(dp[i - 1][j], dp[i][j + 1]);
        }
    }

    return dp[size - 1][0];
}