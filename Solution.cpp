//
// Created by prance on 27.12.18.
//

#include "Solution.hpp"

Solution::Solution(const Instance &instance) {
    //TODO get operations from instance tasks into random constraint order in machines.
    machine1 = instance.getMachine1();
    machine2 = instance.getMachine2();
    unsigned i=0;
    for (auto task: instance.getTasks()){
        machine1[i] = task->m1();
        machine2[i++] = task->m2();
    }
    std::uniform_int_distribution<unsigned > operationsRange = std::uniform_int_distribution<unsigned>(0, instance.getTasks().size());
    for(i=0; i < randomnessDistribution(generator); i++) {
        auto n1 = operationsRange(generator);
        auto n2 = operationsRange(generator);
        auto p = machine1[n1];
        machine1[n1] = machine1[n2];
        machine1[n2] = p;

        n1 = operationsRange(generator);
        n2 = operationsRange(generator);
        p = machine2[n1];
        machine2[n1] = machine2[n2];
        machine2[n2] = p;

        machine1.calculate();
        machine2.calculate();

    }


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
