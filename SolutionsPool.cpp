//
// Created by prance on 07.01.19.
//

#include <algorithm>
#include <chrono>
#include "SolutionsPool.hpp"

void SolutionsPool::mutate() {
    const unsigned long l = size();
    for (unsigned i = 0; i < l; i++) {
        Solution n((*this)[i]);
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

SolutionsPool::SolutionsPool(Instance &instance) : instance(&instance) {
    this->reserve(GENERATION_SIZE * 2);
}

void SolutionsPool::randomizedRanking() {
    ranking();
//    std::default_random_engine generator;

    std::shuffle(this->begin() + (GENERATION_SIZE / 4), this->end() - GENERATION_SIZE / 4, instance->generator);
}

void SolutionsPool::createSolutions(unsigned i) {
    for (int j = 0; j < i; ++j) {
        this->emplace_back(instance);
    }
}

void SolutionsPool::breed() {
    const unsigned long s = size();
    for (int i = 0; i < s; i += 2) {
        this->push_back(Solution((*this)[i], (*this)[i + 1]));
    }
}

void SolutionsPool::randomize() {
    std::shuffle(this->begin(), this->end(), instance->generator);
}
