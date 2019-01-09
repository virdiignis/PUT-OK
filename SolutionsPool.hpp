//
// Created by prance on 07.01.19.
//

#ifndef OK_SOLUTIONSPOOL_HPP
#define OK_SOLUTIONSPOOL_HPP


#include <vector>
#include "Solution.hpp"

class SolutionsPool : public std::vector<Solution> {
private:
    Instance *instance;
    unsigned generationSize = 0;
public:
    explicit SolutionsPool(Instance &, unsigned);

    void createSolutions(unsigned);

    void mutate();

    void ranking();

    void randomizedRanking(unsigned, unsigned);

    void randomize();

    void trimEnd();

    void breed();

};


#endif //OK_SOLUTIONSPOOL_HPP
