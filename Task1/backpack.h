/**
 * @file backpack.h
 * @brief ������������ ���� ��� ������� ������ � �������
 */

#ifndef BACKPACK_H
#define BACKPACK_H

#include "backpack.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

 /**
  * @struct Artifact
  * @brief ���������, ����������� ��������
  */
struct Artifact {
    int weight;  ///< ��� ��������� � ��
    int volume;  ///< ����� ��������� � ���.��
};

/**
 * @brief ���������� ��������� �� ���� ��� ����������
 * @param a ������ ��������
 * @param b ������ ��������
 * @return true, ���� ��� a ������ ���� b
 */
bool SortWeight(const Artifact& a, const Artifact& b);

/**
 * @brief ������ ������ � �������
 * @param filename ��� �������� ����� � �������
 */
void SolveBackpackProblem(const std::string& filename);

#endif  // BACKPACK_H