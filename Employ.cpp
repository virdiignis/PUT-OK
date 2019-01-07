//
// Created by prance on 27.12.18.
//

#include "Employ.hpp"

void Employ::setStartTime(unsigned int start_time) {
    Employ::start_time = start_time;
}

unsigned int Employ::getStartTime() const {
    return start_time;
}

unsigned int Employ::getDuration() const {
    return duration;
}

Employ::Employ(unsigned int start_time, unsigned int duration) : start_time(start_time), duration(duration) {}

unsigned Employ::getEnd() const {
    return start_time + duration;
}


