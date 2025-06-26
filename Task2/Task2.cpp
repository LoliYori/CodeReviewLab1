//Черепашка.На квадратной доске расставлены целые неотрицательные числа, каждое из которых 
//не превосходит 100. Черепашка, находящаяся в правом верхнем углу, мечтает попасть в левый 
//нижний.При этом она может переползать только в клетку слева или снизу и хочет, чтобы сумма 
//всех чисел, оказавшихся у нее на пути, была бы максимальной.Определить эту сумму.Ввод и вывод
//организовать при помощи текстовых файлов.Формат входных данных : в первой строке входного 
//файла записано число N - размер доски(1 < N < 80).Далее следует N строк, каждая из которых 
//содержит N целых чисел, представляющих доску.В выходной файл нужно вывести единственное число :
//максимальную сумму.



#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib> 
#include <ctime>   
#include <Windows.h>

using namespace std;

//чтение с файла
vector<vector<int>> readfile(const string& filename, int& line, int& cols) {
    ifstream input(filename);
    if (!input.is_open()) {
        cout << "Ошибка при открытии файла, не моя проблема" << endl;
        exit(1);
    }
    input >> line >> cols;
    vector<vector<int>> board(line, vector<int>(cols)); //собирает доску
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < cols; j++) {
            input >> board[i][j];
        }
    }
    input.close();
    return board;
}

// вывод с клавиатуры
vector<vector<int>> readkey(int& line, int& cols) {
    cout << "Введите сколько будет строк и столбцов в поле для черепашки: ";
    cin >> line >> cols;
    vector<vector<int>> board(line, vector<int>(cols));
    cout << "Введите элементы поля (по строкам и через пробел):" << endl;
    for (int i = 0; i < line; i++) {// собирает доску
        for (int j = 0; j < cols; j++) {
            cin >> board[i][j];
        }
    }
    return board;
}

// random заполнения доски
vector<vector<int>> random(int& line, int& cols) {
    cout << "Введите сколько будет строк и столбцов в поле для черепашки: ";
    cin >> line >> cols;
    vector<vector<int>> board(line, vector<int>(cols));
    srand(static_cast<unsigned int>(time(0))); //  генератор случайных чисел
    for (int i = 0; i < line; ++i) { //заполнеине поля чудес
        for (int j = 0; j < cols; ++j) {
            board[i][j] = rand() % 101; // число от 0 до 100
        }
    }
    return board;
}

// макс сумм
int MaxSum(const vector<vector<int>>& board, int line, int cols) {
    vector<vector<int>> dp(line, vector<int>(cols, 0));

    dp[0][cols - 1] = board[0][cols - 1];//нач точка, правый верхний угол

    for (int j = cols - 2; j >= 0; j--) {//первая строка, влево
        dp[0][j] = dp[0][j + 1] + board[0][j];
    }

    for (int i = 1; i < line; i++) {// первый столбец, вниз
        dp[i][cols - 1] = dp[i - 1][cols - 1] + board[i][cols - 1];
    }

    for (int i = 1; i < line; i++) {// остальная таблица
        for (int j = cols - 2; j >= 0; j--) {
            dp[i][j] = board[i][j] + max(dp[i - 1][j], dp[i][j + 1]);
        }
    }

    return dp[line - 1][0];//макс сумм, левый нижний угол
}

int main() {
    int choice;
    SetConsoleCP(1251); SetConsoleOutputCP(1251);

    cout << "Выберите способ ввода данных, только 1:" << endl;
    cout << "1. Прочитать из файла" << endl;
    cout << "2. Ввести с клавиатуры" << endl;
    cout << "3. Заполнить random числами" << endl;

    cout << "Какой choise вы делаете? : ";
    cin >> choice;

    int line, cols;
    vector<vector<int>> board;

    switch (choice) {
    case 1: {
        string filename = "file.txt";
        
        board = readfile(filename, line, cols);
        break;
    }
    case 2:
        board = readkey(line, cols);
        break;
    case 3:
        board = random(line, cols);
        break;
    default:
        cout << "Упс, попробуйте еще раз!" << endl;
        return 1;
    }

    
    cout << "ПОЛЕ ЧУДЕС:" << endl;
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < cols; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

  
    int maxSum = MaxSum(board, line, cols);

    cout << "Turtle собрала максимальную сумму: " << maxSum << endl;

    ofstream output("vivod.txt");

    output << maxSum;

    output.close();

    cout << "Результат записан в файл vivod.txt но также показан выше" << endl;

    return 0;
}
