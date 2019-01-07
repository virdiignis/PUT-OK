//
// Created by prance on 07.01.19.
//

#ifndef OK_SOLUTIONSPOOL_HPP
#define OK_SOLUTIONSPOOL_HPP


#include <vector>
#include "Solution.hpp"

class SolutionsPool : std::vector<Solution> {
private:
    std::default_random_engine generator;
public:
    SolutionsPool();

    void mutate();

    void ranking();

    void randomizedRanking();

    void trimEnd();

};


#endif //OK_SOLUTIONSPOOL_HPP
