//
// Created by prance on 04.12.18.
//

#ifndef OK_TASK_HPP
#define OK_TASK_HPP


#include "Operation.hpp"

class Task {
public:
    Operation *op1 = nullptr, *op2 = nullptr;
    unsigned ready_time=0;
};


#endif //OK_TASK_HPP
