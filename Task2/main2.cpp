/**
 * @file main.cpp
 * @brief ������� ���� ��������� ��� ������ � ���������
 */

#include "turtle_path.h"
// FIXME: ����� WindowH

int main() {
    try {
        std::cout << "�������� ������ �����:\n"
            << "1. ��������� �� �����\n"
            << "2. ������ �������\n"
            << "3. ������������� ��������� �����\n"
            << "��� �����: ";

        int choice = 0;
        if (!(std::cin >> choice)) {  // FIXME: ��������� �������� �����
            std::cerr << "������: ������������ ���� ������" << std::endl;
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
            std::cerr << "������: �������� �����" << std::endl;
            return 1;
        }

        if (board.empty()) {  // FIXME: ��������� �������� ������
            std::cerr << "������: �� ������� ������� �����" << std::endl;
            return 1;
        }

        std::cout << "\n������� �����:\n";
        // FIXME: ���������� �����
        for (const auto& row : board) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }

        int max_sum = CalculateMaxPathSum(board, board_size);
        std::cout << "\n������������ ����� ����: " << max_sum << std::endl;

        // ������ ����������� � ����
        std::ofstream output("output.txt");
        // FIXME: ��������� ��������
        if (!output.is_open()) {
            std::cerr << "������: �� ������� ������� ���� ��� ������ �����������" << std::endl;
            return 1;
        }

        output << "������� �����:\n";
        for (const auto& row : board) {
            for (int val : row) {
                output << val << " ";
            }
            output << "\n";
        }

        output << "\n������������ ����� ����: " << max_sum << std::endl;
        output.close();

        std::cout << "\n���������� ��������� � ���� output.txt" << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "��������� ������: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}