//
// Created by prance on 27.12.18.
//

#include "Employ.hpp"

void Employ::setStart_time(unsigned int start_time) {
    Employ::start_time = start_time;
}

unsigned int Employ::getStart_time() const {
    return start_time;
}

unsigned int Employ::getDuration() const {
    return duration;
}

Employ::Employ(unsigned int start_time, unsigned int duration) : start_time(start_time), duration(duration) {}


