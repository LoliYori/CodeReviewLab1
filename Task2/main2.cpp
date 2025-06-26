/**
 * @file main.cpp
 * @brief Главный файл программы для задачи о черепашке
 */

#include "turtle_path.h"
// FIXME: убран WindowH

int main() {
    try {
        std::cout << "Выберите способ ввода:\n"
            << "1. Загрузить из файла\n"
            << "2. Ввести вручную\n"
            << "3. Сгенерировать случайную доску\n"
            << "Ваш выбор: ";

        int choice = 0;
        if (!(std::cin >> choice)) {  // FIXME: Добавлена проверка ввода
            std::cerr << "Ошибка: Некорректный ввод выбора" << std::endl;
            return 1;
        }

        int board_size = 0;
        std::vector<std::vector<int>> board;

        switch (choice) {
        case 1:
            board = ReadBoardFromFile("input.txt", board_size);
            break;
        case 2:
            board = ReadBoardFromInput(board_size);
            break;
        case 3:
            board = GenerateRandomBoard(board_size);
            break;
        default:
            std::cerr << "Ошибка: Неверный выбор" << std::endl;
            return 1;
        }

        if (board.empty()) {  // FIXME: Добавлена проверка вывода
            std::cerr << "Ошибка: Не удалось создать доску" << std::endl;
            return 1;
        }

        std::cout << "\nИгровая доска:\n";
        // FIXME: исправлены циклы
        for (const auto& row : board) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }

        int max_sum = CalculateMaxPathSum(board, board_size);
        std::cout << "\nМаксимальная сумма пути: " << max_sum << std::endl;

        // Запись результатов в файл
        std::ofstream output("output.txt");
        // FIXME: добавлена проверка
        if (!output.is_open()) {
            std::cerr << "Ошибка: Не удалось создать файл для записи результатов" << std::endl;
            return 1;
        }

        output << "Игровая доска:\n";
        for (const auto& row : board) {
            for (int val : row) {
                output << val << " ";
            }
            output << "\n";
        }

        output << "\nМаксимальная сумма пути: " << max_sum << std::endl;
        output.close();

        std::cout << "\nРезультаты сохранены в файл output.txt" << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Произошла ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}