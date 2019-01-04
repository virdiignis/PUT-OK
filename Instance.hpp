//
// Created by prance on 04.12.18.
//

#ifndef OK_INSTANCE_HPP
#define OK_INSTANCE_HPP


#include <random>
#include "Machine.hpp"

class Instance {
    Machine machine1 = Machine(0), machine2 = Machine(1);
    std::array<Task*, TASKS_NO> tasks;
    std::default_random_engine generator;
    std::uniform_int_distribution<unsigned> durationDist = std::uniform_int_distribution<unsigned>(MIN_OP_DURATION,MAX_OP_DURATION);
    std::uniform_int_distribution<unsigned > machineDist = std::uniform_int_distribution<unsigned>(0, 1);
    std::uniform_int_distribution<unsigned> ready_timeDist = std::uniform_int_distribution<unsigned>(0, (MIN_OP_DURATION + MAX_OP_DURATION)/2 * TASKS_NO);

    void generateTasks();
    Task * generateTask();
    void sortTasks();
    void generateMaitenances();

public:
    Instance();
    void toFile(int, std::string);

    const Machine &getMachine1() const;

    const Machine &getMachine2() const;

    const std::array<Task *, 50> &getTasks() const;
};


#endif //OK_INSTANCE_HPP
