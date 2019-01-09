//
// Created by prance on 04.12.18.
//

#ifndef OK_MACHINE_HPP
#define OK_MACHINE_HPP


#include <array>
#include <vector>
#include "tuning.hpp"
#include "Operation.hpp"
#include "Maitenance.hpp"

class Machine {
    bool number = false;
public:
    explicit Machine(bool number);

    void addMaitenance(Maitenance *m);

    Operation *&operator[](unsigned int x);

    unsigned int score() const;

    const std::vector<Maitenance *> &getMaitenances() const;

    unsigned getSize();

    void sortMaitenances();

    unsigned getIndex(Operation *);

    void setMaitenances(const std::vector<Maitenance *> &maitenances);

private:
    std::array<Operation *, TASKS_NO> operations = {nullptr};
    std::vector<Maitenance *> maitenances;

};


#endif //OK_MACHINE_HPP
