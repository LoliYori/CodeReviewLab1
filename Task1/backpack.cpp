/**
 * @file backpack.cpp
 * @brief ���������� ������� ��� ������� ������ � �������
 */

#include "backpack.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

 // FIXME: �������� ��������� ������� ��� ������������� const ������
bool SortWeight(const Artifact& a, const Artifact& b) {
    return a.weight < b.weight;
}

// FIXME: ��� ������ �������� �� main � ��������� �������
void SolveBackpackProblem(const std::string& filename) {
    // FIXME: ������������ f1 � inputFile
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "�� ������� ������� ���� " << filename << std::endl;
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

    // FIXME: ����������� std::sort � ����� ��������� ������� ���������
    std::sort(artifacts.begin(), artifacts.end(), SortWeight);

    // FIXME: ������������� ���������� ��� ������ ����������
    int currentSumWeight = 0;
    int currentSumVolume = 0;
    int bestSumWeight = 0;
    int bestSumVolume = 0;
    int startIndex = 0;  // ���� k

    while (startIndex < numArtifacts) {
        currentSumWeight = 0;
        currentSumVolume = 0;

        for (int j = startIndex; j < numArtifacts; ++j) {
            if (artifacts[j].weight + currentSumWeight <= maxWeight) {
                currentSumWeight += artifacts[j].weight;
                currentSumVolume += artifacts[j].volume;

                // FIXME: �������� ������� ��� ������ ������� ������
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

    // FIXME: ����������� std::endl ������ "\n" ��� �������� �����
    std::cout << "������������ ��� ���������� = " << bestSumWeight << std::endl
        << "����� ������ ���������� = " << bestSumVolume << std::endl;
}