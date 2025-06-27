/**
 * @file backpack.h
 * @brief Çàãîëîâî÷íûé ôàéë äëÿ ðåøåíèÿ çàäà÷è î ðþêçàêå
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
  * @brief Ñòðóêòóðà, îïèñûâàþùàÿ àðòåôàêò
  */
struct Artifact {
    int weight;
    int volume;  
};

/**
 * @brief Ñðàâíèâàåò àðòåôàêòû ïî âåñó äëÿ ñîðòèðîâêè
 * @param a Ïåðâûé àðòåôàêò
 * @param b Âòîðîé àðòåôàêò
 * @return true, åñëè âåñ a ìåíüøå âåñà b
 */
bool SortWeight(const Artifact& a, const Artifact& b);

/**
 * @brief Ðåøàåò çàäà÷ó î ðþêçàêå
 * @param filename Èìÿ âõîäíîãî ôàéëà ñ äàííûìè
 */
void SolveBackpackProblem(const std::string& filename);

#endif  // BACKPACK_H
