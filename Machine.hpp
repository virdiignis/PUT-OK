//
// Created by prance on 04.12.18.
//

#ifndef OK_MACHINE_HPP
#define OK_MACHINE_HPP


#include <array>
#include <vector>
#include "tuning.hpp"
#include "Operation.hpp"
#include "Maintenance.hpp"

class Machine {
    bool number = false;
    std::array<Operation *, TASKS_NO> operations = {nullptr};
    std::vector<Maintenance *> maintenances;
public:
    explicit Machine(bool number);

    void addMaitenance(Maintenance *m);

    Operation *&operator[](unsigned int x);

    unsigned int score() const;

    const std::vector<Maintenance *> &getMaitenances() const;

    unsigned getSize();

    void sortMaitenances();

    unsigned getIndex(Operation *);

    void setMaitenances(const std::vector<Maintenance *> &maitenances);

    unsigned getEnd();


};


#endif //OK_MACHINE_HPP
