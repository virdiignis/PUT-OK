//
// Created by prance on 04.12.18.
//
#include <cmath>
#include "Operation.hpp"
#include "Maitenance.hpp"

Operation::Operation(unsigned int start_time, unsigned int duration, unsigned int penalty, bool machine, bool number,
                     Task *task) : Employ(start_time, duration), penalty(penalty), machine(machine), task(task),
                                   number(number) {}

bool Operation::getMachine() const {
    return machine;
}

unsigned int Operation::getEnd() {
    return start_time + duration + penalty;
}

void Operation::setStartTime(unsigned int start_time) {
    if (!number && start_time < task->getReadyTime()) throw NotReadyException();
    if (number && start_time < task->other(this)->getEnd()) throw SecondBeforeFirstException();
    Employ::setStartTime(start_time);
}

unsigned int Operation::getPenalty() const {
    return penalty;
}

bool Operation::isMachine() const {
    return machine;
}

bool Operation::isSecond() const {
    return number;
}

Task *Operation::getTask() const {
    return task;
}

unsigned Operation::getReadyTime() {
    if(!isSecond()) return task->getReadyTime();
    return 0;
}

void Operation::disturbed(Maitenance *& m) {
    if (!penalty)
        penalty = static_cast<unsigned int>(m->getDuration() + std::ceil((float)duration / 2.0));
    else
        penalty += m->getDuration();
}

void Operation::resetPenalty() {
    Operation::penalty = 0;
}

unsigned Operation::getTaskNo() {
    return task->getNumber();
}
