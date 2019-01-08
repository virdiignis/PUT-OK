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
public:
    explicit SolutionsPool(Instance &);

    void createSolutions(unsigned);

    void mutate();

    void ranking();

    void randomizedRanking();

    void trimEnd();

};


#endif //OK_SOLUTIONSPOOL_HPP
