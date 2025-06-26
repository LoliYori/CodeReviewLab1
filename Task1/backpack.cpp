/**
 * @file backpack.cpp
 * @brief Реализация функций для решения задачи о рюкзаке
 */

#include "backpack.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

 // FIXME: Изменена сигнатура функции для использования const ссылок
bool SortWeight(const Artifact& a, const Artifact& b) {
    return a.weight < b.weight;
}

// FIXME: Вся логика вынесена из main в отдельную функцию
void SolveBackpackProblem(const std::string& filename) {
    // FIXME: Переименован f1 в inputFile
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл " << filename << std::endl;
        return;
    }

    int numArtifacts, maxWeight;
    inputFile >> numArtifacts >> maxWeight;

    std::vector<Artifact> artifacts(numArtifacts);

    for (int i = 0; i < numArtifacts; ++i) {
        inputFile >> artifacts[i].weight;
    }
    for (int i = 0; i < numArtifacts; ++i) {
        inputFile >> artifacts[i].volume;
    }

    // FIXME: Использован std::sort с явным указанием функции сравнения
    std::sort(artifacts.begin(), artifacts.end(), SortWeight);

    // FIXME: Переименованы переменные для лучшей читаемости
    int currentSumWeight = 0;
    int currentSumVolume = 0;
    int bestSumWeight = 0;
    int bestSumVolume = 0;
    int startIndex = 0;  // Было k

    while (startIndex < numArtifacts) {
        currentSumWeight = 0;
        currentSumVolume = 0;

        for (int j = startIndex; j < numArtifacts; ++j) {
            if (artifacts[j].weight + currentSumWeight <= maxWeight) {
                currentSumWeight += artifacts[j].weight;
                currentSumVolume += artifacts[j].volume;

                // FIXME: Улучшено условие для выбора лучшего набора
                if (currentSumWeight > bestSumWeight ||
                    (currentSumWeight == bestSumWeight && j - startIndex + 1 > bestSumVolume)) {
                    bestSumWeight = currentSumWeight;
                    bestSumVolume = currentSumVolume;
                }
            }
        }

        if (bestSumWeight == maxWeight) {
            break;
        }
        ++startIndex;
    }

    // FIXME: Использован std::endl вместо "\n" для переноса строк
    std::cout << "Максимальный вес артефактов = " << bestSumWeight << std::endl
        << "Объем взятых артефактов = " << bestSumVolume << std::endl;
}