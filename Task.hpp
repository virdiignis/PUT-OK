//
// Created by prance on 04.12.18.
//

#ifndef OK_TASK_HPP
#define OK_TASK_HPP


#include "Operation.hpp"
class Operation;

class Task {
private:
    Operation *op1 = nullptr, *op2 = nullptr;
    unsigned ready_time = 0;
    unsigned number;

public:
    Task(unsigned int number);

    unsigned int getNumber() const;

    unsigned int getReadyTime() const;

    void setReadyTime(unsigned int ready_time);

    Operation *getOp1() const;

    Operation *getOp2() const;

    Operation *m1();

    Operation *m2();

    void setOp1(Operation *op1);

    void setOp2(Operation *op2);

    Operation* other(Operation*);
};


#endif //OK_TASK_HPP
