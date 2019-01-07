//
// Created by prance on 27.12.18.
//

#ifndef OK_SOLUTION_HPP
#define OK_SOLUTION_HPP

#include "Machine.hpp"
#include "Instance.hpp"

class Solution {
private:
    Machine machine1 = Machine(0), machine2 = Machine(1);
    Instance *instance;
    std::uniform_int_distribution<unsigned> booleanDist = std::uniform_int_distribution<unsigned>(0, 1);
    void calculate();

public:
    Solution();

    explicit Solution(Instance &instance);
    Solution(const Solution& solution1, const Solution &solution2);
    Solution(const Solution& solution);

    unsigned getScore() const;
    void mutate();

    bool operator<(const Solution &rhs) const;


};


#endif //OK_SOLUTION_HPP
