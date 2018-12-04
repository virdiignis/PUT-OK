//
// Created by prance on 04.12.18.
//

#ifndef OK_OPERATION_HPP
#define OK_OPERATION_HPP


#include "Employ.hpp"
#include "Task.hpp"

class Operation : public Employ {
private:
    unsigned penalty = 0;
    bool machine;
    Task *task;
public:
    /***
     *
     * @param start_time
     * @param duration
     * @param penalty
     * @param machine
     * @param task
     */
    Operation(unsigned int start_time, unsigned int duration, unsigned int penalty, bool machine,
                  Task *task);
};


#endif //OK_OPERATION_HPP
