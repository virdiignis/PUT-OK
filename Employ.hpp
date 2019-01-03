//
// Created by prance on 04.12.18.
//

#ifndef OK_EMPLOY_HPP
#define OK_EMPLOY_HPP


class Employ {
public:
    Employ(unsigned int start_time, unsigned int duration);

    virtual void setStart_time(unsigned int start_time);

    unsigned int getStart_time() const;

    unsigned int getDuration() const;

protected:
    unsigned start_time, duration;
};

#endif //OK_EMPLOY_HPP
