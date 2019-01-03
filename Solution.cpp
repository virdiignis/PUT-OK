//
// Created by prance on 27.12.18.
//

#include "Solution.hpp"

Solution::Solution(const Instance &instance) {
    //TODO get operations from instance tasks into random constraint order in machines.

    //generate random solution for the instance
}

Solution::Solution(const Solution &solution1, const Solution &solution2) {
    //generate solution from two parents
}

Solution::Solution(const Solution &solution) {
    //copy solution
    machine1 = solution.machine1;
    machine2 = solution.machine2;
}
