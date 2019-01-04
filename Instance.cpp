#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc32-c"
//
// Created by prance on 04.12.18.
//

#include <algorithm>
#include <fstream>
#include "Instance.hpp"

Instance::Instance() {
//    generator.seed(static_cast<unsigned long>(time(nullptr)));
    generateTasks();
    sortTasks();
    generateMaitenances();
}

Task *Instance::generateTask() {
    auto t = new Task;
    auto machine_swap = static_cast<bool>(machineDist(generator));
    t->setOp1(new Operation(0, durationDist(generator), 0, machine_swap, 0, t));
    t->setOp2(new Operation(0, durationDist(generator), 0, !machine_swap, 1, t));
    t->setReady_time(ready_timeDist(generator));
    return t;
}

void Instance::generateTasks() {
    for (int i = 0; i < TASKS_NO; ++i) tasks[i] = generateTask();
}

void Instance::sortTasks() {
    std::sort(tasks.begin(), tasks.end(), [](Task *a, Task *b) { return a->getReady_time() < b->getReady_time(); });
}

void Instance::generateMaitenances() {
    unsigned sum = 0;
    for (auto &t: tasks) sum += t->getOp1()->getDuration();
    std::uniform_int_distribution<unsigned> maitenance_start = std::uniform_int_distribution<unsigned>(
            MIN_MAITENANCE_START, sum);
    std::uniform_int_distribution<unsigned> maitenance_duration = std::uniform_int_distribution<unsigned>(
            MIN_MAITENANCE_DURATION, MAX_MAITENANCE_DURATION);

    for (int i = 0; i < MAITENANCES_NO; ++i) {
        machine1.add_maitenance(new Maitenance(maitenance_start(generator), maitenance_duration(generator)));
    }


}

void Instance::toFile(const int number, const std::string filename) {
    std::ofstream ofstream(filename);
    ofstream << "****" << number << "****\n";
    ofstream << TASKS_NO << "\n";
    for (auto t: tasks)
        ofstream << t->getOp1()->getDuration() << ";" << t->getOp2()->getDuration() << ";" << t->getOp1()->getMachine()
                 << ";" << t->getOp2()->getMachine() << ";" << t->getReady_time() << "\n";
    int i = 0;
    for (auto m: machine1.getMaitenances())
        ofstream << i++ << ";0;" << m->getDuration() << ";" << m->getStart_time() << "\n";
    ofstream.close();
}

const Machine &Instance::getMachine1() const {
    return machine1;
}

const Machine &Instance::getMachine2() const {
    return machine2;
}

const std::array<Task *, 50> &Instance::getTasks() const {
    return tasks;
}


#pragma clang diagnostic pop