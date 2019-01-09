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
    this->resize(generationSize);
}

SolutionsPool::SolutionsPool(Instance &instance, unsigned gs) : instance(&instance), generationSize(gs) {
    this->reserve(gs * 4);
    createSolutions(gs);
}

void SolutionsPool::randomizedRanking(unsigned int untouchedTop, unsigned int untouchedEnd) {
    ranking();
//    std::default_random_engine generator;

    std::shuffle(this->begin() + untouchedTop, this->end() - untouchedEnd, instance->generator);
}

void SolutionsPool::createSolutions(unsigned i) {
    for (unsigned j = 0; j < i; ++j) {
        this->emplace_back(instance);
    }
}

void SolutionsPool::breed() {
    const unsigned long s = size();
    for (unsigned i = 0; i < s; i += 2) {
        this->push_back(Solution((*this)[i], (*this)[i + 1]));
    }
}

void SolutionsPool::randomize() {
    std::shuffle(this->begin(), this->end(), instance->generator);
}
