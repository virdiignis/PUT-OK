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
    std::uniform_int_distribution<unsigned> durationDist = std::uniform_int_distribution<unsigned>(MIN_OP_DURATION,MAX_OP_DURATION);
    std::uniform_int_distribution<unsigned > machineDist = std::uniform_int_distribution<unsigned>(0, 1);
    std::uniform_int_distribution<unsigned> readyTimeDist = std::uniform_int_distribution<unsigned>(0,
                                                                                                    (MIN_OP_DURATION +
                                                                                                     MAX_OP_DURATION) *
                                                                                                    TASKS_NO / 4);
    unsigned number = static_cast<unsigned int>(rand());
    void generateTasks();
    Task * generateTask(unsigned);
    void sortTasks();
    void generateMaitenances();

public:
    std::default_random_engine generator;

    Instance();

    void toFile();

    unsigned int getNumber() const;

    const Machine &getMachine1() const;

    const Machine &getMachine2() const;

    const std::array<Task *, TASKS_NO> &getTasks() const;
};


#endif //OK_INSTANCE_HPP
