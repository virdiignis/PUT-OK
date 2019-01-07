//
// Created by prance on 07.01.19.
//

#include <algorithm>
#include "SolutionsPool.hpp"

void SolutionsPool::mutate() {
    for (const auto &s: *this) {
        Solution n = Solution(s);
        n.mutate();
        this->push_back(n);
    }
}

void SolutionsPool::ranking() {
    std::sort(this->begin(), this->end());
}

void SolutionsPool::trimEnd() {
    this->resize(GENERATION_SIZE);
}

SolutionsPool::SolutionsPool() : vector(2 * GENERATION_SIZE) {
    generator.seed(static_cast<unsigned long>(time(nullptr)));
}

void SolutionsPool::randomizedRanking() {
    ranking();
//    std::default_random_engine generator;

    std::shuffle(this->begin() + (GENERATION_SIZE / 2), this->end() - GENERATION_SIZE / 4, generator);
}
