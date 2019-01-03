//
// Created by prance on 04.12.18.
//

#ifndef OK_OPERATION_HPP
#define OK_OPERATION_HPP


#include "Employ.hpp"
#include "Task.hpp"
#include "Exceptions.hpp"

class Task;

class Operation : public Employ {
private:
    unsigned penalty = 0;
    bool machine;
    bool number;
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
    Operation(unsigned int start_time, unsigned int duration, unsigned int penalty, bool machine, bool number,
                  Task *task);

    bool getMachine() const;

    int getEnd();

    void setStart_time(unsigned int start_time) override;

    unsigned int getPenalty() const;

    bool isMachine() const;

    bool isNumber() const;

    Task *getTask() const;
};


#endif //OK_OPERATION_HPP
