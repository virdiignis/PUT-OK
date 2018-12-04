//
// Created by prance on 04.12.18.
//

#include <algorithm>
#include "Instance.hpp"

void Instance::generateMachines() {
    generateTasks();
    sortTasks();



}

Task * Instance::generateTask() {
    auto t = new Task;
    bool swap = machine(generator);
    t->op1 = new Operation(0, duration(generator), 0, swap, t);
    t->op2 = new Operation(0, duration(generator), 0, !swap, t);
    t->ready_time = ready_time(generator);
    return t;
}

void Instance::generateTasks() {
    for (int i = 0; i < TASKS_NO; ++i) tasks[i] = generateTask();
}

void Instance::sortTasks() {
    std::sort(tasks.begin(), tasks.end(), [](Task* a, Task* b){return a->ready_time < b->ready_time;});
}

void Instance::generateMaitenances() {
    unsigned sum=0;
    for(auto& t: tasks) sum += t->op1->duration;
    std::uniform_int_distribution<unsigned> maitenance_start = std::uniform_int_distribution<unsigned>(MIN_MAITENANCE_START, sum);
    std::uniform_int_distribution<unsigned> maitenance_duration = std::uniform_int_distribution<unsigned>(MIN_MAITENANCE_DURATION, MAX_MAITENANCE_DURATION);


    

}

