/**
 * @file main.cpp
 * @brief Ãëàâíûé ôàéë ïðîãðàììû äëÿ çàäà÷è î ÷åðåïàøêå
 */

#include "turtle_path.h"
// FIXME: Убран windows.h

int main() {
    try {
        std::cout << "Âûáåðèòå ñïîñîá ââîäà:\n"
            << "1. Çàãðóçèòü èç ôàéëà\n"
            << "2. Ââåñòè âðó÷íóþ\n"
            << "3. Ñãåíåðèðîâàòü ñëó÷àéíóþ äîñêó\n"
            << "Âàø âûáîð: ";

        // FIXME: Инициализирована переменная
        int choice = 0;
         // FIXME: Добавлена проверка
        if (!(std::cin >> choice)) {
            std::cerr << "Îøèáêà: Íåêîððåêòíûé ââîä âûáîðà" << std::endl;
            return 1;
        }

        // FIXME: Инициализирована переменная
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
            std::cerr << "Îøèáêà: Íåâåðíûé âûáîð" << std::endl;
            return 1;
        }

        // FIXME: Добавлена проверка
        if (board.empty()) {  
            std::cerr << "Îøèáêà: Íå óäàëîñü ñîçäàòü äîñêó" << std::endl;
            return 1;
        }

        std::cout << "\nÈãðîâàÿ äîñêà:\n";
        for (const auto& row : board) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }

        int max_sum = CalculateMaxPathSum(board, board_size);
        std::cout << "\nÌàêñèìàëüíàÿ ñóììà ïóòè: " << max_sum << std::endl;
        
        std::ofstream output("output.txt");
        // FIXME: Добавлена проверка на вывод
        if (!output.is_open()) {
            std::cerr << "Îøèáêà: Íå óäàëîñü ñîçäàòü ôàéë äëÿ çàïèñè ðåçóëüòàòîâ" << std::endl;
            return 1;
        }

        output << "Èãðîâàÿ äîñêà:\n";
        for (const auto& row : board) {
            for (int val : row) {
                output << val << " ";
            }
            output << "\n";
        }

        output << "\nÌàêñèìàëüíàÿ ñóììà ïóòè: " << max_sum << std::endl;
        output.close();

        std::cout << "\nÐåçóëüòàòû ñîõðàíåíû â ôàéë output.txt" << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Ïðîèçîøëà îøèáêà: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
