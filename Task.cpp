//
// Created by prance on 04.12.18.
//

#include <stdexcept>
#include "Task.hpp"

Operation *Task::m1() {
    if (!op1->getMachine()) return op1;
    return op2;
}

Operation *Task::m2() {
    if (op1->getMachine()) return op1;
    return op2;
}

unsigned int Task::getReady_time() const {
    return ready_time;
}

Operation *Task::getOp1() const {
    return op1;
}

void Task::setOp1(Operation *op1) {
    Task::op1 = op1;
}

void Task::setOp2(Operation *op2) {
    Task::op2 = op2;
}

Operation *Task::getOp2() const {
    return op2;
}

void Task::setReady_time(unsigned int ready_time) {
    Task::ready_time = ready_time;
}

Operation *Task::other(Operation * op) {
    if(op == op1) return op2;
    if(op == op2) return op1;
    throw std::runtime_error("operation calling for other is not part of a task");
}
