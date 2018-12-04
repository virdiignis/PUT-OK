//
// Created by prance on 04.12.18.
//

#ifndef OK_INSTANCE_HPP
#define OK_INSTANCE_HPP


#include <random>
#include "Machine.hpp"

class Instance {
    Machine machine1, machine2;
    std::array<Task*, TASKS_NO> tasks;
    std::default_random_engine generator;
    std::uniform_int_distribution<unsigned> duration = std::uniform_int_distribution<unsigned>(MIN_OP_DURATION,MAX_OP_DURATION);
    std::uniform_int_distribution<bool> machine = std::uniform_int_distribution<bool>();
    std::uniform_int_distribution<unsigned> ready_time = std::uniform_int_distribution<unsigned>(0, (MIN_OP_DURATION + MAX_OP_DURATION)/2 * TASKS_NO);

    void generateTasks();
    Task * generateTask();
    void generateMachines();
    void sortTasks();
    void generateMaitenances();

};


#endif //OK_INSTANCE_HPP
