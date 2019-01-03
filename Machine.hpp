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

    void add_maitenance(Maitenance*);
    Operation* operator[](int x);
    int score();

    const std::vector<Maitenance *> &getMaitenances() const;

private:
    std::array<Operation*, TASKS_NO> operations;
    std::vector<Maitenance*> maitenances;

};


#endif //OK_MACHINE_HPP
