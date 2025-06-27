/**
 * @file turtle_path.cpp
 * @brief Реализация функций для задачи о черепашке
 */

#include "turtle_path.h"

// FIXME: Вынесено в функции 
// FIXME: Изменены названия функций на правильные
std::vector<std::vector<int>> ReadBoardFromFile(const std::string& filename, int& size) {
    std::ifstream input(filename);
    if (!input.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл" << std::endl;
        return {};
    }

    input >> size;
    // FIXME: Добавлена проверка 
    if (size <= 1 || size >= MAX_BOARD_SIZE) {
        std::cerr << "Ошибка: Недопустимый размер доски" << std::endl;
        return {};
    }

    std::vector<std::vector<int>> board(size, std::vector<int>(size));
 // FIXME: Изменено на префиксную
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            input >> board[i][j];
            // FIXME: Добавлена проверка 
            if (board[i][j] < 0 || board[i][j] > MAX_CELL_VALUE) {
                std::cerr << "Ошибка: Значение клетки вне допустимого диапазона" << std::endl;
                return {};
            }
        }
    }
    return board;
}

// FIXME: Изменено название функции
std::vector<std::vector<int>> ReadBoardFromInput(int& size) {
    std::cout << "Введите размер доски: ";
    std::cin >> size;

    // FIXME: Добавлена проверка 
    if (size <= 1 || size >= MAX_BOARD_SIZE) {
        std::cerr << "Ошибка: Недопустимый размер доски" << std::endl;
        return {};
    }

    std::vector<std::vector<int>> board(size, std::vector<int>(size));
    std::cout << "Введите значения доски построчно:" << std::endl;

    // FIXME: Изменено на префиксную
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cin >> board[i][j];
            // FIXME: Добавлена проверка 
            if (board[i][j] < 0 || board[i][j] > MAX_CELL_VALUE) {
                std::cerr << "Ошибка: Значение клетки вне допустимого диапазона" << std::endl;
                return {};
            }
        }
    }
    return board;
}

// FIXME: Изменено название функции
std::vector<std::vector<int>> GenerateRandomBoard(int& size) {
    std::cout << "Введите размер доски: ";
    std::cin >> size;

    // FIXME: Добавлена проверка
    if (size <= 1 || size >= MAX_BOARD_SIZE) {
        std::cerr << "Ошибка: Недопустимый размер доски" << std::endl;
        return {};
    }

    std::vector<std::vector<int>> board(size, std::vector<int>(size));
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // FIXME: Изменено на префиксную
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            board[i][j] = std::rand() % (MAX_CELL_VALUE + 1);
        }
    } 
    return board;
}

// FIXME: Изменено название функции
int CalculateMaxPathSum(const std::vector<std::vector<int>>& board, int size) {
    std::vector<std::vector<int>> dp(size, std::vector<int>(size, 0));
    dp[0][size - 1] = board[0][size - 1];

    // FIXME: Изменено на префиксную
    for (int j = size - 2; j >= 0; --j) {
        dp[0][j] = dp[0][j + 1] + board[0][j];
    }

    // FIXME: Изменено на префиксную
    for (int i = 1; i < size; ++i) {
        dp[i][size - 1] = dp[i - 1][size - 1] + board[i][size - 1];
    }

    // FIXME: Изменено на префиксную
    for (int i = 1; i < size; ++i) {
        for (int j = size - 2; j >= 0; --j) {
            dp[i][j] = board[i][j] + std::max(dp[i - 1][j], dp[i][j + 1]);
        }
    }

    return dp[size - 1][0];
}
