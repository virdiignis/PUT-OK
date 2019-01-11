//
// Created by prance on 04.12.18.
//

#ifndef OK_OPERATION_HPP
#define OK_OPERATION_HPP


#include "Employ.hpp"
#include "Task.hpp"
#include "Exceptions.hpp"
#include "Maintenance.hpp"

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
     * @param number
     * @param task
     */
    Operation(unsigned int start_time, unsigned int duration, unsigned int penalty, bool machine, bool number,
                  Task *task);
unsigned getTaskNo();


    bool getMachine() const;

    unsigned int getEnd();

    void setStartTime(unsigned int start_time) override;

    unsigned int getPenalty() const;

    bool isMachine() const;

    bool isSecond() const;

    Task *getTask() const;

    unsigned getReadyTime();

    void disturbed(Maintenance *&);

    void resetPenalty();
};


#endif //OK_OPERATION_HPP
