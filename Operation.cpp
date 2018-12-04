//
// Created by prance on 04.12.18.
//

#include "Operation.hpp"

Operation::Operation(unsigned int start_time, unsigned int duration, unsigned int penalty, bool machine,
                     Task *task) : Employ(start_time, duration), penalty(penalty), machine(machine), task(task) {}
