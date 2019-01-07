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
    std::default_random_engine generator;
    std::uniform_int_distribution<unsigned> booleanDist = std::uniform_int_distribution<unsigned>(0, 1);
    void calculate();

public:
    explicit Solution(const Instance& instance);
    Solution(const Solution& solution1, const Solution &solution2);
    Solution(const Solution& solution);
    unsigned getScore();
    void mutate();



};


#endif //OK_SOLUTION_HPP
