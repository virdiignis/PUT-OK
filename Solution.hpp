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

public:
    explicit Solution(const Instance& instance);
    Solution(const Solution& solution1, const Solution &solution2);
    Solution(const Solution& solution);



};


#endif //OK_SOLUTION_HPP
