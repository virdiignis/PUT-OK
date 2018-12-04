//
// Created by prance on 04.12.18.
//

#ifndef OK_EMPLOY_HPP
#define OK_EMPLOY_HPP


class Employ {
public:
    Employ(unsigned int start_time, unsigned int duration);

protected:
    unsigned start_time, duration;
};

Employ::Employ(unsigned int start_time, unsigned int duration) : start_time(start_time), duration(duration) {}


#endif //OK_EMPLOY_HPP
