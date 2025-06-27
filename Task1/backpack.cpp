/**
 * @file backpack.cpp
 * @brief Ðåàëèçàöèÿ ôóíêöèé äëÿ ðåøåíèÿ çàäà÷è î ðþêçàêå
 */

#include "backpack.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

 // FIXME: Код вынесен в функции и назван по код-стайлу
bool SortWeight(const Artifact& a, const Artifact& b) {
    return a.weight < b.weight;
}

// FIXME: Код вынесен в функции и назван по код-стайлу
void SolveBackpackProblem(const std::string& filename) {
    // FIXME: Переменная была названа плохо, теперь inputFile
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Íå óäàëîñü îòêðûòü ôàéë " << filename << std::endl;
        return;
    }

    // FIXME: Переназваны переменные
    int numArtifacts = 0;
    int maxWeight = 0;
    inputFile >> numArtifacts >> maxWeight;

    std::vector<Artifact> artifacts(numArtifacts);

    // FIXME: Изменено на префиксную 
    for (int i = 0; i < numArtifacts; ++i) {
        inputFile >> artifacts[i].weight;
    }
    // FIXME: Изменено на префиксную
    for (int i = 0; i < numArtifacts; ++i) {
        inputFile >> artifacts[i].volume;
    }
    std::sort(artifacts.begin(), artifacts.end(), SortWeight);

    // FIXME: Изменены названия переменных на правильные
    int currentSumWeight = 0;
    int currentSumVolume = 0;
    int bestSumWeight = 0;
    int bestSumVolume = 0;
    int startIndex = 0; 

    while (startIndex < numArtifacts) {
        // FIXME: Изменены названия переменных на правильные
        currentSumWeight = 0;
        currentSumVolume = 0;

        for (int j = startIndex; j < numArtifacts; ++j) {
            if (artifacts[j].weight + currentSumWeight <= maxWeight) {
                currentSumWeight += artifacts[j].weight;
                currentSumVolume += artifacts[j].volume;

                // FIXME: Добавлена проверка
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
       // FIXME: Изменено на префиксную
        ++startIndex;
    }

    // FIXME: Èñïîëüçîâàí std::endl âìåñòî "\n" äëÿ ïåðåíîñà ñòðîê
    std::cout << "Ìàêñèìàëüíûé âåñ àðòåôàêòîâ = " << bestSumWeight << std::endl
        << "Îáúåì âçÿòûõ àðòåôàêòîâ = " << bestSumVolume << std::endl;
}
