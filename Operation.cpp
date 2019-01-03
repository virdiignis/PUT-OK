//
// Created by prance on 04.12.18.
//
#include "Operation.hpp"

Operation::Operation(unsigned int start_time, unsigned int duration, unsigned int penalty, bool machine, bool number,
                     Task *task) : Employ(start_time, duration), penalty(penalty), machine(machine), task(task),
                                   number(number) {}

bool Operation::getMachine() const {
    return machine;
}

int Operation::getEnd() {
    return start_time + duration + penalty;
}

void Operation::setStart_time(unsigned int start_time) {
    if (!number && start_time < task->getReady_time()) throw NotReadyException();
    if (number && start_time < task->other(this)->getEnd()) throw SecondBeforeFirstException();
    Employ::setStart_time(start_time);
}

unsigned int Operation::getPenalty() const {
    return penalty;
}

bool Operation::isMachine() const {
    return machine;
}

bool Operation::isNumber() const {
    return number;
}

Task *Operation::getTask() const {
    return task;
}
